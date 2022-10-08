import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemB {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] f = new int[n];
        for (int i = 0; i < n; i++) {
            f[i] = sc.nextInt();
        }
        Arrays.sort(f);
        int ans = 0;
        for (int p = n - 1; p >= 0; p -= k) {
            ans += 2 * (f[p] - 1);
        }
        System.out.println(ans);
    }
}