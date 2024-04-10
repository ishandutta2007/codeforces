import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Codeforces {
   
   static Scanner input;
   public static final int maxn = 100 * 1000 + 1;
   
   public static void main(String args[])
   {
   		input = new Scanner(System.in);

   		long[] dp = new long[maxn];
   		int[] cnt = new int[maxn];
   		int[] a = new int[maxn];

   		int n = input.nextInt();

   		for (int i = 0; i < n; i++){
   			int cur = input.nextInt();
   			cnt[cur]++;
   		}

   		dp[1] = cnt[1];
   		dp[0] = 0;

   		for (int i = 2; i < maxn; i++){
   			dp[i] = Math.max(dp[i - 1], (long)dp[i - 2] + (long)cnt[i] * i);
   		}

   		System.out.println(dp[maxn - 1]);
   }
}