import java.util.*;

public class Solution {
    public void doMain() throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        boolean[][] adj = new boolean[n][n];
        for (int i=0; i<m; i++) {
            int a = sc.nextInt()-1, b = sc.nextInt()-1;
            adj[a][b] = adj[b][a] = true;
        }
        
        long res = 0;
        
        for (int st=0; st+1<n; st++) {
            //System.out.println("st="+st);
            long[][] numWays = new long[1<<(n-st-1)][n-st-1];
            for (int i=st+1; i<n; i++)
                if (adj[st][i]) numWays[1<<(i-st-1)][i-st-1] = 1;
            
            for (int mask=1; mask < (1<<(n-st-1)); mask++) {
                boolean simple = ((mask & (mask-1)) == 0);
                for (int last=0; last<n-st-1; last++) if (numWays[mask][last]!=0) {
                    if (adj[last+st+1][st] && !simple) res += numWays[mask][last];
                    for (int next=0; next<n-st-1; next++)
                        if (adj[last+st+1][next+st+1] && (mask & (1<<next)) == 0)
                            numWays[mask | (1<<next)][next] += numWays[mask][last];
                }
            }
        }
        
        System.out.println(res/2);
    }
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}