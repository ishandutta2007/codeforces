import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;
import java.io.BufferedInputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(new BufferedInputStream(inputStream));
        PrintWriter out = new PrintWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    static final long mod = 1000 * 1000 * 1000 + 7;

    int[] a;
    long[] dep;
    long[] toParent;

    int getRoot(int x) {
        if (a[x] == x) return a[x];
        int p = a[x];
        a[x] = getRoot(p);
        dep[x] = (dep[x] + dep[p]) % mod;
        return a[x];
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        long res = 0;
        int n = in.nextInt();
        a = new int[n];
        dep = new long[n];
        toParent = new long[n];
        for (int i = 0; i < n; ++i) {
            a[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            int k = in.nextInt();
            a[i] = i;
            dep[i] = 0;
            for (int j = 0; j < k; ++j) {
                int v = in.nextInt();
                --v;
                long x = in.nextLong();
                int r = getRoot(v);
                long y = (x + dep[v]) % mod;
                res += y;
                res %= mod;
                a[r] = i;
                dep[r] = y;
            }
        }
        res %= mod;
        res += mod;
        res %= mod;
        out.println(res);
    }
}