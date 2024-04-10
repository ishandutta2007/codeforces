import java.util.*;
import java.io.*;

public class ProblemE {
    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] A = new int[n][m];
        for (int i=0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j < m; j++)
                A[i][j] = Integer.parseInt(st.nextToken());
        }
        br.close();
        
        long[][] sum = new long[n][m];
        for (int i=0; i < n; i++) {
            long curSum = 0;
            for (int j=0; j < m; j++) {
                curSum += A[i][j];
                sum[i][j] = curSum;
            }
        }
        
        long[][] B = new long[n][m];
        
        for (int j=0; j < m; j++) {
            B[0][j] = sum[0][j];
        }
        
        final long INF = 1000000000000l;
        
        for (int i=1; i < n; i++) {
            if (i % 2 == 0) {
                long best = -INF;
                
                for (int j=0; j < m; j++) {
                    B[i][j] = best + sum[i][j];
                    best = Math.max(best, B[i-1][j]);
                }
            } else {
                long best = -INF;
                
                for (int j=m-1; j >= 0; j--) {
                    B[i][j] = best + sum[i][j];
                    best = Math.max(best, B[i-1][j]);
                }
            }
        }
        
        long ans = -INF;
        for (int j=0; j < m; j++)
            ans = Math.max(ans, B[n-1][j]);
        
        System.out.println(ans);
    }
    
    public static void main(String[] args) throws Exception {
        (new ProblemE()).doMain();
    }
}