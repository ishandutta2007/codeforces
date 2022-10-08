import java.util.*;
import java.io.*;

public class Solution {
    boolean allFalse(boolean[] a) {
        for (boolean v : a) if (v) return false;
        return true;
    }
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int ourPos = sc.nextInt() - 1;
        int hisPos = sc.nextInt() - 1;
        
        String s = sc.next() + " " + sc.next();
        int hisDir = s.equals("to head") ? -1 : 1;
        
        s = sc.next();
        
        sc.close();
        
        boolean[] cur = new boolean[n];
        cur[ourPos] = true;
        
        for (int t = 0; t < s.length(); t++) {
            if (s.charAt(t) == '0') {
                boolean[] next = new boolean[n];
                for (int i=0; i < n; i++)
                    if (cur[i]) {
                        next[i] = true;
                        if (i+1 < n) next[i+1] = true;
                        if (i-1 >= 0) next[i-1] = true;
                    }
                next[hisPos] = false;
                if (hisPos + hisDir >= 0 && hisPos + hisDir < n) {
                    hisPos += hisDir;
                } else {
                    hisPos -= hisDir;
                    hisDir *= -1;
                }
                next[hisPos] = false;
                if (allFalse(next)) {
                    System.out.println("Controller " + (t + 1));
                    System.exit(0);
                }
                for (int i=0; i<n; i++)
                    cur[i] = next[i];
            } else {
                if (hisPos + hisDir >= 0 && hisPos + hisDir < n) {
                    hisPos += hisDir;
                } else {
                    hisPos -= hisDir;
                    hisDir *= -1;
                }
                Arrays.fill(cur, true);
                cur[hisPos] = false;
            }
        }
        
        System.out.println("Stowaway");
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}