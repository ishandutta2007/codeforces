import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = Integer.parseInt(br.readLine());
        String[] bad = new String[n];
        for (int i=0; i<n; i++)
            bad[i] = br.readLine();
        
        int maxLen = -1, bestPos = -1;
        
        int fn = s.length() - 1;
        
        for (int st = s.length() - 1; st >= 0; st--) {
            for (int i=0; i < n; i++) {
                if (st + bad[i].length() > s.length())
                    continue;
                boolean ok = true;
                for (int a = st, b = 0; b < bad[i].length(); a++, b++)
                    if (bad[i].charAt(b) != s.charAt(a)) {
                        ok = false;
                        break;
                    }
                if (ok) fn = Math.min(fn, st + bad[i].length() - 2);
            }
            if (fn - st + 1 > maxLen) {
                maxLen = fn - st + 1;
                bestPos = st;
            }
        }
        
        System.out.println(maxLen + " " + bestPos);
        
        br.close();
    }
}