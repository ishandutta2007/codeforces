import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    public void go() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] a = new int[N+1];
        for (int i=0; i < N; i++)
            a[i] = Integer.parseInt(st.nextToken());
        a[N] = 1000000001;
        br.close();
        
        int last = -1000000001;
        long len = 0;
        long res = 0;
        for (int i=0; i < a.length; i++) {
            if (a[i] != last) {
                res += (len * (len + 1)) / 2;
                len = 0;
            }
            last = a[i];
            len++;
        }
        
        System.out.println(res);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}