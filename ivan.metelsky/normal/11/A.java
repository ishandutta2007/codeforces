import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    public void doMain() throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long d = sc.nextLong();
        long[] b = new long[n];
        for (int i=0; i<n; i++) b[i] = sc.nextLong();
        sc.close();
        
        long res = 0;
        for (int i=1; i<n; i++) {
            if (b[i] > b[i-1]) continue;
            long k = (b[i-1] - b[i]) / d + 1;
            res += k;
            b[i] += k * d;
        }
        
        System.out.println(res);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}