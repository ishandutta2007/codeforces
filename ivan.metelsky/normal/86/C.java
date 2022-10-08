import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    final String ALPH = "ACGT";
    
    int n, m;
    String[] s;
    int suffCnt = 0;
    String[] suff = new String[500];
    Map<String, Integer> suffId = new HashMap<String, Integer>();
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        n = sc.nextInt();
        m = sc.nextInt();
        s = new String[m];
        for (int i=0; i < s.length; i++)
            s[i] = sc.next();
        sc.close();
        
        for (int i=0; i < m; i++)
            for (int j=0; j <= s[i].length(); j++) {
                String pref = s[i].substring(0, j);
                if (!suffId.containsKey(pref)) {
                    suff[suffCnt] = pref;
                    suffId.put(pref, suffCnt++);
                }
            }
        
        int[][] nextSuff = new int[suffCnt][4];
        for (int i=0; i < suffCnt; i++)
            for (int j=0; j < 4; j++) {
                String have = suff[i] + (char)ALPH.charAt(j);
                while (!suffId.containsKey(have))
                    have = have.substring(1);
                nextSuff[i][j] = suffId.get(have);
            }
        
        int[] maxComplete = new int[suffCnt];
        for (int i=0; i < suffCnt; i++) {
            maxComplete[i] = -1;
            for (int j=0; j < m; j++)
                if (suff[i].endsWith(s[j]))
                    maxComplete[i] = Math.max(maxComplete[i], s[j].length());
        }
        
        int[][] cur = new int[suffCnt][11];
        cur[suffId.get("")][0] = 1;
        
        final int MOD = 1000000009;
        
        for (int pos = 1; pos <= n; pos++) {
            int[][] next = new int[suffCnt][11];
            for (int i=0; i < suffCnt; i++)
                for (int j=0; j <= 10; j++)
                    for (int k=0; k < 4; k++) {
                        int ni = nextSuff[i][k];
                        int nj = j+1;
                        if (maxComplete[ni] >= j+1)
                            nj = 0;
                        if (nj == 11) continue;
                        next[ni][nj] += cur[i][j];
                        while (next[ni][nj] >= MOD) next[ni][nj] -= MOD;
                    }
            for (int i=0; i < next.length; i++)
                for (int j=0; j < next[i].length; j++)
                    cur[i][j] = next[i][j];
        }
        
        int res = 0;
        for (int i=0; i < suffCnt; i++) {
            res += cur[i][0];
            while (res >= MOD) res -= MOD;
        }
        
        System.out.println(res);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}