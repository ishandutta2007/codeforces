import java.util.*;
import java.io.*;

public class Solution {
    public int bruteForce(int n, int m) {
        boolean[][] was = new boolean[n][m];
        int res = 0;
        for (int x=0; x<n; x++)
            for (int y=0; y<m; y++)
                if (!was[x][y]) {
                    res++;
                    for (int ddx = -1; ddx <= 1; ddx += 2) for (int ddy = -1; ddy <= 1; ddy += 2) {
                        int dx = ddx, dy = ddy;
                        int curx = x, cury = y;
                        for (int steps = 1; steps <= n * m; steps++) {
                            was[curx][cury] = true;
                            if (curx + dx >= 0 && curx + dx < n) {
                                curx += dx;
                            } else {
                                curx -= dx;
                                dx *= -1;
                            }
                            if (cury + dy >= 0 && cury + dy < m) {
                                cury += dy;
                            } else {
                                cury -= dy;
                                dy *= -1;
                            }
                        }
                    }
                }
        
        return res;
    }
    
    int compCnt;
    int[] p;
    int[] rank;
    
    int findSet(int x) {
        if (p[x] != x)
            p[x] = findSet(p[x]);
        return p[x];
    }
    
    void merge(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a==b) return;
        compCnt--;
        if (rank[a] < rank[b]) {
            p[a] = b;
        } else {
            p[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    
    void process(int n, int m, int i, int j) {
        merge(i + j, n + m + i + (m - j - 1));;
    }
    
    public int solve(int n, int m) {
        p = new int[2 * (n + m)];
        rank = new int[2 * (n + m)];
        compCnt = 2 * (n + m - 1);
        for (int i=0; i < p.length; i++) {
            p[i] = i;
            rank[i] = 0;
        }
        
        for (int j=0; j < m; j++) {
            process(n, m, 0, j);
            process(n, m, n-1, j);
        }
        
        for (int i=0; i < n; i++) {
            process(n, m, i, 0);
            process(n, m, i, m-1);
        }
        
        return compCnt;
    }
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.close();
        
        System.out.println(solve(n, m));
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}