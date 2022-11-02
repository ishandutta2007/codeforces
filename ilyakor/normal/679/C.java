import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final int[] dx = new int[]{-1, 1, 0, 0};
        static final int[] dy = new int[]{0, 0, -1, 1};
        int n;
        int k;
        boolean[][] a;
        int[][] sum;
        int[][] sum2;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            n = in.nextInt();
            k = in.nextInt();
//        n = 500;
//        k = 150;
//        Random random = new Random(0xdead);

            TaskC.PersistentDSU dsu = new TaskC.PersistentDSU((n + 2) * (n + 2) + 1, n);
            int N = n + 2;
            int S = N * N;
            a = new boolean[n][n];
            for (int i = 0; i < n; ++i) {
                String s = in.nextToken();
                for (int j = 0; j < n; ++j)
                    a[i][j] = s.charAt(j) == '.';
//            for (int j = 0; j < n; ++j)
//                a[i][j] = random.nextInt(2) == 1;
            }

            sum = new int[n][n];
            for (int i = 0; i < n; ++i) {
                int cur = 0;
                for (int j = 0; j < n; ++j) {
                    cur += a[i][j] ? 0 : 1;
                    if (j - k >= 0) {
                        cur -= a[i][j - k] ? 0 : 1;
                    }
                    if (j - k + 1 >= 0) {
                        sum[i][j - k + 1] = cur;
                    }
                }
            }
            sum2 = new int[n][n];
            for (int i = 0; i < n; ++i) {
                int cur = 0;
                for (int j = 0; j < n; ++j) {
                    cur += sum[j][i];
                    if (j - k >= 0) {
                        cur -= sum[j - k][i];
                    }
                    if (j - k + 1 >= 0) {
                        sum2[j - k + 1][i] = cur;
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!a[i][j]) continue;
                    dsu.cnt[(i + 1) * N + j + 1] = 1;
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (!a[i][j]) continue;
                    for (int dir = 0; dir < 4; ++dir) {
                        int x = i + dx[dir];
                        int y = j + dy[dir];
                        if (x >= 0 && x < n && y >= 0 && y < n && a[x][y])
                            dsu.unite((i + 1) * N + j + 1, (x + 1) * N + y + 1);
                    }
                }
            }
            int res = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int r = dsu.root((i + 1) * N + j + 1);
                    res = Math.max(res, dsu.cnt[r]);
                }
            }

            int[] del = new int[(n + 2) * (n + 2) + 1];

            for (int i = 0; i <= n - k; ++i) {
                int internal = 0;
                for (int x = 0; x < k; ++x) {
                    for (int y = 0; y < k; ++y) {
                        int t = (i + x + 1) * N + (y + 1);
                        if (dsu.p[t] != t) continue;
                        int mx = dsu.mx[t];
                        int Mx = dsu.Mx[t];
                        int my = dsu.my[t];
                        int My = dsu.My[t];
                        if (mx >= i && Mx <= i + k - 1 && my >= 0 && My <= k - 1)
                            internal += dsu.cnt[t];
                    }
                }
                for (int j = 0; j <= n - k; ++j) {
                    dsu.reset();
                    if (j > 0) for (int x = 0; x < k; ++x) {
                        if (!a[i + x][j - 1]) continue;
                        if (x == 0 || !a[i + x - 1][j - 1])
                            dsu.punite(S, (i + x + 1) * N + j);
                    }
                    if (j + k < n) for (int x = 0; x < k; ++x) {
                        if (!a[i + x][j + k]) continue;
                        if (x == 0 || !a[i + x - 1][j + k])
                            dsu.punite(S, (i + x + 1) * N + j + k + 1);
                    }
                    if (i > 0) for (int x = 0; x < k; ++x) {
                        if (!a[i - 1][j + x]) continue;
                        if (x == 0 || !a[i - 1][j + x - 1])
                            dsu.punite(S, i * N + j + x + 1);
                    }
                    if (i + k < n) for (int x = 0; x < k; ++x) {
                        if (!a[i + k][j + x]) continue;
                        if (x == 0 || !a[i + k][j + x - 1])
                            dsu.punite(S, (i + k + 1) * N + j + x + 1);
                    }
                    int cur = sum2[i][j] + dsu.Cnt[dsu.proot(S)] + internal;
                    if (cur > res) res = cur;

                    int M = dsu.marker;
                    for (int y = 0; y < 2; ++y) {
                        for (int x = 0; x < k; ++x) {
                            if (j + y >= n || !a[i + x][j + y]) continue;
                            int t = (i + x + 1) * N + j + 1 + y;
                            t = dsu.p[t];
                            if (del[t] == M) continue;
                            del[t] = M;
                            int mx = dsu.mx[t];
                            int Mx = dsu.Mx[t];
                            int my = dsu.my[t];
                            int My = dsu.My[t];
                            if (mx >= i && Mx <= i + k - 1 && my >= j && My <= j + k - 1) {
                                if (!(mx >= i && Mx <= i + k - 1 && my >= j + 1 && My <= j + k)) {
                                    internal -= dsu.cnt[t];
                                }
                            }
                        }
                        for (int x = 0; x < k; ++x) {
                            if (j + k - y >= n || j + k - y < 0 || !a[i + x][j + k - y]) continue;
                            int t = (i + x + 1) * N + j + k + 1 - y;
                            t = dsu.p[t];
                            if (del[t] == M) continue;
                            del[t] = M;
                            int mx = dsu.mx[t];
                            int Mx = dsu.Mx[t];
                            int my = dsu.my[t];
                            int My = dsu.My[t];
                            if (!(mx >= i && Mx <= i + k - 1 && my >= j && My <= j + k - 1)) {
                                if ((mx >= i && Mx <= i + k - 1 && my >= j + 1 && My <= j + k)) {
                                    internal += dsu.cnt[t];
                                }
                            }
                        }
                    }
                }
            }
            out.printLine(res);
        }

        static class PersistentDSU {
            int[] p;
            int[] cnt;
            int[] Mx;
            int[] mx;
            int[] My;
            int[] my;
            int[] P;
            int[] Cnt;
            int[] u;
            int marker;
            int n;

            void init() {
                for (int i = 0; i < p.length; i++) {
                    p[i] = i;
                    cnt[i] = 0;
                    mx[i] = i / (n + 2) - 1;
                    my[i] = i % (n + 2) - 1;
                    Mx[i] = i / (n + 2) - 1;
                    My[i] = i % (n + 2) - 1;
                }
            }

            PersistentDSU(int size, int n) {
                this.n = n;
                p = new int[size];
                P = new int[size];
                mx = new int[size];
                Mx = new int[size];
                my = new int[size];
                My = new int[size];
                u = new int[size];
                cnt = new int[size];
                Cnt = new int[size];
                marker = 1;
                init();
            }

            void reset() {
                ++marker;
            }

            int root(int x) {
                if (x == p[x])
                    return x;
                return p[x] = root(p[x]);
            }

            void unite(int a, int b) {
                a = root(a);
                b = root(b);
                if (a == b)
                    return;
                //if (rnd.nextBoolean()) {
                if ((((a * 57 + b * 43) ^ (a * b + 12)) >> 3) % 2 == 0) {
                    p[a] = b;
                    cnt[b] += cnt[a];
                    if (mx[b] > mx[a]) mx[b] = mx[a];
                    if (my[b] > my[a]) my[b] = my[a];
                    if (Mx[b] < Mx[a]) Mx[b] = Mx[a];
                    if (My[b] < My[a]) My[b] = My[a];
                } else {
                    p[b] = a;
                    cnt[a] += cnt[b];
                    if (mx[a] > mx[b]) mx[a] = mx[b];
                    if (my[a] > my[b]) my[a] = my[b];
                    if (Mx[a] < Mx[b]) Mx[a] = Mx[b];
                    if (My[a] < My[b]) My[a] = My[b];
                }
            }

            int proot(int x) {
                if (u[x] != marker) {
                    u[x] = marker;
                    P[x] = p[x];
                    Cnt[x] = cnt[x];
                }
                if (x == P[x]) return x;
                return P[x] = proot(P[x]);
            }

            void punite(int a, int b) {
                a = proot(a);
                b = proot(b);
                if (a == b)
                    return;
                //if (rnd.nextBoolean()) {
                if ((((a * 57 + b * 43) ^ (a * b + 12)) >> 3) % 2 == 0) {
                    P[a] = b;
                    Cnt[b] += Cnt[a];
                } else {
                    P[b] = a;
                    u[b] = marker;
                    Cnt[a] += Cnt[b];
                }
            }

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buffer = new byte[10000];
        private int cur;
        private int count;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public static boolean isSpace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public int read() {
            if (count == -1) {
                throw new InputMismatchException();
            }
            try {
                if (cur >= count) {
                    cur = 0;
                    count = stream.read(buffer);
                    if (count <= 0)
                        return -1;
                }
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            return buffer[cur++];
        }

        public int readSkipSpace() {
            int c;
            do {
                c = read();
            } while (isSpace(c));
            return c;
        }

        public String nextToken() {
            int c = readSkipSpace();
            StringBuilder sb = new StringBuilder();
            while (!isSpace(c)) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
        }

        public int nextInt() {
            int sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
        }

    }
}