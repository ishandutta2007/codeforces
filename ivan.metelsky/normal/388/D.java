import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.Scanner;

public class ProblemD {
    static final long MOD = 1000000007;
    static long[][] C;
    static int k;

    static long make0(int len) {
        if (len == 0) return 1;
        return 1L << (len-1);
    }

    static long make1(int len) {
        if (len == 0) return 0;
        return 1L << (len-1);
    }

    static long[][][] memo;

    static long solve(int bitPos, int used, int lessFlag) {
        if (bitPos < 0) return 1;
        if (memo[bitPos][used][lessFlag] != -1) return memo[bitPos][used][lessFlag];

        int have = (k & (1<<bitPos)) > 0 ? 1 : 0;

        long ans = 0;

        ans += make0(used) * solve(bitPos - 1, used, have == 1 ? 1 : lessFlag);
        ans %= MOD;

        if (have == 1 || lessFlag == 1) {
            ans += make1(used) * solve(bitPos - 1, used, lessFlag);
            ans %= MOD;

            ans += solve(bitPos - 1, used + 1, lessFlag);
            ans %= MOD;
        }

        memo[bitPos][used][lessFlag] = ans;

        return ans;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        k = sc.nextInt();

        memo = new long[30][30][2];
        for (int i=0; i<30; i++) for (int j=0; j<30; j++) memo[i][j][0] = memo[i][j][1] = -1;
        System.out.println(solve(29, 0, 0));
    }
}