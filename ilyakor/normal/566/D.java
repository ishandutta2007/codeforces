import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        boolean[] tree;
        int[] comp;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            //int n = 1000;
            //int q = 1000000;

            tree = new boolean[4 * n + 10];
            initTree(0, 0, n - 1);
            comp = new int[n];
            //comp1 = new int[n];
            for (int i = 0; i < n; ++i) {
                comp[i] = i;
                //comp1[i] = i;
            }
            //Random random = new Random(0xdead);
            for (int qi = 0; qi < q; ++qi) {
                int t = in.nextInt();
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                //int t = random.nextInt(3);
                //int x = random.nextInt(n);
                //int y = random.nextInt(n);
                if (x > y && t == 2) {
                    int tmp = x;
                    x = y;
                    y = tmp;
                }
                if (t == 2 && x > y) throw new RuntimeException();
                if (t == 1) {
                    int rx = get(comp, x);
                    int ry = get(comp, y);
                    if (rx != ry) {
                        merge(comp, rx, ry);
                    }
/*
                rx = get(comp1, x);
                ry = get(comp1, y);
                if (rx != ry) {
                    merge(comp1, rx, ry);
                }*/
                } else if (t == 2) {
                    mergeTree(0, 0, n - 1, x, y);
/*
                for (int i = x; i < y; ++i) {
                    int rx = get(comp1, x);
                    int ry = get(comp1, i);
                    if (rx != ry) {
                        merge(comp1, rx, ry);
                    }
                }*/
                } else if (t == 3) {
                    int rx = get(comp, x);
                    int ry = get(comp, y);
                    if (rx == ry) out.println("YES");
                    else out.println("NO");

                /*int rx1 = get(comp1, x);
                int ry1 = get(comp1, y);

                if ((rx1 == ry1) != (rx == ry))
                    throw new RuntimeException("OMG");*/
                }
            }
        }

        private boolean mergeTree(int root, int rl, int rr, int x, int y) {
            if (x > y) return false;
            if (tree[root]) return true;
            int rm = (rl + rr) / 2;
            if (mergeTree(root * 2 + 1, rl, rm, x, Math.min(y, rm)) &
                    mergeTree(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, x), y)) {
                int a = get(comp, rm);
                int b = get(comp, rm + 1);
                if (a != b) merge(comp, a, b);
            }
            if (rl == x && rr == y) {
                tree[root] = true;
            }
            return true;
        }

        private int get(int[] comp, int x) {
            int r = x;
            while (true) {
                int rr = comp[r];
                if (rr == r) break;
                r = rr;
            }
            while (x != r) {
                int rr = comp[x];
                comp[x] = r;
                x = rr;
            }
            return r;
        }

        private void merge(int[] comp, int a, int b) {
            comp[a] = b;
        }

        private void initTree(int root, int rl, int rr) {
            if (rl == rr) {
                tree[root] = true;
                return;
            }
            int rm = (rl + rr) / 2;
            initTree(root * 2 + 1, rl, rm);
            initTree(root * 2 + 2, rm + 1, rr);
            tree[root] = false;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}