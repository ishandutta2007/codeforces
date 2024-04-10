import java.util.*;
import static java.lang.Math.*;

public class MainE {
    static int dfs(int i, int par, int[] flow, int[] col, int curCol) {
        if(req[i] != -1)
            curCol = i;
        col[i] = curCol;

        int cost = 0;

        for(int j : adj[i]) {
            if(j != par)
                cost += dfs(j, i, flow, col, curCol);
        }

        if(req[i] != -1) {
            if(cost > req[i]) {
                flag = 1;
            }
            flow[i] = req[i] - cost;
            cost = req[i];
        }

        return cost;
    }

    static int flag = 0;
    static ArrayList<Integer> adj[];
    static int req[];

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int capital1 = sc.nextInt() - 1;
        int capital2 = sc.nextInt() - 1;

        int maxVal = 0;
        int a[] = new int[n];
        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
            maxVal = max(maxVal, a[i]);
        }

        ArrayList<Integer> adj1[] = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj1[i] = new ArrayList<>();
        for(int i = 0; i < n - 1; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj1[u].add(v);
            adj1[v].add(u);
        }

        ArrayList<Integer> adj2[] = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj2[i] = new ArrayList<>();
        for(int i = 0; i < n - 1; ++i) {
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            adj2[u].add(v);
            adj2[v].add(u);
        }

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = adj1[i];

        req = new int[n];
        int q = sc.nextInt();
        Arrays.fill(req, -1);

        for(int i = 0; i < q; ++i) {
            int ind = sc.nextInt() - 1;
            req[ind] = sc.nextInt();
        }
        int reqFlow1 = req[capital1];

        int col[] = new int[n];
        int flow[] = new int[n];
        Arrays.fill(flow, 1000);
        dfs(capital1, -1, flow, col, capital1); 
        if(flag == 1) {
            System.out.print("-1");
            return;
        }

        adj = new ArrayList[n];
        for(int i = 0; i < n; ++i)
            adj[i] = adj2[i];

        req = new int[n];
        q = sc.nextInt();
        Arrays.fill(req, -1);

        for(int i = 0; i < q; ++i) {
            int ind = sc.nextInt() - 1;
            req[ind] = sc.nextInt();
        }
        int reqFlow2 = req[capital2];

        if(reqFlow1 != reqFlow2) {
            System.out.print("-1");
            return;
        }

        int col2[] = new int[n];
        int flow2[] = new int[n];
        Arrays.fill(flow2, 1000);
        dfs(capital2, -1, flow2, col2, capital2);  
        if(flag == 1) {
            System.out.print("-1");
            return;
        }

        List<Edge>[] graph = createGraph(2 * n + 2);
        int source = 0, sink = 2 * n + 1;
        for(int i = 0; i < n; ++i) {
            addEdge(graph, source, i + 1, flow[i], 0);
            addEdge(graph, n + i + 1, sink, flow2[i], 0);
            addEdge(graph, col[i] + 1, n + col2[i] + 1, 1, -a[i] + maxVal);
        }

        int[] ans = minCostFlow(graph, source, sink, n);
        if(ans[0] != reqFlow1) {
            System.out.print("-1");
            return;
        }

        int fans = ans[1] - maxVal * reqFlow1;
        fans = -fans;

        System.out.print(fans);
    }

    static class Edge {
        int to, f, cap, cost, rev;

        Edge(int v, int cap, int cost, int rev) {
          this.to = v;
          this.cap = cap;
          this.cost = cost;
          this.rev = rev;
        }
    }

    static List<Edge>[] createGraph(int n) {
        List<Edge>[] graph = new List[n];
        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();
        return graph;
    }

    static void addEdge(List<Edge>[] graph, int s, int t, int cap, int cost) {
        graph[s].add(new Edge(t, cap, cost, graph[t].size()));
        graph[t].add(new Edge(s, 0, -cost, graph[s].size() - 1));
    }

    static void bellmanFord(List<Edge>[] graph, int s, int[] dist) {
        int n = graph.length;
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[s] = 0;
        boolean[] inqueue = new boolean[n];
        int[] q = new int[n];
        int qt = 0;
        q[qt++] = s;
        for (int qh = 0; (qh - qt) % n != 0; qh++) {
          int u = q[qh % n];
          inqueue[u] = false;
          for (int i = 0; i < graph[u].size(); i++) {
            Edge e = graph[u].get(i);
            if (e.cap <= e.f)
              continue;
            int v = e.to;
            int ndist = dist[u] + e.cost;
            if (dist[v] > ndist) {
              dist[v] = ndist;
              if (!inqueue[v]) {
                inqueue[v] = true;
                q[qt++ % n] = v;
              }
            }
          }
        }
      }

    static int[] minCostFlow(List<Edge>[] graph, int s, int t, int maxf) {
        int n = graph.length;
        int[] prio = new int[n];
        int[] curflow = new int[n];
        int[] prevedge = new int[n];
        int[] prevnode = new int[n];
        int[] pot = new int[n];

        // bellmanFord invocation can be skipped if edges costs are non-negative
        bellmanFord(graph, s, pot);
        int flow = 0;
        int flowCost = 0;
        while (flow < maxf) {
            PriorityQueue<Long> q = new PriorityQueue<>();
            q.add((long) s);
            Arrays.fill(prio, Integer.MAX_VALUE);
            prio[s] = 0;
            boolean[] finished = new boolean[n];
            curflow[s] = Integer.MAX_VALUE;
            while (!finished[t] && !q.isEmpty()) {
                long cur = q.remove();
                int u = (int) (cur & 0xFFFF_FFFFL);
                int priou = (int) (cur >>> 32);
                if (priou != prio[u])
                  continue;
                finished[u] = true;
                for (int i = 0; i < graph[u].size(); i++) {
                    Edge e = graph[u].get(i);
                    if (e.f >= e.cap)
                        continue;
                    int v = e.to;
                    int nprio = prio[u] + e.cost + pot[u] - pot[v];
                    if (prio[v] > nprio) {
                        prio[v] = nprio;
                        q.add(((long) nprio << 32) + v);
                        prevnode[v] = u;
                        prevedge[v] = i;
                        curflow[v] = Math.min(curflow[u], e.cap - e.f);
                    }
                }
            }
            if (prio[t] == Integer.MAX_VALUE)
                break;
            for (int i = 0; i < n; i++)
                if (finished[i])
                    pot[i] += prio[i] - prio[t];
            int df = Math.min(curflow[t], maxf - flow);
            flow += df;
            for (int v = t; v != s; v = prevnode[v]) {
                Edge e = graph[prevnode[v]].get(prevedge[v]);
                e.f += df;
                graph[v].get(e.rev).f -= df;
                flowCost += df * e.cost;
            }
        }
        return new int[]{flow, flowCost};
    }
}