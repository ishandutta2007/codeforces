import java.io.*;
import java.util.*;

public class B {
    public static class Solver {
        final int maxn = 105;
        int b[] = new int[maxn];
        int mt[] = new int[maxn];
        ArrayList<Integer> e[] = new ArrayList[maxn];
        int n, m;
        int wa[] = new int[maxn];
        int wb[] = new int[maxn];

        void scan() throws IOException {
            n = nextInt();
            for (int i = 0; i < n; ++i) {
                wa[i] = nextInt();
            }
            m = nextInt();
            for (int i = 0; i < m; ++i) {
                wb[i] = nextInt();
            }
        }

        boolean kuhn(int v) {
            if (b[v] != 0)  {
                return false;
            }
            b[v] = 1;
            for (int to : e[v]) {
                if (mt[to] == -1 || kuhn(mt[to])) {
                    mt[to] = v;
                    return true;
                }
            }
            return false;
        }

        void solve() {
            for (int i = 0; i < n; ++i) {
                e[i] = new ArrayList<Integer>();
                for (int j = 0; j < m; ++j) {
                    if (wb[j] >= wa[i] - 1 && wb[j] <= wa[i] + 1) {
                        e[i].add(j);
                    }
                }
            }

            for (int i = 0; i < m; ++i) {
                mt[i] = -1;
            }
            int res = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    b[j] = 0;
                }
                if (kuhn(i)) {
                    ++res;
                }
            }
            out.print(res + "\n");
        }

        public void main() throws IOException {
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