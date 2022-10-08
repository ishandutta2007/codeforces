import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    int n;
    int[] a;
    
    int[][] memo;
    
    int solve(int x, int y) {
        if (x >= n)
            return 0;
        
        if (y >= n)
            return a[x];
        
        if (y == n - 1)
            return Math.max(a[x], a[y]);
        
        if (memo[x][y] != -1)
            return memo[x][y];
        
        int res = Integer.MAX_VALUE;
        res = Math.min(res, solve(x, y+2) + Math.max(a[y], a[y+1]));
        res = Math.min(res, solve(y, y+2) + Math.max(a[x], a[y+1]));
        res = Math.min(res, solve(y+1, y+2) + Math.max(a[x], a[y]));
                
        memo[x][y] = res;
        return res;
    }
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        n = sc.nextInt();
        a = new int[n];
        for (int i=0; i < n; i++)
            a[i] = sc.nextInt();
        sc.close();
        
        memo = new int[n][n];
        for (int i=0; i<n; i++)
            Arrays.fill(memo[i], -1);
        
        System.out.println(solve(0, 1));
        
        int x = 0, y = 1;
        while (x < n - 1 && y < n - 1) {
            if (solve(x, y) == solve(x, y+2) + Math.max(a[y], a[y+1])) {
                System.out.println((y + 1) + " " + (y + 2));
                y += 2;
                continue;
            }
            if (solve(x, y) == solve(y, y+2) + Math.max(a[x], a[y+1])) {
                System.out.println((x + 1) + " " + (y + 2));
                y += 2;
                x = y-2;
                continue;
            }
            if (solve(x, y) == solve(y+1, y+2) + Math.max(a[x], a[y])) {
                System.out.println((x + 1) + " " + (y + 1));
                y += 2;
                x = y-1;
                continue;
            }
            System.out.println("failure");
        }
        
        if (y == n - 1) {
            System.out.println((x + 1) + " " + (y + 1));
        } else if (x < n) {
            System.out.println(x + 1);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Solution().go();
    }
}