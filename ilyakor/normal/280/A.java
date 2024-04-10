import java.util.List;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.PrintStream;
import java.util.Comparator;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {

    public static final double EPS = 1E-8;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int w = in.nextInt();
        int h = in.nextInt();
        double alpha = in.nextDouble() / 180.0 * Math.PI;
        PointDouble[] a = new PointDouble[4];
        a[0] = new PointDouble(-0.5 * w, -0.5 * h);
        a[1] = new PointDouble(-0.5 * w, +0.5 * h);
        a[2] = new PointDouble(+0.5 * w, +0.5 * h);
        a[3] = new PointDouble(+0.5 * w, -0.5 * h);
        PointDouble[] b = new PointDouble[4];
        for (int i = 0; i < 4; ++i) {
            b[i] = a[i].rotate(alpha);
        }
        ArrayList<PointDouble> pa = new ArrayList<PointDouble>();
        for (int i = 0; i < 4; ++i) {
            PointDouble p1 = a[i];
            PointDouble p2 = a[(i + 1) % 4];
            for (int j = 0; j < 4; ++j) {
                PointDouble q1 = b[j];
                PointDouble q2 = b[(j + 1) % 4];
                LineDouble l1 = new LineDouble(p1, p2);
                LineDouble l2 = new LineDouble(q1, q2);
                PointDouble o = l1.intersect(l2);
                if (o == null) continue;
                if (q1.subtract(o).sclar(q2.subtract(o)) > EPS)
                    continue;
                if (p1.subtract(o).sclar(p2.subtract(o)) > EPS)
                    continue;
                pa.add(o);
            }
        }
        for (PointDouble p : b) {
            if (p.x > -0.5 * w - EPS && p.x < 0.5 * w + EPS && p.y > -0.5 * h - EPS && p.y < 0.5 * h + EPS)
                pa.add(p);
        }
        pa = DoublePolyUtils.convexHull(pa);
        double res = 0.0;
        for (int i = 0; i < pa.size(); ++i) {
            PointDouble p1 = pa.get(i);
            PointDouble p2 = pa.get((i + 1) % pa.size());
            res += p1.cross(p2);
        }
        res = Math.abs(res) * 0.5;
        out.printLine(String.format("%.20f", res));
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

    public double cross(PointDouble p) {
        return x * p.y - y * p.x;
    }

    public double sclar(PointDouble p) {
        return x * p.x + y * p.y;
    }

    public PointDouble subtract(PointDouble p) {
        return new PointDouble(x - p.x, y - p.y);
    }

    public boolean eq(PointDouble p) {
        return Math.abs(x - p.x) < 1E-8 && Math.abs(y - p.y) < 1E-8;
    }

    public PointDouble rotate(double alpha) {
        double _x = x * Math.cos(alpha) - y * Math.sin(alpha);
        double _y = x * Math.sin(alpha) + y * Math.cos(alpha);
        return new PointDouble(_x, _y);
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
        if (Math.abs(d) < 1E-18) {
            return null;
        }
        double dx = -b * l.c + c * l.b;
        double dy = a * l.c - c * l.a;
        return new PointDouble(-dx / d, -dy / d);
    }

    }

class DoublePolyUtils {

    public static final double EPS = 1E-15;

    public static ArrayList<PointDouble> convexHull(ArrayList<PointDouble> p) {
        int n = p.size();
        if (n <= 1)
            return p;
        Collections.sort(p, new Comparator<PointDouble>() {
            @Override
            public int compare(PointDouble o1, PointDouble o2) {
                int sx = (int) Math.signum(o1.x - o2.x);
                return sx != 0 ? sx : (int) Math.signum(o1.y - o2.y);
            }
        });
        PointDouble[] q = new PointDouble[n * 2];
        int cnt = 0;
        for (int i = 0; i < n; q[cnt++] = p.get(i++))
            for (; cnt > 1 && !cw(q[cnt - 2], q[cnt - 1], p.get(i)); --cnt)
                ;
        for (int i = n - 2, t = cnt; i >= 0; q[cnt++] = p.get(i--))
            for (; cnt > t && !cw(q[cnt - 2], q[cnt - 1], p.get(i)); --cnt)
                ;
        ArrayList<PointDouble> res = new ArrayList<PointDouble>();
        int len = cnt - 1 - (q[0].eq(q[1]) ? 1 : 0);
        for (int i = 0; i < len; ++i)
            res.add(q[i]);
        return res;
    }

    static boolean cw(PointDouble a, PointDouble b, PointDouble c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < -EPS;
    }
}