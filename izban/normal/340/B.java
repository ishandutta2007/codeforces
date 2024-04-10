import java.util.*;


public class Main {

    final int maxn = 1 << 17;

    int n;
    int x[] = new int[maxn], y[] = new int[maxn];

    public void Run() {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }

        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double A = y[i] - y[j];
                double B = x[j] - x[i];
                double C = -A * x[i] - B * y[i];
                double d = Math.sqrt(A * A + B * B);
                A /= d; B /= d; C /= d;
                d = Math.sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) / 2.0;

                double a1 = -1, a2 = -1;
                for (int k = 0; k < n; k++) if (k != i && k != j) {
                    if (A * x[k] + B * y[k] + C > 0) {
                        a1 = Math.max(a1, (A * x[k] + B * y[k] + C) * d);
                    }
                    if (A * x[k] + B * y[k] + C < 0) {
                        a2 = Math.max(a2, -(A * x[k] + B * y[k] + C) * d);
                    }
                }
                if (a1 > 0 && a2 > 0) ans = Math.max(ans, a1 + a2);
            }
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}