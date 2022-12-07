import java.util.*;
import static java.lang.Math.*;

public class SolutionD {
    static long fast_pow(long a, long b) {
        if(b == 0)
            return 1L;
        long val = fast_pow(a, b / 2);
        if(b % 2 == 0)
            return val * val % mod;
        else
            return val * val % mod * a % mod;
    }
    static void solve(int lvl, int maxlvl, int[] primes, long baseVal, long curVal, long m, int parity) {
        if(lvl == maxlvl) {
            long poss = m / (baseVal * curVal);
            if(parity == 0)
                cnt += poss;
            else
                cnt -= poss;

            return;
        }

        solve(lvl + 1, maxlvl, primes, baseVal, curVal, m, parity);
        solve(lvl + 1, maxlvl, primes, baseVal, curVal * primes[lvl], m, parity ^ 1);
    }
    static long cnt = 0;
    static long mod = (long)1e9 + 7;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();

        int primes[][] = new int[m + 1][6];
        int ptr[] = new int[m + 1];

        for(int i = 2; i <= m; ++i) {
            if(ptr[i] == 0) {
                for(int j = i; j <= m; j += i) {
                    primes[j][ptr[j]++] = i; 
                }
            }
        }

        long prob[] = new long[m + 1];
        long ans[] = new long[m + 1];
        ans[0] = 0;
        prob[0] = 1;
        long invm = fast_pow(m, mod - 2);
        for(int i = m; i >= 2; --i) {
            long multiples = m / i;
            long mminv = fast_pow(m - multiples, mod - 2);
            prob[i] = mminv;
            long num = m;
            long den = (m - multiples) * (m - multiples) % mod;
            long deninv = fast_pow(den, mod - 2);
            ans[i] = num * deninv % mod;

            for(int j = 2 * i; j <= m; j += i) {
                int val = j / i;
                cnt = 0;
                solve(0, ptr[val], primes[val], i, 1, m, 0);
                long curProb = cnt * mminv % mod;
                num = m * cnt % mod;
                long curEv = (num * deninv % mod * fast_pow(curProb, mod - 2) % mod + ans[j] % mod) % mod; 
                curProb = curProb * prob[j] % mod;
                ans[i] += curEv * curProb % mod;
                prob[i] += curProb;
            }

            prob[i] %= mod;
            ans[i] %= mod;
            ans[i] = ans[i] * fast_pow(prob[i], mod - 2) % mod;
        }

        long fans = 0;
        long fprob = invm;
        for(int i = 2; i <= m; ++i) {
            int val = i;
            cnt = 0;
            solve(0, ptr[val], primes[val], 1, 1, m, 0);
            long curProb = prob[i] * cnt % mod * invm % mod;
            fans += curProb * ans[i] % mod;
            fprob += curProb;
        }
        fans %= mod;
        fprob %= mod;

        fans = (fans * fast_pow(fprob, mod - 2) % mod + 1L) % mod;

        System.out.print(fans);
    }   
}