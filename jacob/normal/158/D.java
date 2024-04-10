import java.util.*;

public class Program {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] w = new int[N];
        for (int i = 0; i < N; i++)
            w[i] = in.nextInt();
        int res = -100000000;
        for (int i = 1; i <= N/3; i++) {
            if (N % i != 0)
                continue;
            for (int j = 0; j < i; j++) {
                int cr = 0;
                for (int k = j; k < N; k += i) {
                    cr += w[k];
                }
                res = Math.max(res, cr);
            }
        }
        System.out.println(res);
    }

}