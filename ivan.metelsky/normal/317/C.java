import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ProblemC {
    int n;
    long v;
    boolean[][] adj;
    int[] deg;
    boolean[] used;
    long[] have, need;
    int ops;
    StringBuilder res = new StringBuilder();

    public void doIt(int from, int to, long cnt) {
        have[from] -= cnt;
        have[to] += cnt;
        ops++;
        res.append((from+1) + " " + (to+1) + " " + cnt + "\n");
    }

    void sinkUp(int pos, int parent) {
        for (int i=0; i < n; i++)
            if (adj[pos][i] && i != parent) {
                sinkUp(i, pos);
                doIt(i, pos, Math.min(have[i], v - have[pos]));
            }
    }

    void sinkDown(int pos, int parent) {
        for (int i=0; i < n; i++)
            if (adj[pos][i] && i != parent) {
                sinkDown(i, pos);
                doIt(pos, i, Math.min(have[pos], v - have[i]));
            }
    }

    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());
        int[] id = new int[n];
        for (int i=0; i<n; i++) {
            id[i] = i;
        }
        have = new long[n]; need = new long[n];
        st = new StringTokenizer(br.readLine());
        for (int i=0; i<n; i++) {
            have[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i=0; i<n; i++) {
            need[i] = Integer.parseInt(st.nextToken());
        }
        used = new boolean[n];
        adj = new boolean[n][n];
        deg = new int[n];
        for (int i=0; i<e; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            x--; y--;
            if (id[x] != id[y]) {
                deg[x]++; deg[y]++;
                adj[x][y] = adj[y][x] = true;
                int idx = id[x], idy = id[y];
                for (int t=0; t<n; t++) if (id[t] == idx) id[t] = idy;
            }
        }
        br.close();

        long[] sumHave = new long[n];
        long[] sumNeed = new long[n];
        for (int i=0; i<n; i++) {
            sumHave[id[i]] += have[i];
            sumNeed[id[i]] += need[i];
        }
        for (int i=0; i<n; i++)
            if (sumHave[i] != sumNeed[i]) {
                System.out.println("NO");
                System.exit(0);
            }

        while (true) {
            int leaf = 0;
            while (leaf < n && (used[leaf] || deg[leaf] != 1)) leaf++;
            if (leaf == n) break;
            int parent = 0;
            while (!adj[leaf][parent]) parent++;
            if (have[leaf] < need[leaf]) {
                sinkUp(parent, leaf);
                doIt(parent, leaf, need[leaf] - have[leaf]);
            } else if (have[leaf] > need[leaf]) {
                sinkDown(parent, leaf);
                doIt(leaf, parent, have[leaf] - need[leaf]);
            }
            adj[leaf][parent] = adj[parent][leaf] = false;
            deg[parent]--; deg[leaf]--;
        }

        System.out.println(ops);
        System.out.println(res);
    }
    public static void main(String[] args) throws Exception {
        new ProblemC().doMain();
    }
}