import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CDF_D {
    public static void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] prob = new int[n][m];
        for (int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<m; j++)
                prob[i][j] = Integer.parseInt(st.nextToken());
        }
        br.close();

        final double BND = 1e-20;

        int[] maxShirts = new int[m];
        double[][] gain = new double[m][];

        for (int kind=0; kind<m; kind++) {
            double[] cur = new double[n + 1];

            cur[0] = 1.0;
            int max = 0;

            for (int eng=0; eng < n; eng++) {
                double p = prob[eng][kind] / 1000.0;
                cur[max + 1] = cur[max] * p;
                for (int i=max; i > 0; i--) {
                    cur[i] = cur[i] * (1 - p) + cur[i-1] * p;
                }
                cur[0] = cur[0] * (1 - p);
                if (cur[max + 1] > BND) max++;
            }

            maxShirts[kind] = max;
            gain[kind] = new double[max + 1];

            double curGain = 0.0;
            double remProb = 1.0;
            for (int i=0; i <= max; i++) {
                curGain += i * cur[i];
                remProb -= cur[i];
                gain[kind][i] = curGain + remProb * i;
            }
        }

        double[][] dp = new double[m + 1][n + 1];
        for (int kind=0; kind < m; kind++)
            for (int have=0; have <= n; have++)
                for (int next=0; next <= maxShirts[kind] && have + next <= n; next++)
                    dp[kind + 1][have + next] = Math.max(dp[kind + 1][have + next], dp[kind][have] + gain[kind][next]);

        System.out.println(dp[m][n]);
    }

    public static void main(String[] args) throws Exception {
        new CDF_D().doMain();
    }
}