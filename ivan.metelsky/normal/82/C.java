import java.util.*;
import java.io.*;

public class Solution {
    class Edge {
        int from, to, cp;
        Edge next;
        public Edge(int from, int to, int cp) {
            this.from = from;
            this.to = to;
            this.cp = cp;
        }
    }
    
    Edge[] adj;
    
    void addEdge(int from, int to, int cp) {
        Edge a = new Edge(from, to, cp);
        Edge b = new Edge(to, from, cp);
        a.next = adj[from];
        b.next = adj[to];
        adj[from] = a;
        adj[to] = b;
    }
    
    int[] par;
    int[] cp;
    
    void dfs(int v, int p) {
        Edge e = adj[v];
        while (e != null) {
            if (e.to != p) {
                par[e.to] = v;
                cp[e.to] = e.cp;
                dfs(e.to, v);
            }
            e = e.next;
        }
    }
    
    PriorityQueue<Integer>[] queues;
    
    void dfs1(int v, int p) {
        if (v != 0) {
            int can = cp[v];
            while (can > 0 && !queues[v].isEmpty()) {
                int pp = queues[v].poll();
                queues[par[v]].add(pp);
                can--;
            }
        }
        
        Edge e = adj[v];
        while (e != null) {
            if (e.to != p) {
                dfs1(e.to, v);
            }
            e = e.next;
        }
    }
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int[] pri = new int[n];
        Map<Integer, Integer> idByPri = new HashMap<Integer, Integer>();
        for (int i=0; i<n; i++) {
            pri[i] = sc.nextInt();
            idByPri.put(pri[i], i);
        }
        adj = new Edge[n];
        for (int i=0; i<n-1; i++)
            addEdge(sc.nextInt()-1, sc.nextInt()-1, sc.nextInt());
        sc.close();
        
        par = new int[n];
        cp = new int[n];
        dfs(0, -1);
        
        queues = new PriorityQueue[n];
        for (int i=0; i < n; i++) {
            queues[i] = new PriorityQueue<Integer>();
            queues[i].add(pri[i]);
        }
        
        int[] ans = new int[n];
        int left = n;
        for (int time=0; ; time++) {
            while (!queues[0].isEmpty()) {
                int pp = queues[0].poll();
                left--;
                ans[idByPri.get(pp)] = time;
            }
            if (left == 0) break;
            dfs1(0, -1);
        }
        
        for (int i=0; i < n; i++) {
            System.out.print(ans[i]);
            if (i+1<n) System.out.print(" ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}