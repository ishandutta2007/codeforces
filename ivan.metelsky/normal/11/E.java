import java.io.*;

public class Solution {
    public long solve(String s) {
        StringBuffer sb = new StringBuffer();
        for (int i=0; i < s.length(); i++) {
            sb.append(s.charAt(i));
            if (i+1<s.length() && s.charAt(i)==s.charAt(i+1) && s.charAt(i)!='X') sb.append('X');
        }
        
        s = sb.toString();
        
//       try odd length
        long finalLen = s.length();
        long good = 0;
        for (int i=0; i<s.length(); i++)
            if (s.charAt(i)!='X') good++;

        if (finalLen%2==0) finalLen++;
        
        long ans1 = (100000000l * good) / (2 * finalLen);
        
        sb = new StringBuffer();
        
        int posMod2 = 0;
        for (int i=0; i < s.length(); i++) {
            if (s.charAt(i) == 'X') {posMod2=1-posMod2; sb.append('X'); continue;}
            if (s.charAt(i) == 'L' && posMod2 == 1 || s.charAt(i) == 'R' && posMod2 == 0) {
                sb.append('Y'); posMod2=1-posMod2;
            }
            posMod2=1-posMod2; sb.append(s.charAt(i));
        }
        
        s = sb.toString();
        if (s.length() % 2 != 0) s += "Y";
                
        good = 0;
        long len = s.length();
        for (int i=0; i<s.length(); i++) if (s.charAt(i)!='X'&&s.charAt(i)!='Y') good++;
        
        long ans2 = 100000000l * good / len;
        
        for (int i=0; i < s.length(); i++) if (s.charAt(i)=='Y') {
            int cnt=0;
            int j = i + 1;
            while (j < s.length() && s.charAt(j) != 'Y') {
                if (s.charAt(j) == 'L' || s.charAt(j) == 'R') cnt++;
                j++;
            }
            if (j < s.length() && s.charAt(j) == 'Y' && cnt == 1 && (good-1)*len > good*(len-2)) {
                i = j;
                good--;
                len -= 2;
                ans2 = 100000000l * good / len;
            }
        }
        
        // output
        long best = Math.max(ans1,ans2);
        return best;
    }
    
    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        br.close();
        
        long res = 0;
                
        if (s.length()>1 && s.charAt(s.length()-1) == s.charAt(0) && s.charAt(0) != 'X') {
            res = Math.max(solve(s+"X"), solve("X"+s));
        } else res = solve(s);
        
        long best = res;
        System.out.print(best/1000000l);
        best %= 1000000l;
        System.out.print(".");
        String tt = ""+best;
        while (tt.length()<6) tt = "0"+tt;
        System.out.println(tt);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}