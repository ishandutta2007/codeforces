import java.util.*;

public class Solution {
    class Data {
        long x, y;
    }
    
    long gcd(long a, long b) {
        while (a>0 && b>0)
            if (a>b) a%=b; else b%=a;
        return a+b;
    }
    
    Data solve(long a, long b) {
        if (a < b) {
            Data tt = solve(b, a);
            long tmp = tt.x;
            tt.x = tt.y;
            tt.y = tmp;
            return tt;
        }
        if (a == b) {
            Data tt = new Data();
            tt.x = 1;
            tt.y = 0;
            return tt;
        }
        if (b == 0) {
            Data tt = new Data();
            tt.x = 1;
            tt.y = 0;
            return tt;
        }
        
        //b * tt.x + (a - b * (a/b)) * tt.y = 1
        //a * tt.y + b * (tt.x - (a/b) * tt.y) = 1;     
        
        Data tt = solve(b, a % b);
        Data res = new Data();
        res.x = tt.y;
        res.y = tt.x - (a/b) * tt.y;
        return res;
    }
    
    void doMain() {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextInt(), B = sc.nextInt(), C = sc.nextInt();
        sc.close();
        
        if (C == 0) {
            System.out.println(B + " " + (-A));
            return;
        }
        
        long d = gcd(Math.abs(A), Math.abs(B));
        
        if (C % d != 0) {
            System.out.println(-1);
            return;
        }
        
        A /= d; B /= d; C /= d;
        
        Data tt = solve(Math.abs(A), Math.abs(B));
        tt.x *= -1; tt.y *= -1;
        if (A<0) tt.x *= -1;
        if (B<0) tt.y *= -1;
        
        System.out.println((tt.x * C) + " " + (tt.y * C));
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}