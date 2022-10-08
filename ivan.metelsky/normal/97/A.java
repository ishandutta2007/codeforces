import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    InputStreamReader inp = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(inp);
    Scanner sc = new Scanner(inp);
    
    // input data
    int[] cnt = new int[28];
    int[] x1 = new int[28];
    int[] y1 = new int[28];
    int[] x2 = new int[28];
    int[] y2 = new int[28];
    
    int sqCnt = 0;
    int[][] sqId;
    
    int n, m;
    
    boolean[][] have;
    
    void inputData() {
        n = sc.nextInt();
        m = sc.nextInt();
        String[] map = new String[n];
        for (int i=0; i<n; i++)
            map[i] = sc.next();
        have = new boolean[n][m];
        sqId = new int[n][m];
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                have[i][j] = map[i].charAt(j) != '.';
                if (have[i][j]) {
                    char c = map[i].charAt(j);
                    int id = -1;
                    if (c=='A') id = 26; else if (c=='B') id = 27;
                    else id = c-'a';
                    cnt[id]++;
                    if (cnt[id] == 1) {
                        x1[id] = i; y1[id] = j;
                    } else {
                        x2[id] = i; y2[id] = j;
                    }
                }
            }
        
        for (int i=0; i<n; i++)
            Arrays.fill(sqId[i], -1);
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (have[i][j] && sqId[i][j] == -1) {
                    sqId[i][j] = sqCnt;
                    sqId[i+1][j] = sqCnt;
                    sqId[i][j+1] = sqCnt;
                    sqId[i+1][j+1] = sqCnt++;
                }
    }

    // intermediate

    int res = 0;
    
    int[] cntColor = new int[7];
    int[] colorForSq = new int[14];
    
    char[][] sol;
    
    void go(int pos, int nextColor) {
        if (pos==14) {
            boolean[][] memo = new boolean[7][7];
            for (int i=0; i<28; i++) {
                int ca = colorForSq[sqId[x1[i]][y1[i]]];
                int cb = colorForSq[sqId[x2[i]][y2[i]]];
                if (ca<cb) {int tmp=ca; ca=cb; cb=tmp;}
                if (memo[ca][cb])
                    return;
                memo[ca][cb] = true;
            }
            res++;
            if (res==1) {
                sol = new char[n][m];
                for (int i=0; i<n; i++)
                    for (int j=0; j<m; j++)
                        if (have[i][j]) {
                            sol[i][j] = (char)('0'+colorForSq[sqId[i][j]]);
                        } else sol[i][j] = '.';
            }
            return;
        }
        for (int i=0; i < nextColor; i++)
            if (cntColor[i] < 2) {
                colorForSq[pos] = i;
                cntColor[i]++;
                go(pos+1, nextColor);
                cntColor[i]--;
            }
        if (nextColor < 7) {
            colorForSq[pos] = nextColor;
            cntColor[nextColor]++;
            go(pos+1, nextColor+1);
            cntColor[nextColor]--;
        }
    }
    
    void solve() {
        go(0, 0);
    }
    
    // output data
    
    void writeData() {
        System.out.println(5040 * res);
        for (int i=0; i<n; i++)
            System.out.println(new String(sol[i]));
    }
        
    // ================================================== //
    
    void solveAlternative() {
    }
    
    // ================================================== //
    
    static void solveTask() throws Exception {
        Solution sol = new Solution();
        sol.inputData();
        sol.solve();
        sol.writeData();
    }
    
    static void stressTest() {
        Random rnd = new Random();
        int it = 0;
        while (true) {
            it++;
            System.out.println("testing case #" + it);
            
            Solution sol = new Solution();
            
            // generate test case
            
            Solution sol1 = new Solution();
            
            // copy test case
            
            sol.solve();
            sol1.solveAlternative();
            
            // compare answers
        }
    }
    
    public static void main(String[] args) throws Exception {
        solveTask();
        // stressTest()
    }
}