import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    final int MOD = 1000000007;
    
    int[][] C;
    
    int M;
    
    int[] X, Y;
    
    int[][] memo;
    
    int solve(int pos, int have) {
        if (pos == M)
            return have == 0 ? 1 : 0;
        
        if (memo[pos][have] != -1)
            return memo[pos][have];
        
        long res = 0;
        have += X[pos];
        
        for (int leave=0; leave <= Math.min(have, Y[pos]); leave++) {
            res += (long)C[have][leave] * (long)solve(pos + 1, have - leave);
            if (res >= 7000000000000000000l)
                res %= MOD;
        }
        
        res %= MOD;
        
        memo[pos][have - X[pos]] = (int)res;
        return memo[pos][have - X[pos]];
    }
    
    void main() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
    
        C = new int[1001][1001];
        for (int i=0; i<=1000; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j=1; j<i; j++) {
                C[i][j] = C[i-1][j] + C[i-1][j-1];
                if (C[i][j]>=MOD) C[i][j] -= MOD;
            }
        }
        
        M = sc.nextInt();
        
        X = new int[M];
        Y = new int[M];
        
        int N = 0;
        for (int i=0; i < M; i++) {
            X[i] = sc.nextInt();
            N += X[i];
        }
        for (int i=0; i < M; i++) Y[i] = sc.nextInt();
        
        sc.close();
        
        memo = new int[M+1][1001];
        
        for (int i=0; i < memo.length; i++)
            Arrays.fill(memo[i], -1);
        
        long res = solve(0, 0);
        for (int i=0; i < M; i++) {
            res = res * (long)C[N][X[i]];
            N -= X[i];
            res %= MOD;
        }
        
        System.out.println(res);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).main();
    }
}