import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Collection;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jeel Vaishnav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        EShortestPath solver = new EShortestPath();
        solver.solve(1, in, out);
        out.close();
    }

    static class EShortestPath {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int k = sc.nextInt();

            HashSet<Integer> adj[] = new HashSet[n];
            for (int i = 0; i < n; ++i)
                adj[i] = new HashSet<>();

            for (int i = 0; i < m; ++i) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;

                adj[u].add(v);
                adj[v].add(u);
            }

            HashMap<Integer, HashSet<Integer>> map[] = new HashMap[n];
            for (int i = 0; i < n; ++i)
                map[i] = new HashMap<>();

            for (int i = 0; i < k; ++i) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
                int w = sc.nextInt() - 1;

                if (map[v].get(u) == null)
                    map[v].put(u, new HashSet<>());

                map[v].get(u).add(w);
            }

            Queue<Pair> queue = new LinkedList<>();
            int par[][] = new int[n][n];

            int cans = 0;
            queue.add(new Pair(0, -1, -1));
            int ans = -1, ansPar = -1;

            main:
            while (!queue.isEmpty()) {
                int len = queue.size();

                for (int i = 0; i < len; ++i) {
                    Pair curP = queue.poll();

                    int curInd = curP.ind;
                    int curPar = curP.par;

                    if (curPar != -1)
                        par[curInd][curPar] = curP.prevPar;

                    if (curInd == n - 1) {
                        ans = cans;
                        ansPar = curPar;
                        break main;
                    }

                    if (adj[curInd].size() == 0)
                        continue;

                    if (map[curInd].get(curPar) == null) {
                        for (int j : adj[curInd]) {
                            queue.add(new Pair(j, curInd, curPar));
                        }
                        adj[curInd].clear();
                    } else {
                        ArrayList<Integer> remSet = new ArrayList<>();
                        HashSet<Integer> curSet = map[curInd].get(curPar);

                        for (int j : adj[curInd]) {
                            if (!curSet.contains(j)) {
                                remSet.add(j);
                                queue.add(new Pair(j, curInd, curPar));
                            }
                        }

                        for (int j : remSet)
                            adj[curInd].remove(j);
                    }
                }

                cans++;
            }

            if (ans == -1) {
                out.print("-1");
            } else {
                out.println(ans);
                ArrayList<Integer> ansList = new ArrayList<>();
                ansList.add((n - 1));
                int curInd = n - 1, curPar = ansPar;
                while (curPar != -1) {
                    ansList.add(curPar);

                    int temp = curInd;
                    curInd = curPar;
                    curPar = par[temp][curPar];
                }

                for (int i = ansList.size() - 1; i >= 0; --i)
                    out.print((ansList.get(i) + 1) + " ");
            }
        }

        class Pair {
            int ind;
            int par;
            int prevPar;

            Pair(int a, int b, int c) {
                ind = a;
                par = b;
                prevPar = c;
            }

        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}