import java.io.*;
import java.util.*;

public class CDF_B {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int m = sc.nextInt();
        long[] x = new long[m];
        long[] y = new long[m];
        for (int i=0; i<m; i++) {
            x[i] = sc.nextLong();
            y[i] = sc.nextLong();
        }
        sc.close();

        long[] max = new long[n+1];

        Arrays.fill(max, 1);

        for (int i=0; i<m; i++) for (int j=i+1; j<m; j++) {
            long A = y[j] - y[i];
            if (A == 0) continue;
            long B = x[i] - x[j];
            long C = -A * x[i] - B * y[i];
            long pp = - C / A;
            if (pp * A != (-C)) continue;
            if (pp < 1 || pp > n) continue;
            int pos = (int)pp;
            int cnt = 0;
            for (int k=0; k<m; k++)
                if (A * x[k] + B * y[k] + C == 0)
                    cnt++;
            max[pos] = Math.max(max[pos], cnt);
        }

        long res = 0;
        for (int i=1; i <= n; i++)
            res += max[i];

        System.out.println(res);
    }
}