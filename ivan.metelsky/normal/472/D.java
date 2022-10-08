import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class ProblemD {
    static class Edge implements Comparable<Edge> {
        int x, y;
        int w;
        Edge next;
        public Edge(int x, int y, int w) {
            this.x = x;
            this.y = y;
            this.w = w;
        }
        public int compareTo(Edge other) {
            return this.w - other.w;
        }
    }
    static Edge[] adj;
    static void addEdge(int x, int y, int w) {
        Edge a = new Edge(x, y, w);
        Edge b = new Edge(y, x, w);
        a.next = adj[x]; adj[x] = a;
        b.next = adj[y]; adj[y] = b;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] A = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
            if (A[i][i] != 0) {
                System.out.println("NO");
                System.exit(0);
            }
        }
        int p = 0;
        Edge[] e = new Edge[n * (n - 1) / 2];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (A[i][j] != A[j][i] || A[i][j] == 0) {
                    System.out.println("NO");
                    System.exit(0);
                }
                e[p++] = new Edge(i, j, A[i][j]);
            }
        }
        Arrays.sort(e);
        int[] id = new int[n];
        for (int i=0; i < n; i++) {
            id[i] = i;
        }
        adj = new Edge[n];
        for (int i = 0; i < e.length; i++) {
            if (id[e[i].x] != id[e[i].y]) {
                addEdge(e[i].x, e[i].y, e[i].w);
                int Q = id[e[i].x];
                int W = id[e[i].y];
                for (int j = 0; j < n; j++) {
                    if (id[j] == Q) {
                        id[j] = W;
                    }
                }
            }
        }
        final long INF = 1000000000000000L;
        int[] Q = new int[n];
        for (int i = 0; i < n; i++) {
            long[] dst = new long[n];
            Arrays.fill(dst, INF);
            int qBeg = 0, qEnd = 0;
            Q[qBeg++] = i;
            dst[i] = 0;
            while (qEnd < qBeg) {
                int curV = Q[qEnd++];
                Edge cur = adj[curV];
                while (cur != null) {
                    if (dst[cur.y] == INF) {
                        dst[cur.y] = dst[cur.x] + cur.w;
                        Q[qBeg++] = cur.y;
                    }
                    cur = cur.next;
                }
            }
            for (int j = 0; j < n; j++) {
                if (dst[j] != A[i][j]) {
                    System.out.println("NO");
                    System.exit(0);
                }
            }
        }

        System.out.println("YES");
    }
}