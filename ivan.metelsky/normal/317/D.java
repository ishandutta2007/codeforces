import java.io.InputStreamReader;
import java.util.*;

public class ProblemD {
    static Map<Integer, Integer> memo = new HashMap<Integer, Integer>();

    static int grundy(int mask) {
        if (mask == 0) return 0;
        if (memo.containsKey(mask)) return memo.get(mask);
        boolean[] have = new boolean[31];
        for (int i=1; i<=30; i++) if ((mask & (1<<(i-1))) != 0) {
            int nmask = mask;
            for (int j=i; j<=30; j+=i) if ((nmask & (1<<(j-1))) != 0) nmask ^= (1<<(j-1));
            have[grundy(nmask)] = true;
        }
        int ans = 0;
        while (have[ans]) ans++;
        memo.put(mask, ans);
        return ans;
    }

    static long pow(long a, long b) {
        long ans = 1;
        for (int i=0; i<b; i++) ans *= a;
        return ans;
    }

    public static void main(String[] args) throws Exception {
        final int[] grundy = new int[] {
                1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12
        };
        /*int mask = 1;
        for (int i=1; i<=29; i++) {
            System.out.print(grundy(mask)+",");
            mask = 2 * mask + 1;
        }*/
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        long last = 1;
        int xor = 0;
        Set<Long> powers = new HashSet<Long>();
        for (int pw=29; pw>=2; pw--) {
            long cur = last + 1;
            long atLevel = 0;
            while (pow(cur, pw) <= n && pow(cur, pw+1) > n) {
                if (!powers.contains(cur)) {
                    atLevel++;
                    long tmp = cur;
                    for (int i=0; i<pw; i++) {
                        powers.add(tmp);
                        tmp *= cur;
                    }
                }
                cur++;
            }
            if (atLevel % 2 == 1)
                xor ^= grundy[pw-1];
            last = cur - 1;
        }
        long rem = n - powers.size();
        if (rem % 2 == 1) xor ^= grundy[0];
        sc.close();
        System.out.println(xor > 0 ? "Vasya" : "Petya");
    }
}