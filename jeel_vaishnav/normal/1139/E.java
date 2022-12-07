import java.util.*;
import static java.lang.Math.*;

public class SolutionE {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        int deg[] = new int[m];
        int p[] = new int[n];
        for(int i = 0; i < n; ++i) {
            p[i] = sc.nextInt();
            if(p[i] < m)
                deg[p[i]]++;
        }

        int c[] = new int[n];
        for(int i = 0; i < n; ++i)
            c[i] = sc.nextInt();

        int q = sc.nextInt();
        int qind[] = new int[q];
        int vis[] = new int[n];
        for(int i = 0; i < q; ++i) {
            qind[i] = sc.nextInt() - 1;
            vis[qind[i]] = 1;
        }

        Kunh kunh = new Kunh(2 * m, deg);
        for(int i = 0; i < n; ++i) {    
            if(vis[i] == 0) {
                if(p[i] < m) 
                    kunh.addEdge(p[i], m + c[i] - 1);
            }
        }
        int ans = 0;
        while(ans < m && kunh.addFlow(ans)) 
            ans++;

        int fans[] = new int[q];
        for(int i = q - 1; i >= 0; --i) {
            fans[i] = ans;

            int ind = qind[i];

            if(p[ind] < m) {
                kunh.addEdge(p[ind], m + c[ind] - 1);
            }

            while(ans < m && kunh.addFlow(ans))
                ans++;
        }

        for(int i : fans)
            System.out.println(i);
    }
}
class Kunh {
    int pair[];
    int adj[][];
    int ptr[];
    int vis[];
    int level = 0;
    Kunh(int n, int deg[]) {
        pair = new int[n];
        Arrays.fill(pair, -1);
        adj = new int[n / 2][];
        for(int i = 0; i < n / 2; ++i) {
            adj[i] = new int[deg[i]];
        }
        ptr = new int[n / 2];
        vis = new int[n / 2];
    }
    void addEdge(int i, int j) {
        adj[i][ptr[i]++] = j;
    }
    boolean addFlow(int source) {
        level++;
        return dfs(source);
    }
    boolean dfs(int i) {
        vis[i] = level;

        for(int k = 0; k < ptr[i]; ++k) {
            int j = adj[i][k];
            if(pair[j] == -1) {
                pair[j] = i;
                return true;
            }
            else if(vis[pair[j]] != level && dfs(pair[j])) {
                pair[j] = i;
                return true;
            }
        }

        return false;
    }
}