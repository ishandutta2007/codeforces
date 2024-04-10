import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
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
        B1SocialNetworkEasyVersion solver = new B1SocialNetworkEasyVersion();
        solver.solve(1, in, out);
        out.close();
    }

    static class B1SocialNetworkEasyVersion {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            int k = in.i();
            int[] a = in.ia(n);
            Map<Integer, Integer> freq = new HashMap<>();
            ArrayDeque<Integer> fifo = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                if (fifo.size() < k) {
                    if (!freq.containsKey(a[i])) {
                        fifo.addFirst(a[i]);
                        freq.put(a[i], 1);
                    }
                } else {
                    if (!freq.containsKey(a[i])) {
                        int removed = fifo.removeLast();
                        freq.put(removed, freq.get(removed) - 1);
                        if (freq.get(removed) == 0) {
                            freq.remove(removed);
                        }
                        fifo.addFirst(a[i]);
                        freq.put(a[i], freq.getOrDefault(a[i], 0) + 1);
                    }
                }
            }
            out.printLine(fifo.size());
            fifo.forEach(e -> out.print(e + " "));

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

        public int[] ia(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = i();
            return a;
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