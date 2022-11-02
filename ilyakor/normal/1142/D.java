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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
//        ArrayList<Integer> a = new ArrayList<>();
//        for (int i = 1; i < 10; ++i)
//            a.add(i);
//        for (int i = 0; a.size() < 50000; ++i) {
//            int x = a.get(i);
//            int upper = (i + 1) % 11;
//            for (int j = 0; j < upper; ++j)
//                a.add(x * 10 + j);
//        }
//        for (int i = 0; i < a.size(); i++) {
//            int x = a.get(i);
////            if ((i + 1) % 11 == 1)
//            System.err.println((i + 1) % 11 + " " + calc("" + x) + " " + x);
//        }

            char[] s = in.nextToken().toCharArray();
            int n = s.length;
            int[][] next = new int[11][n + 1];
            for (int i = 0; i < 11; ++i)
                next[i][n] = n;
            for (int i = n - 1; i >= 0; --i) {
                for (int j = 0; j < 11; ++j) {
                    int c = s[i] - '0';
                    if (c >= j) {
                        next[j][i] = i;
                        continue;
                    }
                    int nj = (10 + j * (j - 1) / 2 + c) % 11;
                    next[j][i] = next[nj][i + 1];
                }
            }
            long res = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') continue;
                int r = next[s[i] - '0'][i + 1];
                res += r - i;
            }
            out.printLine(res);
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

    }
}