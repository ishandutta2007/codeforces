import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    final int MOD = 1000000007;
    
    void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        br.close();
        
        long[] A = new long[s.length()];
        
        A[0] = s.charAt(0);
        for (int i=1; i < s.length(); i++)
            A[i] = (256 * A[i-1] + s.charAt(i)) % MOD;
        
        long[] B = new long[s.length()];
        long mul = 1;
        B[0] = s.charAt(0);
        for (int i=1; i < s.length(); i++) {
            mul = (256 * mul) % MOD;
            B[i] = (B[i-1] + mul * s.charAt(i)) % MOD;
        }
        
        int[] palin = new int[s.length()];
        palin[0] = 1;
        for (int i=1; i < s.length(); i++)
            if (A[i] != B[i])
                palin[i] = 0;
            else
                palin[i] = palin[(i-1)/2] + 1;
        
        int res = 0;
        for (int i=0; i < s.length(); i++)
            res += palin[i];
        
        System.out.println(res);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}