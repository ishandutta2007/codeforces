import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    int n, m, k;
    char[][] map;
    
    int stI, stJ, fnI, fnJ;
    
    int bestLen = 10000;
    String bestP = null;
    
    boolean[] can;
    
    final int[] dx = new int[] {1, -1, 0, 0};
    final int[] dy = new int[] {0, 0, 1, -1};
    
    boolean[][] pass;
    int[][] len;
    
    int[] qI, qJ;
    
    class Pair implements Comparable<Pair> {
        int vi, vj;
        char let;
        int next;
        public Pair(int vi, int vj, char let, int next) {
            this.vi = vi;
            this.vj = vj;
            this.let = let;
            this.next = next;
        }
        public int compareTo(Pair other) {
            if (this.let != other.let)
                return this.let - other.let;
            else
                return this.next - other.next;
        }
    }
    
    void go(int pos, int taken) {
        if (taken > k)
            return;
        
        if (pos == 26) {
            for (int i=0; i < n; i++) {
                Arrays.fill(len[i], -1);
                Arrays.fill(pass[i], false);
            }
            
            pass[stI][stJ] = true;
            pass[fnI][fnJ] = true;
            for (int i=0; i < n; i++)
                for (int j=0; j < m; j++)
                    if (map[i][j] >= 'a' && map[i][j] <= 'z' && can[map[i][j]-'a'])
                        pass[i][j] = true;
            
            int qBeg = 0, qEnd = 0;
            qI[qBeg] = fnI;
            qJ[qBeg++] = fnJ;
            len[fnI][fnJ] = 0;
            while (qEnd < qBeg) {
                int curI = qI[qEnd], curJ = qJ[qEnd++];
                for (int i=0; i < 4; i++) {
                    int nextI = curI + dx[i];
                    int nextJ = curJ + dy[i];
                    if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m &&
                            pass[nextI][nextJ] && len[nextI][nextJ] == -1) {
                        len[nextI][nextJ] = len[curI][curJ] + 1;
                        qI[qBeg] = nextI;
                        qJ[qBeg++] = nextJ;
                    }
                }
            }

            if (len[stI][stJ] == -1 || len[stI][stJ] > bestLen)
                return;
            
            int L = len[stI][stJ];
            int[] sz = new int[L+1];
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (len[i][j] != -1 && len[i][j] <= L)
                        sz[len[i][j]]++;
            
            int[][] layerI = new int[L+1][];
            int[][] layerJ = new int[L+1][];
            int[] p = new int[L+1];
            for (int i=0; i<=L; i++) {
                layerI[i] = new int[sz[i]];
                layerJ[i] = new int[sz[i]];
            }
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (len[i][j] != -1 && len[i][j] <= L) {
                        layerI[len[i][j]][p[len[i][j]]] = i;
                        layerJ[len[i][j]][p[len[i][j]]++] = j;
                    }
            
            int[][] pathId = new int[n][m];
            pathId[fnI][fnJ] = 0;
            
            int curPathId = 1;
            
            for (int X=1; X <= L; X++) {
                char[] let = new char[sz[X]];
                int[] next = new int[sz[X]];
                Pair[] pp = new Pair[sz[X]];
                for (int i=0; i < sz[X]; i++) {
                    int curI = layerI[X][i];
                    int curJ = layerJ[X][i];
                    let[i] = map[curI][curJ];
                    next[i] = 1000000;
                    for (int j=0; j < 4; j++) {
                        int nextI = curI + dx[j];
                        int nextJ = curJ + dy[j];
                        if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m && len[nextI][nextJ] == X-1)
                            next[i] = Math.min(next[i], pathId[nextI][nextJ]);
                    }
                    pp[i] = new Pair(curI, curJ, let[i], next[i]);
                }
                Arrays.sort(pp);
                for (int i=0; i < sz[X]; i++)
                    pathId[pp[i].vi][pp[i].vj] = curPathId++; 
            }
            
            StringBuilder sb = new StringBuilder();
            
            int curI = stI, curJ = stJ;
            while (curI != fnI || curJ != fnJ) {
                int minId = 10000, bestDI = -1, bestDJ = -1;
                sb.append(map[curI][curJ]);
                for (int i=0; i < 4; i++) {
                    int nextI = curI + dx[i];
                    int nextJ = curJ + dy[i];
                    if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m && len[nextI][nextJ] == len[curI][curJ] - 1) {
                        if (pathId[nextI][nextJ] < minId) {
                            minId = pathId[nextI][nextJ];
                            bestDI = dx[i];
                            bestDJ = dy[i];
                        }
                    }
                }
                curI += bestDI;
                curJ += bestDJ;
            }
            
            String path = sb.toString();
            
//          for (int i=0; i < n; i++) {
//              for (int j=0; j < m; j++)
//                  System.out.print(pathId[i][j] + " ");
//              System.out.println();
//          }
            
            if (L < bestLen) {
                bestLen = L;
                bestP = path;
            } else if (path.compareTo(bestP) < 0) {
                bestP = path;
            }
            
            return;
        }
        
        go(pos+1, taken);
        can[pos] = true;
        go(pos+1, taken+1);
        can[pos] = false;
    }
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        map = new char[n][m];
        for (int i=0; i<n; i++) {
            String s = sc.next();
            for (int j=0; j<m; j++)
                map[i][j] = s.charAt(j);
        }
        sc.close();
        
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                if (map[i][j] == 'S') {
                    stI = i; stJ = j;
                }
                if (map[i][j] == 'T') {
                    fnI = i; fnJ = j;
                }
            }
        
        can = new boolean[26];
        len = new int[n][m];
        qI = new int[n*m];
        qJ = new int[n*m];
        pass = new boolean[n][m];
        go(0, 0);
        
        if (bestLen == 10000)
            System.out.println(-1);
        else
            System.out.println(bestP.substring(1));
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}