import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ProblemE {
    int n;

    class Edge {
        int from, to;
        Edge next;
        String s;
        public Edge(int from, int to, String s) {
            this.from = from;
            this.to = to;
            this.s = s;
            this.next = adj[from];
        }
    }

    class State {
        int v;
        int len;
        public State(int v, int len) {
            this.v = v;
            this.len = len;
        }
    }

    Edge[] adj;

    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        adj = new Edge[n + 1];
        for (int i=2; i<=n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            adj[from] = new Edge(from, i, st.nextToken());
        }
        String s = br.readLine();
        int L = s.length();
        int[] p = new int[L+1];
        p[1] = 0;
        for (int i=2; i<=L; i++) {
            int x = p[i-1];
            while (x > 0 && s.charAt(x) != s.charAt(i-1)) x = p[x];
            if (s.charAt(x) == s.charAt(i-1)) p[i] = x + 1; else p[i] = 0;
        }
        State[] Q = new State[n];
        int qBeg = 0, qEnd = 0;
        Q[qBeg++] = new State(1, 0);
        int ans = 0;
        while (qEnd < qBeg) {
            State cur = Q[qEnd++];
            Edge e = adj[cur.v];
            while (e != null) {
                int newLen = cur.len;
                for (char c : e.s.toCharArray()) {
                    if (newLen == L) newLen = p[newLen];
                    while (newLen > 0 && s.charAt(newLen) != c) newLen = p[newLen];
                    if (s.charAt(newLen) == c) newLen++;
                    if (newLen == L) ans++;
                }
                Q[qBeg++] = new State(e.to, newLen);
                e = e.next;
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws Exception {
        new ProblemE().doMain();
    }
}