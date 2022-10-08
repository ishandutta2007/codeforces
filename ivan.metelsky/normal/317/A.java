import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemA {
    static long solve(long x, long y, long m) {
        long ans = 0;
        if (x>y) {long tmp = x; x = y; y = tmp;}
        if (x >= m || y >= m) return 0;
        if (x <= 0 && y <= 0) return -1;
        if (x < 0) {
            ans += (-x) / y;
            x += ans * y;
        }
        while (x < m && y < m) {
            long s = x + y;
            if (x<y) x = s; else y = s;
            ans++;
        }
        return ans;
    }

    static long solve2(long x, long y, long m) {
        for (int i=0; ; i++) {
            if (x > m || y > m) return i;
            long s = x + y;
            if (s <= x && s <= y) return -1;
            if (x<y) x = s; else y = s;
        }
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        long x = sc.nextLong(), y = sc.nextLong(), m = sc.nextLong();
        sc.close();
        System.out.println(solve(x, y, m));

        /*long best = -1;
        final int MAX = 100;
        for (int x=-MAX; x<=MAX; x++)
            for (int y=-MAX; y<=MAX; y++)
                for (int m=-MAX; m<=MAX; m++) {
                    long ans = solve(x, y, m);
                    if (ans>best) {
                        best = ans;
                        System.out.println(x+" "+y+" "+m+" "+ans);
                    }
                }*/

        //System.out.println(best);
        // solve(-100, 1, 90);
    }
}