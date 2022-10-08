import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    boolean isPrime(long x) {
        for (int i=2; i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }
    
    int[] primes;
    int primeCnt;
    
    long res = 0;
    
    void go(long a, long b, int pos, int count, long lcm) {
        if (lcm > b) return;
        long add = b / lcm - (a - 1) / lcm;
        if (count % 2 == 0)
            res += add;
        else
            res -= add;
        for (int next=pos+1; next < primeCnt; next++)
            go(a, b, next, count+1, lcm*primes[next]);
    }
    
    
    long solve(long a, long b, long k) {
        if (!isPrime(k))
            return 0;
        
        a = (a + k - 1) / k;
        b = b / k;
        
        if (b < k) {
            return (a <= 1 && 1 <= b ? 1 : 0);
        }
        
        primes = new int[100000];
        primeCnt = 0;
        for (int i=2; i < k; i++)
            if (isPrime(i))
                primes[primeCnt++] = i;
        
        if (b <= 10000000) {
            boolean[] good = new boolean[(int)b + 1];
            Arrays.fill(good, true);
            for (int i=0; i < primeCnt; i++)
                for (int j=primes[i]; j <= b; j += primes[i])
                    good[j] = false;
            
            int res = 0;
            for (int i=(int)a; i <= b; i++)
                if (good[i] || i == 1)
                    res++;
            
            return res;
        }
        
        go(a, b, -1, 0, 1);
                
        return res;
    }
    
    long bruteForce(long a, long b, long k) {
        long res = 0;
        for (int i = (int)a; i <= b; i++) {
            if (i % k != 0) continue;
            boolean ok = true;
            for (int j=2; j < k; j++)
                if (i % j == 0) {
                    ok = false;
                    break;
                }
            if (ok) res++;
        }
        return res;
    }
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        long a = sc.nextLong();
        long b = sc.nextLong();
        long k = sc.nextLong();
        sc.close();
        
        System.out.println(solve(a, b, k));
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
        
//      int it = 0;
//      Random rnd = new Random();
//      while (true) {
//          it++;
//          if (it%1000==0) System.out.println(it);
//          
//          int a = rnd.nextInt(100)+1;
//          int b = rnd.nextInt(100)+1;
//          if (a>b) {
//              int tmp=a; a=b; b=tmp;
//          }
//          int k = rnd.nextInt(100)+1;
//          
//          long ans1 = new Solution().solve(a,b,k);
//          long ans2 = new Solution().bruteForce(a, b, k);
//          
//          if (ans1!=ans2) {
//              System.out.println(a+" "+b+" "+k);
//              System.out.println(ans1+" "+ans2);
//              System.exit(0);
//          }
//      }
    }
}