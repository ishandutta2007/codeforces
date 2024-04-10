import java.util.*;
import java.io.*;

public class TaskA {
    char[][] data;
    int n;

    final int[] dx = new int[] {1, -1, 0, 0};
    final int[] dy = new int[] {0, 0, 1, -1};

    void put(int x1, int y1, int x2, int y2) {
        boolean[] was = new boolean[26];
        for (int i=0; i < 4; i++) {
            int x = x1 + dx[i], y = y1 + dy[i];
            if (x >=0 && x < 4 && y >= 0 && y < n && data[x][y] >= 'a' && data[x][y] <= 'z')
                was[data[x][y]-'a'] = true;
            x = x2 + dx[i]; y = y2 + dy[i];
            if (x >=0 && x < 4 && y >= 0 && y < n && data[x][y] >= 'a' && data[x][y] <= 'z')
                was[data[x][y]-'a'] = true;
        }
        int x = 0;
        while (was[x]) x++;
        data[x1][y1] = (char)((int)'a'+x);
        data[x2][y2] = (char)((int)'a'+x);
    }

    public void doMain() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        sc.close();

        data = new char[4][n];
        this.n = n;
        for (int i=0; i < 4; i++)
            Arrays.fill(data[i], ' ');

        if (n % 2 == 0) {
            for (int i=0; i < n; i += 2) {
                put(0, i, 0, i+1);
                put(3, i, 3, i+1);
            }
            put(1, 0, 2, 0);
            put(1, n-1, 2, n-1);
            for (int i=1; i < n-1; i += 2) {
                put(1, i, 1, i+1);
                put(2, i, 2, i+1);
            }
        } else {
            for (int i=0; i < n-1; i += 2) {
                put(0, i, 0, i+1);
                put(1, i, 1, i+1);
                put(2, i+1, 2, i+2);
                put(3, i+1, 3, i+2);
            }
            put(0, n-1, 1, n-1);
            put(2, 0, 3, 0);
        }

        for (int i=0; i < 4; i++) System.out.println(new String(data[i]));
    }

    public static void main(String[] args) throws Exception {
        (new TaskA()).doMain();
    }
}