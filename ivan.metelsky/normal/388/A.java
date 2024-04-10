import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int[] x = new int[n];
        for (int i = 0; i < n; i++) x[i] = sc.nextInt();

        Arrays.sort(x);

        for (int ans = 1; ; ans++) {
            boolean ok = true;
            for (int i=0; i<n; i++)
                if (x[i] < i / ans) ok = false;
            if (ok) {
                System.out.println(ans);
                break;
            }
        }
    }
}