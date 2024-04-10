import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {
    final int maxn = 3072;
    final int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
    final int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

    int n, m, k;
    Boolean a[][] = new Boolean[maxn][2 * maxn];
    int p[] = new int[2 * maxn * maxn];
    int cnt[] = new int[2 * maxn * maxn];
    ArrayList<Integer> v1 = new ArrayList<Integer>(), v2 = new ArrayList<Integer>();

    int getNum(int x, int y) {
        return x * (2 * m + 2) + y;
    }

    int get(int x) {
        if (p[x] == x) return x;
        return p[x] = get(p[x]);
    }

    int get(int x, int y) {
        return get(getNum(x, y));
    }

    public void union(int u, int v) {
        u = get(u);
        v = get(v);
        if (u == v) return;

        if (cnt[v] > cnt[u]) {
            int o;
            o = v;
            v = u;
            u = o;
        }
        p[v] = u;
        if (cnt[v] == cnt[u]) cnt[u]++;
    }

    public void union(int x1, int y1, int x2, int y2) {
        union(getNum(x1, y1), getNum(x2, y2));
    }

    public void Run() {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        if (m == 1) {
            System.out.print(0);
            return;
        }
        k = in.nextInt();
        for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= 2 * m + 1; j++) {
            a[i][j] = false;
            p[getNum(i, j)] = getNum(i, j);
            cnt[getNum(i, j)] = 1;
        }


        int res = 0;
        for (int it = 0; it < k; it++) {
            int x, y;
            x = in.nextInt();
            y = in.nextInt();

            v1.clear();
            v2.clear();
            for (int i = 0; i < 8; i++) {
                int nx, ny;

                nx = x + dx[i];
                ny = y + dy[i]; if (ny == 0) ny = 2 * m;
                if (a[nx][ny]) v1.add(get(nx, ny));

                nx = x + dx[i];
                ny = y + m + dy[i]; if (ny == 2 * m + 1) ny = 1;
                if (a[nx][ny]) v2.add(get(nx, ny));
            }

            Boolean ok = true;
            for (int i = 0; i < v1.size(); i++) {
                for (int j = 0; j < v2.size(); j++) {
                    if (v1.get(i).equals(v2.get(j))) {
                        ok = false;
                    }
                }
            }

            if (ok) {
                res++;
                for (int i = 0; i < 8; i++) {
                    int nx, ny;

                    nx = x + dx[i];
                    ny = y + dy[i]; if (ny == 0) ny = 2 * m;
                    if (a[nx][ny]) union(x, y, nx, ny);

                    nx = x + dx[i];
                    ny = y + m + dy[i]; if (ny == 2 * m + 1) ny = 1;
                    if (a[nx][ny]) union(x, y + m, nx, ny);
                }
                a[x][y] = true;
                a[x][y + m] = true;
            }
        }
        System.out.println(res);
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}