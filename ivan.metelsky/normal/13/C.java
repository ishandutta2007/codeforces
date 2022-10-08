import java.util.*;

public class Solution {
    public void doMain() throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] a = new int[N];
        for (int i=0; i<N; i++)
            a[i] = sc.nextInt();
        sc.close();
        
        int[] b = a.clone();
        Arrays.sort(b);
        
        //long[][] F = new long[N][N];
        
        long[] cur = new long[N];
        long[] next = new long[N];
        
        cur[0] = Math.abs(a[0] - b[0]);
        for (int i=1; i<N; i++)
            cur[i] = Math.min(cur[i-1], Math.abs(a[0] - b[i]));
        
        for (int i=1; i<N; i++) {
            next[0] = Math.abs(a[i] - b[0]) + cur[0];
            for (int j=1; j<N; j++)
                next[j] = Math.min(next[j-1], Math.abs(a[i] - b[j]) + cur[j]);
            for (int j=0; j<N; j++) cur[j] = next[j];
        }
        
        //System.out.println(F[0][3]);
        
        System.out.println(cur[N-1]);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}