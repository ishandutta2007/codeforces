import java.util.*;
import java.io.*;

public class Solution {
    public long maxParts(long x, long y, long z, long k) {
        long a = 1, b = 1, c = 1;
        while ((a < x || b < y || c < z) && (k > 0)) {
            int t = -1;
            long min = 10000000;
            if (a < x && a < min) {
                t = 0;
                min = a;
            }
            if (b < y && b < min) {
                t = 1;
                min = b;
            }
            if (c < z && c < min) {
                t = 2;
                min = c;
            }
            k--;
            if (t==0) a++;
            if (t==1) b++;
            if (t==2) c++;
        }
        return a * b * c;
    }
    
    public long bruteForce(long x, long y, long z, long k) {
        long res = 0;
        for (long a = 1; a <= x; a++)
            for (long b = 1; b <= y; b++)
                for (long c = 1; c <= z; c++)
                    if (a + b + c <= k + 3)
                        res = Math.max(res, a * b * c);
        return res;
    }
    
    public static void main(String[] args) throws Exception {
        /*Random rnd = new Random();
        int it = 0;
        while (true) {
            it++;
            if (it%1000==0) System.out.println(it);
            
            int x = rnd.nextInt(10) + 1;
            int y = rnd.nextInt(10) + 1;
            int z = rnd.nextInt(10) + 1;
            int k = rnd.nextInt(100) + 1;
            
            long ans1 = (new Solution()).maxParts(x, y, z, k);
            long ans2 = (new Solution()).bruteForce(x, y, z, k);
            
            if (ans1!=ans2) {
                System.out.println(x+" "+y+" "+z+" "+k);
                System.out.println(ans1+" "+ans2);
                System.exit(0);
            }
        }*/
        
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        long x = sc.nextLong(), y = sc.nextLong(), z = sc.nextLong(), k = sc.nextLong();
        System.out.println((new Solution()).maxParts(x, y, z, k));
    }
}