import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
    public long faster(String a, String b) {
        int n = a.length();
        int m = b.length();

        int[][][] count = new int[3][3][n+1];

        for (int c1=0; c1<3; c1++)
            for (int c2=0; c2<3; c2++) {
                if (c1 == c2) continue;
                count[c1][c2][0] = 0;
                int S = 0;
                char cc1 = "RGB".charAt(c1);
                char cc2 = "RGB".charAt(c2);
                for (int i=0; i+1 < n; i++) {
                    if (a.charAt(i) == cc1 && a.charAt(i+1) == cc2) {
                        S++;
                    }
                    count[c1][c2][i+1] = S;
                }
            }

        int[] minRow = new int[m];
        int[] maxRow = new int[m];
        long ans = 0;
        for (int i=0; i<m; i++) {
            if (i == 0) {
                minRow[i] = maxRow[i] = 0;
            } else {
                minRow[i] = minRow[i-1] + (a.charAt(minRow[i-1]) == b.charAt(i-1) ? 1 : 0);
                maxRow[i] = maxRow[i-1] + (a.charAt(maxRow[i-1]) == b.charAt(i-1) ? 1 : 0);
                if (minRow[i] >= n) break;
                if (maxRow[i] >= n) {
                    if (n == 1) break;
                    maxRow[i]--;
                    if (b.charAt(i-1) != b.charAt(i) && b.charAt(i-1) == a.charAt(n-1) && b.charAt(i) == a.charAt(n-2)) {
                        maxRow[i]--;
                    }
                }
            }
            while (a.charAt(maxRow[i]) != b.charAt(i) && maxRow[i] + 1 < n) maxRow[i]++;
            ans += maxRow[i] - minRow[i] + 1;
            if (i>0 && b.charAt(i-1) != b.charAt(i)) {
                char A = b.charAt(i-1);
                char B = b.charAt(i);
                int AA = (A == 'R' ? 0 : (A == 'G' ? 1 : 2));
                int BB = (B == 'R' ? 0 : (B == 'G' ? 1 : 2));
                if (minRow[i] <= maxRow[i]-2) {
                    ans -= count[BB][AA][maxRow[i]-1] - count[BB][AA][minRow[i]];
                }
            }
        }
        return ans;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a = br.readLine();
        String b = br.readLine();
        br.close();

        System.out.println(new Solution().faster(a, b));
    }
}