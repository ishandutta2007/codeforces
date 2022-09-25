import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {

    final int dx[] = {1, -1, 0, 0};
    final int dy[] = {0, 0, 1, -1};

    int n, m;
    int d[][] = new int[1002][1002];
    String a[] = new String[1002];

    public void bfs(int i, int j) {
        Queue<Integer> q = new ArrayDeque<Integer>();
        q.add((i - 1) * m + j);
        d[i][j] = 0;
        while (!q.isEmpty()) {
            i = (q.peek() - 1) / m + 1;
            j = (q.peek() - 1) % m + 1;
            q.remove();

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (a[nx].charAt(ny) != 'T' && d[nx][ny] > d[i][j] + 1) {
                    d[nx][ny] = d[i][j] + 1;
                    q.add((nx - 1) * m + ny);
                }
            }
        }
    }

    public void Run() {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        in.nextLine();
        for (int i = 0; i <= m + 1; i++) {
            a[0] += 'T';
            a[n + 1] += 'T';
        }
        for (int i = 1; i <= n; i++) {
            a[i] = in.nextLine();
            a[i] = "T" + a[i] + "T";
        }
        int xe = -1, ye = -1, xs = -1, ys = -1;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
            if (a[i].charAt(j) == 'E') {
                xe = i;
                ye = j;
            }
            if (a[i].charAt(j) == 'S') {
                xs = i;
                ys = j;
            }
            d[i][j] = (int)1e9;
        }
        bfs(xe, ye);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i].charAt(j) >= '0' && a[i].charAt(j) <= '9' && d[i][j] <= d[xs][ys]) {
                    res += a[i].charAt(j) - '0';
                }
            }
        }
        System.out.println(res);
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}