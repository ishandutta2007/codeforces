import java.util.*;
import java.io.*;

public class Solution {
    int solve(int n, int x, int[] a) {
        Arrays.sort(a);
        
        if (x == 2)
            return 0;
        
        if (a.length == 0)
            return -1;
        
        if (a[0] == 1)
            return 1;
        
        int MAX = 2000001;
        
        boolean[] isPrime = new boolean[MAX];
        Arrays.fill(isPrime, true);
        int primeCnt = 0;
        for (int i=2; i < x; i++) if (isPrime[i]) {
            if (Arrays.binarySearch(a, i) < 0)
                return -1;
            
            primeCnt++;
            for (int j = 2*i; j < MAX; j += i)
                isPrime[j] = false;
        }
        
        return primeCnt;
    }
    
    int bruteForce(int n, int x, int[] a) {
        int[][] sign = new int[x+1][n];
        for (int i=2; i<=x; i++)
            for (int j=0; j<n; j++)
                sign[i][j] = (i + a[j] - 1) / a[j];
        
        for (int i=2; i<x; i++)
            if (Arrays.equals(sign[i], sign[i+1]))
                return -1;
        
        int ans = n + 1;
        for (int mask=0; mask < (1<<n); mask++) {
            boolean ok = true;
            for (int i=2; i<x; i++) {
                boolean eq = true;
                for (int j=0; j < n; j++) if ((mask & (1<<j)) != 0 && sign[i][j] != sign[i+1][j]) {
                    eq = false;
                    break;
                }
                if (eq) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = Math.min(ans, Integer.bitCount(mask));
        }
        
        return ans;
    }
    
    public void go() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int[] a = null;
        if (n == 0) a = new int[0];
        else {
            st = new StringTokenizer(br.readLine());
            a = new int[n];
            for (int i=0; i<n; i++)
                a[i] = Integer.parseInt(st.nextToken());
        }
        br.close();
        
        System.out.println(solve(n,x,a));
    }
    
    public static void main(String[] args) throws Exception {
        /*Random rnd = new Random();
        int it = 0;
        while (true) {
            it++;
            if (it%1000==0) System.out.println(it);
            int n = rnd.nextInt(11);
            int x = rnd.nextInt(100-2+1)+2;
            int max = rnd.nextInt(100) + 1;
            int[] a = new int[n];
            for (int i=0; i<n; i++) a[i] = rnd.nextInt(max) + 1;
            
            int ans1 = new Solution().solve(n,x,a.clone());
            int ans2 = new Solution().bruteForce(n,x,a.clone());
            
            if (ans1 != ans2) {
                System.out.println(n);
                System.out.println(x);
                for (int i=0; i < n; i++)
                    System.out.println(a[i]);
                
                System.out.println(ans1+" "+ans2);
                System.exit(0);
            }
        }*/
        (new Solution()).go();
    }
}