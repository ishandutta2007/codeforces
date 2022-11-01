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
 * @author unknown
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        DDistinctCharactersQueries solver = new DDistinctCharactersQueries();
        solver.solve(1, in, out);
        out.close();
    }

    static class DDistinctCharactersQueries {
        private boolean[][] tree;
        private StringBuilder st;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            st = new StringBuilder(in.next());
            tree = new boolean[4 * st.length()][26];
            buildTree(1, 1, st.length());
            int q = in.i();
            while (q-- > 0) {
                int type = in.i();
                if (type == 2) {
                    // query type
                    int l = in.i();
                    int r = in.i();
                    boolean[] ans = query(1, 1, st.length(), l, r);
                    if (ans == null) out.printLine(0);
                    else {
                        int count = 0;
                        for (int i = 0; i < 26; i++) if (ans[i]) ++count;
                        out.printLine(count);
                    }
                } else {
                    int ind = in.i();
                    char val = in.c();
                    updateTree(1, 1, st.length(), ind, val);
                }
            }
        }

        private void updateTree(int n, int s, int e, int i, char val) {
            if (i < s || i > e) return;
            if (s == e) {
                int oldPos = (st.charAt(i - 1) - 'a');
                st.setCharAt(i - 1, val);
                int newPos = val - 'a';
                tree[n][oldPos] = false;
                tree[n][newPos] = true;
                return;
            }
            int m = (s + e) / 2;
            if (s <= i && i <= m) {
                updateTree(2 * n, s, m, i, val);
            } else {
                updateTree(2 * n + 1, m + 1, e, i, val);
            }
            for (int j = 0; j < 26; j++) {
                tree[n][j] = (tree[2 * n][j] | tree[2 * n + 1][j]);
            }
        }

        private void buildTree(int no, int s, int e) {
            if (s == e) {
                int i = st.charAt(s - 1) - 'a';
                tree[no][i] = true;
            } else {
                int m = (s + e) / 2;
                buildTree(2 * no, s, m);
                buildTree(2 * no + 1, m + 1, e);
                for (int i = 0; i < 26; i++) {
                    tree[no][i] = (tree[2 * no][i] | tree[2 * no + 1][i]);
                }
            }
        }

        private boolean[] query(int n, int s, int e, int l, int r) {
            if (l > e || r < s) return null;
            if (l <= s && e <= r) return tree[n];
            int m = (s + e) / 2;
            boolean[] first = query(2 * n, s, m, l, r);
            boolean[] secon = query(2 * n + 1, m + 1, e, l, r);
            return getResult(first, secon);
        }

        private boolean[] getResult(boolean[] first, boolean[] secon) {
            boolean[] res = new boolean[26];
            if (first != null && secon != null) {
                for (int i = 0; i < 26; i++) {
                    res[i] = (first[i] | secon[i]);
                }
            } else if (first != null) {
                for (int i = 0; i < 26; i++) {
                    res[i] = first[i];
                }
            } else if (secon != null) {
                for (int i = 0; i < 26; i++) {
                    res[i] = secon[i];
                }
            } else {
                return null;
            }
            return res;
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

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static class InputReader {
        private InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0;
        private int ptrbuf = 0;

        public InputReader(InputStream is) {
            this.is = is;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }

        public char c() {
            return (char) skip();
        }

        public String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public int i() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }
}