import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Random;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.Collections;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        int n;
        int m;
        int[][] a;
        Random random;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            long seed = 0xdead;
            seed *= new Random().nextInt();
            seed += new Random().nextInt();
            n = in.nextInt();
            m = in.nextInt();
            a = new int[n][m];
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    a[i][j] = in.nextInt();
                    seed = seed * 57L + a[i][j];
                }
            random = new Random(seed);

            DisjointSets dsu = new DisjointSets(n * m);
            int[] edgesX = new int[2 * n * m];
            int[] edgesY = new int[2 * n * m];
            int cntEdges = 0;
            
            ArrayList<Integer> inds = new ArrayList<>();

            for (int i = 0; i < n; ++i) {
                final int[] line = a[i];
                if (inds.size() != m) {
                  inds.clear();
                  for (int j = 0; j < m; ++j)
                      inds.add(j);
                }
                Collections.shuffle(inds, random);
                Collections.sort(inds, new Comparator<Integer>() {

                    public int compare(Integer ind1, Integer ind2) {
                        return Integer.compare(line[ind1], line[ind2]);
                    }
                });

                for (int j = 1; j < inds.size(); ++j) {
                    int ind = inds.get(j);
                    int pind = inds.get(j - 1);
                    if (line[ind] == line[pind]) {
                        dsu.unite(i * m + ind, i * m + pind);
                    } else {
                        edgesX[cntEdges] = i * m + ind;
                        edgesY[cntEdges] = i * m + pind;
                        ++cntEdges;
                    }
                }
            }

            for (int i = 0; i < m; ++i) {
                final int[] line = new int[n];
                for (int j = 0; j < n; ++j)
                    line[j] = a[j][i];
                if (inds.size() != n) {
                  inds.clear();
                  for (int j = 0; j < n; ++j)
                      inds.add(j);
                }
                Collections.shuffle(inds, random);
                Collections.sort(inds, new Comparator<Integer>() {

                    public int compare(Integer ind1, Integer ind2) {
                        return Integer.compare(line[ind1], line[ind2]);
                    }
                });

                for (int j = 1; j < inds.size(); ++j) {
                    int ind = inds.get(j);
                    int pind = inds.get(j - 1);
                    if (line[ind] == line[pind]) {
                        dsu.unite(i + ind * m, i + pind * m);
                    } else {
                        edgesX[cntEdges] = i + ind * m;
                        edgesY[cntEdges] = i + pind * m;
                        ++cntEdges;
                    }
                }
            }
            

            ArrayList<Integer>[] g = new ArrayList[n * m];
            for (int i = 0; i < g.length; ++i) {
                if (dsu.root(i) == i) g[i] = new ArrayList<>(1);
            }
            for (int i = 0; i < cntEdges; ++i) {
                g[dsu.root(edgesX[i])].add(dsu.root(edgesY[i]));
            }
        ArrayList<Integer> topsort = new ArrayList<>(n * m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                topsort.add(i * m + j);
        Collections.shuffle(topsort, random);
        Collections.sort(topsort, new Comparator<Integer>() {
            @Override
            public int compare(Integer p, Integer q) {
                return Integer.compare(a[p / m][p % m], a[q / m][q % m]);
            }
        });
            int[] d = new int[n * m];
            for (int x : topsort) {
                if (dsu.root(x) != x) continue;
                int val = 0;
                for (int y : g[x]) {
                    if (val < d[y]) val = d[y];
                }
                d[x] = val + 1;
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int val = d[dsu.root(i * m + j)];
                    out.print(val + " ");
                }
                out.printLine();
            }
        }

    }

    static class TopologicalSort {
        static void dfs(List<Integer>[] graph, boolean[] used, List<Integer> res, int u) {
            used[u] = true;
            if (graph[u] != null) {
              for (int v : graph[u])
                  if (!used[v])
                      dfs(graph, used, res, v);
            }
            res.add(u);
        }

        public static List<Integer> topologicalSort(List<Integer>[] graph) {
            int n = graph.length;
            boolean[] used = new boolean[n];
            List<Integer> res = new ArrayList<Integer>();
            for (int i = 0; i < n; i++)
                if (!used[i])
                    dfs(graph, used, res, i);
            Collections.reverse(res);
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

    }

    static class DisjointSets {
        int[] p;
        int[] rank;

        public DisjointSets(int size) {
            p = new int[size];
            for (int i = 0; i < size; i++) {
                p[i] = i;
            }
            rank = new int[size];
        }

        public DisjointSets(int[] p, int[] rank) {
            this.p = p;
            this.rank = rank;
        }

        public int root(int x) {
            while (x != p[x])
                x = p[x];
            return x;
        }

        public void unite(int a, int b) {
            a = root(a);
            b = root(b);
            if (a == b)
                return;
            if (rank[a] < rank[b]) {
                p[a] = b;
            } else {
                p[b] = a;
                if (rank[a] == rank[b])
                    ++rank[a];
            }
        }

    }
}