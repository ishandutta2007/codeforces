import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
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
        BTheNumberOfProducts solver = new BTheNumberOfProducts();
        solver.solve(1, in, out);
        out.close();
    }

    static class BTheNumberOfProducts {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            long[] a = in.la(n);
            List<Integer> odd = new ArrayList<>();
            List<Integer> even = new ArrayList<>();
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] < 0) ++count;
                if (count % 2 == 1) odd.add(i);
                else even.add(i);
            }
            odd.sort(Comparator.naturalOrder());
            even.sort(Comparator.naturalOrder());
            long oddCount = 0;
            boolean checkOdd = true;
            for (int i = 0; i < n; i++) {
                if (checkOdd) {
                    int ind;
                    if (a[i] < 0) {
                        ind = ArrayUtil.lowerBound(odd, i);
                    } else {
                        ind = ArrayUtil.upperBound(odd, i);
                    }
                    if (ind != odd.size()) oddCount += odd.size() - ind;
                } else {
                    int ind;
                    if (a[i] < 0) {
                        ind = ArrayUtil.lowerBound(even, i);
                    } else {
                        ind = ArrayUtil.upperBound(even, i);
                    }
                    if (ind != even.size()) oddCount += even.size() - ind;
                }
                if (a[i] < 0) {
                    checkOdd = !checkOdd;
                }
            }
            long evenCount = 0;
            boolean checkEven = true;
            for (int i = 0; i < n; i++) {
                if (checkEven) {
                    int ind;
                    if (a[i] > 0) {
                        ind = ArrayUtil.lowerBound(even, i);
                    } else {
                        ind = ArrayUtil.upperBound(even, i);
                    }
                    if (ind != even.size()) evenCount += even.size() - ind;
                } else {
                    int ind;
                    if (a[i] > 0) {
                        ind = ArrayUtil.lowerBound(odd, i);
                    } else {
                        ind = ArrayUtil.upperBound(odd, i);
                    }
                    if (ind != odd.size()) evenCount += odd.size() - ind;
                }
                if (a[i] < 0) {
                    checkEven = !checkEven;
                }
            }
            out.printLine(oddCount + " " + evenCount);
        }

    }

    static class ArrayUtil {
        public static <T extends Comparable<T>> int lowerBound(List<T> a, T key) {
            int l = 0;
            int h = a.size();
            while (l < h) {
                int mid = (l + h) >> 1;
                if (key.compareTo(a.get(mid)) <= 0) h = mid;
                else l = mid + 1;
            }
            return l;
        }

        public static <T extends Comparable<T>> int upperBound(List<T> a, T key) {
            int l = 0;
            int h = a.size();
            while (l < h) {
                int mid = (l + h) >> 1;
                if (key.compareTo(a.get(mid)) >= 0) l = mid + 1;
                else h = mid;
            }
            return l;
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

        public long[] la(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) a[i] = l();
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

        public long l() {
            long num = 0;
            int b;
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