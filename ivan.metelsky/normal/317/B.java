import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ProblemB {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        int SZ = 70;
        int[][] cur = new int[SZ+1][SZ+1];
        int[][] next = new int[SZ+1][SZ+1];
        cur[0][0] = n;
        boolean upd = true;
        int max = 0;
        while (upd) {
            upd = false;
            for (int i=0; i<=max; i++) for (int j=0; j<=max; j++)
                next[i][j] = cur[i][j];
            for (int i=0; i<=max; i++) for (int j=0; j<=max; j++)
                if (cur[i][j] >= 4) {
                    next[i][j] -= 4;
                    if (i > 1) next[i-1][j]++; else if (i == 1) next[i-1][j] += 2;
                    next[i+1][j]++;
                    if (j > 1) next[i][j-1]++; else if (j == 1) next[i][j-1] += 2;
                    next[i][j+1]++;
                    upd = true;
                    if (i == max || j == max) max++;
                }
            for (int i=0; i<=max; i++) for (int j=0; j<=max; j++)
                cur[i][j] = next[i][j];
        }
        StringBuilder ans = new StringBuilder();
        for (int x = 0; x < t; x++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            a = Math.abs(a); b = Math.abs(b);
            if (a > SZ || b > SZ) {
                ans.append(0).append("\n");
            } else {
                ans.append(cur[a][b]).append("\n");
            }
        }
        br.close();
        System.out.println(ans);
    }
}