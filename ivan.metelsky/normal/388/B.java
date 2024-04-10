import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemB {
    static int[][] ans;
    static void set(int a, int b) {
        ans[a][b] = ans[b][a] = 1;
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int L = 30;
        ans = new int[3*L+5][3*L+5];
        set(0,3); set(0,4);
        for (int i=0; i < L; i++) {
            set(3*i+3, 3*i+6);
            set(3*i+3, 3*i+7);
            set(3*i+4, 3*i+6);
            set(3*i+4, 3*i+7);
            set(3*i+2, 3*i+5);
        }
        set(3*L+2, 1);
        for (int pw=L-1; pw>=0; pw--) {
            if (k >= (1<<pw)) {
                k -= (1<<pw);
                set(3*pw+3, 3*pw+5);
            }
        }

        int n = 3*L+5;
        StringBuilder sb = new StringBuilder();
        sb.append(n + "\n");
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++)
                sb.append(ans[i][j] == 1 ? 'Y' : 'N');
            sb.append('\n');
        }
        System.out.println(sb.toString());
    }
}