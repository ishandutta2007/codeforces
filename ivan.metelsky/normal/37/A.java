import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    void main() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        
        int N = sc.nextInt();
        int[] cnt = new int[1001];
        for (int i=0; i < N; i++) {
            int x = sc.nextInt();
            cnt[x]++;
        }
        
        int max = 0;
        for (int i=0; i < cnt.length; i++) max = Math.max(max, cnt[i]);
        
        int tot = 0;
        for (int i=0; i < cnt.length; i++) if (cnt[i]>0) tot++;
        
        System.out.println(max+" "+tot);
        
        sc.close();
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).main();
    }
}