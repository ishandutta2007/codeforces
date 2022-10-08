import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemA {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        long a = sc.nextInt();
        long b = sc.nextInt();
        String s = sc.next();
        sc.close();

        int N = s.length();
        long[] baseX = new long[N];
        long[] baseY = new long[N];
        int curX = 0, curY = 0;
        for (int i=0; i<N; i++) {
            baseX[i] = curX; baseY[i] = curY;
            if (s.charAt(i) == 'U') curY++;
            else if (s.charAt(i) == 'D') curY--;
            else if (s.charAt(i) == 'R') curX++;
            else if (s.charAt(i) == 'L') curX--;
        }

        int totX = curX, totY = curY;
        boolean ok = false;
        for (int i=0; i < N; i++) {
            // baseX[i] + t * totX = a
            // baseY[i] + t * totY = b
            if (totX == 0 && totY == 0) {
                ok |= (baseX[i] == a && baseY[i] == b);
            } else if (totX == 0) {
                ok |= (baseX[i] == a && (b - baseY[i]) % totY == 0 && (b - baseY[i]) / totY >= 0);
            } else if (totY == 0) {
                ok |= (baseY[i] == b && (a - baseX[i]) % totX == 0 && (a - baseX[i]) / totX >= 0);
            } else {
                ok |= ((a - baseX[i]) % totX == 0 && (b - baseY[i]) % totY == 0 && (a - baseX[i]) / totX == (b - baseY[i]) / totY && (a - baseX[i]) / totX >= 0);
            }
        }

        System.out.println(ok ? "Yes" : "No");
    }
}