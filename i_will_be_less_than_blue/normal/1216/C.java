import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.awt.geom.Rectangle2D;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.function.Function;
import java.awt.geom.RectangularShape;
import java.io.Writer;
import java.io.OutputStreamWriter;
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
        CWhiteSheet solver = new CWhiteSheet();
        solver.solve(1, in, out);
        out.close();
    }

    static class CWhiteSheet {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
//        Rectangle w = Rectangle.of(in.i(), in.i(), in.i(), in.i());
//        Rectangle f = Rectangle.of(in.i(), in.i(), in.i(), in.i());
//        Rectangle s = Rectangle.of(in.i(), in.i(), in.i(), in.i());
//
//        Rectangle wf = Rectangle.intersection(w, f);
//        Rectangle ws = Rectangle.intersection(w, s);
//        Rectangle fs = Rectangle.intersection(ws, wf);
//
//        long wa = Rectangle.area(w);
//        long wfa = Rectangle.area(wf);
//        long wsa = Rectangle.area(ws);
//        long fsa = Rectangle.area(fs);
//
//        if (wfa + wsa - fsa >= wa) {
//            out.printLine("NO");
//        } else {
//            out.printLine("YES");
//        }
            int[] a = in.ia(4);
            Rectangle2D w = new Rectangle2D.Double(a[0], a[1], a[2] - a[0], a[3] - a[1]);
            a = in.ia(4);
            Rectangle2D f = new Rectangle2D.Double(a[0], a[1], a[2] - a[0], a[3] - a[1]);
            a = in.ia(4);
            Rectangle2D s = new Rectangle2D.Double(a[0], a[1], a[2] - a[0], a[3] - a[1]);

            Rectangle2D wf = w.createIntersection(f);
            Rectangle2D ws = w.createIntersection(s);
            Rectangle2D fs = wf.createIntersection(ws);


            Function<Rectangle2D, Double> area = e -> Math.max(0, e.getHeight()) * Math.max(0, e.getWidth());
            Double wa = area.apply(w);
            Double wfa = area.apply(wf);
            Double wfs = area.apply(ws);
            Double fsa = area.apply(fs);

            if (wfa + wfs - fsa >= wa) {
                out.printLine("NO");
            } else {
                out.printLine("YES");
            }
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
}