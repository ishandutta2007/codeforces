import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class OracAndModels {
    private static final int N = 1_00_001;
    private static final List<List<Integer>> indexDivisorList = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        populateIndexDivisorList();
        final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int q = Integer.parseInt(br.readLine());
        while (q-- > 0) {
            final int n = Integer.parseInt(br.readLine());
            final Integer[] s = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .boxed()
                    .toArray(Integer[]::new);
            final int[] dp = new int[n + 1];
            Arrays.fill(dp, 1);
            for (int i = 2; i <= s.length; i++) {
                for (int div : indexDivisorList.get(i)) {
                    if (s[i - 1] > s[div - 1])
                        dp[i] = Math.max(dp[i], dp[div] + 1);
                }
            }
            int max = Arrays.stream(dp).max().orElse(Integer.MAX_VALUE);
            System.out.println(max);
        }
    }

    private static void populateIndexDivisorList() {
        indexDivisorList.add(new ArrayList<>()); // for index 0;
        indexDivisorList.add(new ArrayList<>()); // for index 1;
        for (int i = 2; i < N; i++) {
            indexDivisorList.add(new ArrayList<>());
            for (int j = 1; j <= (int) Math.sqrt(i); j++) {
                if (i % j == 0) {
                    indexDivisorList.get(i).add(j);
                    if (j * j != i) {
                        indexDivisorList.get(i).add(i / j);
                    }
                }
            }
        }
    }
}