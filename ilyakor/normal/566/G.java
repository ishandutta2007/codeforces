import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            in.nextInt();
            in.nextInt();
            TaskG.Point[] p1 = readPoly(in, n);
            TaskG.Point[] p2 = readPoly(in, m);
            p1 = convexHull(p1);
            p2 = convexHull(p2);
            int ptr = 1;
            TaskG.Point a = p2[ptr];
            TaskG.Point b = p2[ptr + 1];
            for (int i = 1; i < p1.length; ++i) {
                TaskG.Point cur = p1[i];
                while (cur.x * (long) b.y - cur.y * (long) b.x < 0) {
                    ++ptr;
                    a = b;
                    b = p2[ptr + 1];
                }
                if ((cur.x - a.x) * (long) (b.y - cur.y) - (cur.y - a.y) * (long) (b.x - cur.x) >= 0) {
                    out.println("Max");
                    return;
                }
            }
            out.println("Min");
        }

        private TaskG.Point[] convexHull(TaskG.Point[] points) {
            Arrays.sort(points, new Comparator<TaskG.Point>() {

                public int compare(TaskG.Point o1, TaskG.Point o2) {
                    long z = -o1.x * (long) o2.y + o2.x * (long) o1.y;
                    if (z < 0) return -1;
                    if (z > 0) return 1;
                    z = (long) Math.abs(o1.x) + Math.abs(o1.y) - Math.abs(o2.x) - Math.abs(o2.y);
                    if (z < 0) return -1;
                    if (z > 0) return 1;
                    return 0;
                }
            });

            TaskG.Point[] hull = new TaskG.Point[points.length];
            int nhull = 0;
            for (TaskG.Point p : points) {
                hull[nhull++] = p;
                while (nhull >= 3) {
                    TaskG.Point a = hull[nhull - 3];
                    TaskG.Point b = hull[nhull - 2];
                    TaskG.Point c = hull[nhull - 1];
                    if ((b.y - a.y) * (long) (c.x - b.x) - (b.x - a.x) * (long) (c.y - b.y) < 0) break;
                    hull[nhull - 2] = c;
                    --nhull;
                }
            }
            return Arrays.copyOf(hull, nhull);
        }

        private TaskG.Point[] readPoly(InputReader in, int n) {
            TaskG.Point[] pts = new TaskG.Point[n + 3];
            int maxx = 0;
            int maxy = 0;
            for (int i = 0; i < n; ++i) {
                pts[i] = new TaskG.Point();
                pts[i].x = in.nextInt();
                pts[i].y = in.nextInt();
                maxx = Math.max(maxx, pts[i].x);
                maxy = Math.max(maxy, pts[i].y);
            }
            pts[n] = new TaskG.Point();
            pts[n + 1] = new TaskG.Point();
            pts[n + 1].x = maxx;
            pts[n + 2] = new TaskG.Point();
            pts[n + 2].y = maxy;
            return pts;
        }

        static class Point {
            int x;
            int y;

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