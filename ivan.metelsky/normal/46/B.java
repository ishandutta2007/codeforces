import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int[] cnt = new int[5];
        for (int i=0; i<5; i++)
            cnt[i] = sc.nextInt();
        int N = sc.nextInt();
        String[] kinds = new String[] {"S", "M", "L", "XL", "XXL"};
        for (int i=0; i < N; i++) {
            String s = sc.next();
            int wantId = -1;
            for (int j=0; j < 5; j++)
                if (kinds[j].equals(s)) wantId = j;
            int bestDist = Integer.MAX_VALUE;
            int bestId = -1;
            for (int j=0; j < 5; j++) {
                if (cnt[j] == 0) continue;
                if (Math.abs(j - wantId) < bestDist ||
                    Math.abs(j - wantId) == bestDist && j > bestId) {
                    bestId = j;
                    bestDist = Math.abs(j - wantId);
                }
            }
            System.out.println(kinds[bestId]);
            cnt[bestId]--;
        }
        sc.close();
    }
}