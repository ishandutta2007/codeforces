import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ProblemE {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[][] A = new int[n][n];
        for (int i=0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j < n; j++)
                A[i][j] = Integer.parseInt(st.nextToken());
        }
        br.close();

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i>0) A[i][j] += A[i-1][j];
                if (j>0) A[i][j] += A[i][j-1];
                if (i>0 && j>0) A[i][j] -= A[i-1][j-1];
            }
        }

        int[][] cost = new int[n][n];
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++) {
                cost[i][j] = A[j][j];
                if (i > 0) {
                    cost[i][j] -= A[i-1][j];
                    cost[i][j] -= A[j][i-1];
                    cost[i][j] += A[i-1][i-1];
                }
                cost[i][j] >>= 1;
            }

        int[] cur = new int[n+1];
        cur[0] = 0;
        for (int i=1; i<=n; i++) cur[i] = cost[0][i-1];
        k--;

        while (k > 0) {
            k--;
            int[] next = new int[n+1];
            next[0] = 0;
            int last = 0;
            for (int i=1; i<=n; i++) {
                next[i] = cur[last] + cost[last][i-1];
                for (int j=last + 1; j < i && j <= last + 50; j++) {
                    int tmp = cur[j] + cost[j][i-1];
                    if (next[i] > tmp) {
                        next[i] = tmp;
                        last = j;
                    }
                }
            }
            for (int i=0; i<=n; i++) cur[i] = next[i];
        }

        System.out.println(cur[n]);
    }
}