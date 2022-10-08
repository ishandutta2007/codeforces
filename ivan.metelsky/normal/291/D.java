import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemD {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n+1];
        for (int i=1; i<n; i++) a[i] = 1;
        StringBuilder sb = new StringBuilder();
        for (int step = 0; step < k; step++) {
            int[] c = new int[n+1];
            for (int i=1; i<=n; i++) {
                int maxAdd = (n - i - a[i]);
                int pos = n;
                for (int x = 15; x>=0; x--)
                    if (pos - (1<<x) > 0 && a[pos - (1<<x)] <= maxAdd) pos -= (1<<x);
                c[i] = pos;
            }
            int[] b = new int[n+1];
            for (int i=1; i<=n; i++) b[i] = a[i] + a[c[i]];
            for (int i=1; i<=n; i++) a[i] = b[i];
            for (int i=1; i<=n; i++) {
                sb.append(c[i]);
                if (i<n) sb.append(" "); else sb.append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}