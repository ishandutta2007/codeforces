import java.util.*;
import java.io.*;

public class Solution {
    public void doMain() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int k = sc.nextInt();
        int L = sc.nextInt();
        
        Set<Integer> nums = new HashSet<Integer>();
        for (int i=0; i < k; i++) {
            int x = sc.nextInt();
            if (nums.contains(x - 1))
                nums.remove(x - 1);
            else
                nums.add(x - 1);
            if (nums.contains(x))
                nums.remove(x);
            else
                nums.add(x);
        }
        
        int cnt = nums.size();
        int[] X = new int[cnt];
        int pos = 0;
        for (int val : nums)
            X[pos++] = val;
        
        int[] a = new int[L];
        for (int i=0; i < L; i++)
            a[i] = sc.nextInt();

        sc.close();
        
        int[][] dist = new int[cnt][cnt];
        for (int i=0; i < cnt; i++)
            Arrays.fill(dist[i], 1000000000);
        
        for (int i=0; i < cnt; i++) {
            int[] len = new int[n + 1];
            Arrays.fill(len, 1000000000);
            len[X[i]] = 0;
            int[] Q = new int[n + 1];
            int qBeg = 0, qEnd = 0;
            Q[qBeg++] = X[i];
            while (qEnd < qBeg) {
                int cur = Q[qEnd++];
                for (int j=0; j < L; j++) {
                    if (cur >= a[j] && len[cur - a[j]] == 1000000000) {
                        len[cur - a[j]] = len[cur] + 1;
                        Q[qBeg++] = cur - a[j];
                    }
                    if (cur + a[j] <= n && len[cur + a[j]] == 1000000000) {
                        len[cur + a[j]] = len[cur] + 1;
                        Q[qBeg++] = cur + a[j];
                    }
                }
            }
            for (int j=0; j < cnt; j++)
                dist[i][j] = len[X[j]];
        }
        
        int[] dp = new int[1<<cnt];
        Arrays.fill(dp, 1000000000);
        dp[0] = 0;
        for (int mask=0; mask + 1 < (1<<cnt); mask++) {
            if (dp[mask] == 1000000000)
                continue;
            int b1 = 0;
            while ((mask & (1<<b1)) != 0) b1++;
            for (int b2 = b1 + 1; b2 < cnt; b2++)
                if ((mask & (1<<b2)) == 0)
                    dp[mask | (1<<b1) | (1<<b2)] = Math.min(dp[mask | (1<<b1) | (1<<b2)], dp[mask] + dist[b1][b2]);
        }
        
        int ans = dp[(1<<cnt) - 1];
        System.out.println(ans == 1000000000 ? -1 : ans);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}