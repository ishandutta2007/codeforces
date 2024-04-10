import java.util.*;
import java.io.*;

public class Solution {
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        String s = sc.next();
        int k = sc.nextInt();
        int n = s.length();
        int cnt = sc.nextInt();
        int[][] add = new int[26][26];
        for (int i=0; i < cnt; i++) {
            String a = sc.next();
            String b = sc.next();
            add[a.charAt(0) - 'a'][b.charAt(0) - 'a'] = sc.nextInt();
        }
        sc.close();
                
        int[][][] f = new int[n][k + 1][26];
        for (int i=0; i < f.length; i++)
            for (int j=0; j < f[i].length; j++)
                Arrays.fill(f[i][j], -1000000000);
        
        for (char c = 'a'; c <= 'z'; c++)
            if (k > 0 || s.charAt(0) == c)
                f[0][c == s.charAt(0) ? 0 : 1][c - 'a'] = 0;
        
        for (int pos = 0; pos + 1 < n; pos++)
            for (int rep = 0; rep <= k; rep++)
                for (int last=0; last < 26; last++)
                    for (int next=0; next < 26; next++) {
                        int nextRep = rep + (s.charAt(pos + 1) - 'a' == next ? 0 : 1);
                        if (nextRep <= k)
                            f[pos + 1][nextRep][next] = Math.max(f[pos + 1][nextRep][next], f[pos][rep][last] + add[last][next]);
                    }
        
        int ans = -1000000000;
        for (int rep = 0; rep <= k; rep++)
            for (int last=0; last < 26; last++)
                ans = Math.max(ans, f[n-1][rep][last]);
        
        System.out.println(ans);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}