import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    public static final double eps = 1E-7;
    ArrayList<PointDouble>[] a;
    double[] sq;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        a = new ArrayList[k];
        sq = new double[k];
        for (int i = 0; i < k; ++i) {
            a[i] = new ArrayList<>();
            a[i].add(new PointDouble(i, 0));
            a[i].add(new PointDouble(i + 1, 0));
        }
        for (int i = 0; i < n; ++i) {
            double res = 0;
            double prev = in.nextDouble();
            for (int j = 0; j < k; ++j) {
                double y = in.nextDouble();
                res += add(j, new PointDouble(j, prev), new PointDouble(j + 1, y));
                prev = y;
            }
            out.printLine(String.format("%.20f", res));
        }
    }

    private double add(int index, PointDouble p1, PointDouble p2) {
        ArrayList<PointDouble> newPoints = new ArrayList<>();
        if (p1.y > a[index].get(0).y - eps) {
            newPoints.add(p1);
        }
        LineDouble l1 = new LineDouble(p1, p2);
        for (int i = 0; i < a[index].size(); ++i) {
            if (a[index].get(i).y > p1.y + (p2.y - p1.y) * (a[index].get(i).x - p1.x) / (p2.x - p1.x) - eps) {
                newPoints.add(a[index].get(i));
            }
            if (i + 1 < a[index].size()) {
                LineDouble l2 = new LineDouble(a[index].get(i), a[index].get(i + 1));
                PointDouble o = l1.intersect(l2);
                if (o != null && a[index].get(i).x - eps < o.x && o.x < a[index].get(i + 1).x + eps) {
                    newPoints.add(o);
                }
            }
        }
        if (p2.y > a[index].get(a[index].size() - 1).y - eps)
            newPoints.add(p2);
        double res = 0;
        ArrayList<PointDouble> newPointsClean = new ArrayList<>();
        newPointsClean.add(newPoints.get(0));
        for (int i = 0; i + 1 < newPoints.size(); ++i) {
            int j = i + 1;
            if (newPoints.get(j).x - newPoints.get(i).x < eps) continue;
            newPointsClean.add(newPoints.get(j));
            res += (newPoints.get(j).x - newPoints.get(i).x) * (newPoints.get(j).y + newPoints.get(i).y);
        }
        res *= 0.5;
        double delta = res - sq[index];
        sq[index] = res;
        a[index] = newPointsClean;
        return delta;
    }
}

class PointDouble {
    public double x;
    public double y;

    public PointDouble(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public PointDouble() {
        x = 0;
        y = 0;
    }

    }

class InputReader {
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

    public double nextDouble() {
        double sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        double res = 0;
        while (!isSpace(c) && c != '.') {
            if (c == 'e' || c == 'E') {
                return res * Math.pow(10, nextInt());
            } else if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10 + c - '0';
            c = read();
        }
        if (c == '.') {
            c = read();
            double m = 1;
            while (!isSpace(c)) {
                if (c == 'e' || c == 'E') {
                    return res * Math.pow(10, nextInt());
                } else if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                m /= 10;
                res += (c - '0') * m;
                c = read();
            }
        }
        res *= sgn;
        return res;
    }

    }

class OutputWriter {
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

class LineDouble {
    public double a, b, c;

    public LineDouble() {
    }

    public LineDouble(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public LineDouble(PointDouble p, PointDouble q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
    }

    public PointDouble intersect(LineDouble l) {
        double d = a * l.b - b * l.a;
        if (Math.abs(d) < 1E-8) {
            return null;
        }
        double dx = -b * l.c + c * l.b;
        double dy = a * l.c - c * l.a;
        return new PointDouble(-dx / d, -dy / d);
    }

    }