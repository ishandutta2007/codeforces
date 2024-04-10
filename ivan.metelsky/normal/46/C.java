import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        String s = sc.next();
        sc.close();
        
        int cH = 0;
        for (int i=0; i < s.length(); i++)
            if (s.charAt(i) == 'H')
                cH++;
        
        int best = cH;
        
        for (int st=0; st < s.length(); st++) {
            int cur = st;
            int cnt = cH;
            for (int i=0; i < cH; i++) {
                if (s.charAt(cur) == 'H')
                    cnt--;
                cur++;
                if (cur == s.length()) cur = 0;
            }
            best = Math.min(best, cnt);
        }
        
        System.out.println(best);
    }
}