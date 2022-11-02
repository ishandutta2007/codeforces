import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.util.Scanner;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        static final int maxn = 100;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            ArrayList<Integer> p = new ArrayList<>();
            for (int i = 2; i <= maxn; ++i)
                if (isPrime(i)) p.add(i);

//        for (int n = 2; n <= maxn; ++n) {
//            check(n);
//        }

            int cur = 1;
            InputStream stream = in.getStream();
            Scanner sc = new Scanner(stream);
            for (int x : p) {
                if (cur * x > maxn) break;
                if (cur == 1 && x * x > maxn) break;
                out.printLine(x);
                out.flush();
                String s = sc.next();
                if (s.equals("yes")) {
                    if (cur > 1) {
                        out.printLine("composite");
                        out.flush();
                        return;
                    }
                    cur *= x;
                    if (cur * x <= maxn) {
                        out.printLine(x * x);
                        out.flush();
                        s = sc.next();
                        if (s.equals("yes")) {
                            out.printLine("composite");
                            out.flush();
                            return;
                        }
                    }
                }
            }
            out.printLine("prime");
            out.flush();
            //System.err.println(p.size());
        }

        public static boolean isPrime(long n) {
            if (n <= 1)
                return false;

            for (long i = 2; i * i <= n; i++)
                if (n % i == 0)
                    return false;

            return true;
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

        public void flush() {
            writer.flush();
        }

    }

    static class InputReader {
        private InputStream stream;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public InputStream getStream() {
            return stream;
        }

    }
}