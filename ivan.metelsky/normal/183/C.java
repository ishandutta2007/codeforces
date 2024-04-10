import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CDF_C {
    class Edge {
        int from, to;
        Edge next;
        public Edge(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }

    Edge[] adj;

    void addEdge(int x, int y) {
        Edge a = new Edge(x, y);
        Edge b = new Edge(x, y);
        a.next = adj[x];
        adj[x] = a;
        b.next = adj[y];
        adj[y] = b;
    }

    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        adj = new Edge[n];
        int[] from = new int[m];
        int[] to = new int[m];
        for (int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            from[i] = Integer.parseInt(st.nextToken()) - 1;
            to[i] = Integer.parseInt(st.nextToken()) - 1;
            if (from[i] == to[i]) {
                System.out.println(1);
                System.exit(0);
            }
            addEdge(from[i], to[i]);
        }
        br.close();

        int[] id = new int[n];
        Arrays.fill(id, -1);

        int[] QV = new int[n];
        int qBeg = 0, qEnd = 0;

        for (int i=0; i<n; i++)
            if (id[i] == -1) {
                QV[qBeg++] = i;
                id[i] = 1000000;
                while (qEnd < qBeg) {
                    int curV = QV[qEnd++];
                    Edge e = adj[curV];
                    while (e != null) {
                        if (e.from == curV && id[e.to] == -1) {
                            id[e.to] = id[curV] + 1;
                            QV[qBeg++] = e.to;
                        }
                        if (e.to == curV && id[e.from] == -1) {
                            id[e.from] = id[curV] - 1;
                            QV[qBeg++] = e.from;
                        }
                        e = e.next;
                    }
                }
            }

        for (int i=0; i<m; i++)
            if (id[to[i]] != id[from[i]] + 1) {
                for (int k=n; k >= 1; k--) {
                    int a = id[from[i]] % k;
                    int b = id[to[i]] % k;
                    if (b != (a + 1) % k)
                        continue;

                    boolean ok = true;
                    for (int j=0; j < m && ok; j++) {
                        a = id[from[j]] % k;
                        b = id[to[j]] % k;
                        if (b != (a + 1) % k)
                            ok = false;
                    }

                    if (ok) {
                        System.out.println(k);
                        System.exit(0);
                    }
                }
            }

        System.out.println(n);
    }

    public static void main(String[] args) throws Exception {
        new CDF_C().doMain();
    }
}