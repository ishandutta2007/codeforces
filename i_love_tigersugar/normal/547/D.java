import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Queue;
import java.io.BufferedReader;
import java.util.LinkedList;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Van Hanh Pham (skyvn97)
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        ArrayList<TaskD.Edge> edges;
        private TaskD.Point[] points;
        private int numPoints;
        private int numNodes;
        private Queue<Integer> curNodes;
        private Queue<Integer>[] curEdges;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            numPoints = in.nextInt();
            points = new TaskD.Point[numPoints];
            for (int i = 0; i < numPoints; i++) points[i] = new TaskD.Point(in);

            ArrayList<Integer> valX = new ArrayList<Integer>();
            ArrayList<Integer> valY = new ArrayList<Integer>();
            for (TaskD.Point p : points) {
                valX.add(p.x);
                valY.add(p.y);
            }
            valX = ArrayUtils.uniqueElements(valX);
            valY = ArrayUtils.uniqueElements(valY);

            numNodes = valX.size() + valY.size();
            int[] degree = new int[numNodes];
            edges = new ArrayList<TaskD.Edge>();
            for (int i = 0; i < numPoints; i++) {
                int idX = Collections.binarySearch(valX, points[i].x);
                int idY = Collections.binarySearch(valY, points[i].y);
                degree[idX]++;
                degree[valX.size() + idY]++;
                edges.add(new TaskD.Edge(idX, valX.size() + idY, false));
            }

            ArrayList<Integer> oddNodes = new ArrayList<Integer>();
            for (int i = 0; i < numNodes; i++) if (degree[i] % 2 != 0) oddNodes.add(i);
            if (oddNodes.size() % 2 != 0) throw new UnknownError();
            for (int i = 0; i < oddNodes.size() / 2; i++) {
                int u = oddNodes.get(2 * i);
                int v = oddNodes.get(2 * i + 1);
                edges.add(new TaskD.Edge(u, v, true));
            }

            curNodes = new LinkedList<Integer>();
            curEdges = new LinkedList[numNodes];
            for (int i = 0; i < numNodes; i++) curEdges[i] = new LinkedList<Integer>();
            for (int i = 0; i < numNodes; i++) curNodes.add(i);
            for (int i = 0; i < edges.size(); i++) {
                TaskD.Edge e = edges.get(i);
                curEdges[e.u].add(i);
                curEdges[e.v].add(i);
            }

            while (true) {
                int s = getNode();
                if (s < 0) break;
                buildCycle(s);
            }

            for (TaskD.Edge e : edges) e.printEdge(out);
            out.println();
        }

        private int getNode() {
            while (!curNodes.isEmpty()) {
                int u = curNodes.peek();
                if (getEdge(u) >= 0) return u;
                curNodes.poll();
            }
            return -1;
        }

        private int getEdge(int u) {
            while (!curEdges[u].isEmpty()) {
                int id = curEdges[u].peek();
                if (!edges.get(id).used) return id;
                curEdges[u].poll();
            }
            return -1;
        }

        private void buildCycle(int s) {
            int u = s;
            while (true) {
                int id = getEdge(u);
                if (id < 0) throw new UnknownError();
                edges.get(id).setDir(u);
                u = edges.get(id).other(u);
                if (u == s) return;
            }
        }

        static class Edge {
            private static final char FORWARD = 'r';
            private static final char BACKWARD = 'b';
            public int u;
            public int v;
            public char dir;
            public boolean used;
            public boolean fake;

            public Edge(int u, int v, boolean fake) {
                this.u = u;
                this.v = v;
                this.fake = fake;
                this.used = false;
                this.dir = '#';
            }

            public int other(int x) {
                if (u != x && v != x) throw new UnknownError();
                return u ^ v ^ x;
            }

            public void setDir(int x) {
                if (u != x && v != x) throw new UnknownError();
                used = true;
                dir = u == x ? FORWARD : BACKWARD;
            }

            public void printEdge(PrintWriter out) {
                if (dir != FORWARD && dir != BACKWARD) throw new UnknownError();
                if (fake) return;
                out.printf("%c", dir);
            }

        }

        static class Point {
            public int x;
            public int y;

            public Point(InputReader in) {
                this.x = in.nextInt();
                this.y = in.nextInt();
            }

        }

    }

    static class ArrayUtils {
        public static <Type extends Comparable<? super Type>> ArrayList<Type> uniqueElements(ArrayList<Type> types) {
            ArrayList<Type> tmp = new ArrayList<Type>();
            for (Type type : types) tmp.add(type);
            Collections.sort(tmp);
            ArrayList<Type> res = new ArrayList<Type>();
            for (Type t : tmp)
                if (res.isEmpty() || !t.equals(res.get(res.size() - 1)))
                    res.add(t);
            return res;
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String nextString() {
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
            return Integer.parseInt(nextString());
        }

    }
}