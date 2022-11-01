import java.io.*;
import java.util.*;

public class D {
    static class Solver {
        final int maxn = 3010;
        int n, m;
        ArrayList<Integer> e[] = new ArrayList[maxn];
        int d[] = new int[maxn];
        int c[] = new int[maxn];
        int q[] = new int[maxn];

        void scan() throws IOException {
            n = nextInt();
            m = nextInt();
            for (int i = 0; i < n; ++i) {
                e[i] = new ArrayList<Integer>();
            }
            for (int i = 0; i < m; ++i) {
                int u = nextInt(), v = nextInt();
                e[--u].add(--v);
            }
        }

        long solve(int sv) {
            for (int i = 0; i < n; ++i) {
                d[i] = -1;
                c[i] = 0;
            }

            for (int to : e[sv]) {
                for (int r : e[to]) {
                    ++c[r];
                }
            }


            long res = 0;
            for (int v = 0; v < n; ++v) {
                if (v != sv) {
                    res += c[v] * (c[v] - 1) / 2;
                }
            }
            return res;
        }

        void solve() {
            long res = 0;
            for (int i = 0; i < n; ++i) {
                res += solve(i);
            }
            out.println(res);
        }

        void main() throws IOException {
            scan();
            solve();
        }
    }
    public static void main(String[] args) throws IOException {
	    init();

        Solver solver = new Solver();
        solver.main();

        br.close();
        out.close();
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void init() throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;

        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
    }

    static boolean hasNext() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return false;
            }
            st = new StringTokenizer(line);
        }
        return true;
    }

    static String next() throws IOException {
        return hasNext() ? st.nextToken() : null;
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}