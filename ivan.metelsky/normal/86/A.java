import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    long rev(long n) {
        long pw = 1;
        while (pw <= n) pw *= 10;
        return pw - n - 1;
    }
    
    long findWeight(long n) {
        return n * rev(n);
    }
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        long l = sc.nextLong();
        long r = sc.nextLong();
        sc.close();
        
        long res = Math.max(findWeight(l), findWeight(r));
        
        long cur = 5;
        while (cur <= r) {
            if (cur >= l && cur <= r)
                res = Math.max(res, findWeight(cur));
            if (cur-1 >= l && cur-1 <= r)
                res = Math.max(res, findWeight(cur-1));
            cur = 10*cur;
        }
        
        System.out.println(res);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}