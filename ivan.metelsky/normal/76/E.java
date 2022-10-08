import java.util.*;
import java.io.*;

public class Solution {
    long calc(long[] X) {
        long sumSq = 0, sum = 0;
        for (int i=0; i < X.length; i++) {
            sumSq += X[i] * X[i];
            sum += X[i];
        }
        return (long)X.length * sumSq - sum * sum;
    }
    
    public void go() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] X = new long[N];
        long[] Y = new long[N];
        for (int i=0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            X[i] = Integer.parseInt(st.nextToken());
            Y[i] = Integer.parseInt(st.nextToken());
        }
        br.close();
        
        System.out.println(calc(X) + calc(Y));
    }
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}