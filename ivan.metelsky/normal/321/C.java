import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ProblemC {
    class Edge {
        int from, to;
        Edge next;
        public Edge(int from, int to) {
            this.from = from;
            this.to = to;
        }
    }
    Edge[] adj;
    char[] rank;

    public void addEdge(int from, int to ) {
        Edge e = new Edge(from, to);
        e.next = adj[from];
        adj[from] = e;
    }

    int treeSize(int v, int p) {
        int ans = 1;
        Edge e = adj[v];
        while (e != null) {
            if (rank[e.to] == ' ' && e.to != p) ans += treeSize(e.to, v);
            e = e.next;
        }
        return ans;
    }

    int tot, bestSubtree, bestV;

    int chooseVert(int v, int p) {
        int sumBelow = 0;
        int maxBelow = 0;
        Edge e = adj[v];
        while (e != null) {
            if (rank[e.to] == ' ' && e.to != p) {
                int belowSz = chooseVert(e.to, v);
                if (belowSz > maxBelow) {
                    maxBelow = belowSz;
                }
                sumBelow += belowSz;
            }
            e = e.next;
        }
        int maxSubtree = Math.max(maxBelow, tot - sumBelow - 1);
        if (maxSubtree < bestSubtree) {
            bestSubtree = maxSubtree;
            bestV = v;
        }
        return sumBelow + 1;
    }

    void solve(int root, char c) {
        tot = treeSize(root, -1);
        bestSubtree = tot;
        bestV = -1;
        chooseVert(root, -1);
        rank[bestV] = c;
        Edge e = adj[bestV];
        while (e != null) {
            if (rank[e.to] == ' ') {
                solve(e.to, (char)((int)c + 1));
            }
            e = e.next;
        }
    }

    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        adj = new Edge[n];
        for (int i=0; i<n-1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            a--; b--;
            addEdge(a, b);
            addEdge(b, a);
        }
        br.close();

        rank = new char[n];
        Arrays.fill(rank, ' ');
        solve(0, 'A');

        StringBuilder sb = new StringBuilder();
        for (int i=0; i<n; i++) {
            sb.append(rank[i]);
            if (i+1<n) sb.append(' ');
        }

        System.out.println(sb.toString());
    }

    public static void main(String[] args) throws Exception {
        new ProblemC().doMain();
    }
}