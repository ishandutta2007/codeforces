import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {

    static int n, m;
    static int cnt[] = new int[1001];

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int u, v;
            u = in.nextInt();
            v = in.nextInt();
            cnt[u]++;
            cnt[v]++;
        }
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                System.out.println(n - 1);
                for (int j = 1; j <= n; j++) if (i != j) System.out.println(i + " " + j);
                break;
            }
        }
    }
}