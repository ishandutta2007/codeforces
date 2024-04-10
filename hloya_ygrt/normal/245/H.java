import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Main {
   

   public static final int maxn = 5000 + 5;
   
   static boolean[][] isPalindrome;
   static int[][] dp;
   static String string;
   
   static BufferedReader in;
   static StringTokenizer st;
   static PrintWriter out;

   static  int nextInt() throws IOException
   {
   		return Integer.parseInt(nextToken());
   }

   static  String nextString() throws IOException
   {
   		return in.readLine();
   }

   public static void main(String args[]) throws IOException
   {	
   		in = new BufferedReader(new InputStreamReader(System.in));
   		out = new PrintWriter(new OutputStreamWriter(System.out));
      
   		dp = new int[maxn][maxn];
   		isPalindrome = new boolean[maxn][maxn];

   		string = nextString();
   		findAllPalindomes();
   		calcDp();

   		int q = nextInt();

   		for (int i = 0; i < q; i++){
   			int l, r;
   				l = nextInt() - 1;
   				r = nextInt() - 1;
   			out.println(dp[l][r]);
   		}
   		out.flush();
   }

   static String nextToken() throws IOException
   {
   		while (st == null || !st.hasMoreTokens()) {
   			st = new StringTokenizer(in.readLine());
   		}
   		return st.nextToken();
   }
   static void findAllPalindomes()
   {
   		for (int length = 1; length <= string.length(); length++){
   			for (int l = 0; l < string.length(); l++){
   				int r = l + length - 1;
   				if (r >= string.length())
   					continue;
   				isPalindrome[l][r] = (string.charAt(l) == 
   					string.charAt(r)) && ( (l + 1 > r - 1) || isPalindrome[l + 1][r - 1]);
   			}
   		}
   }

   static void calcDp() {
   		 for (int length = 1; length <= string.length(); length++){
   		 	for (int l = 0; l < string.length(); l++){
   		 		int r = l + length - 1;
   		 		if (r >= string.length())
   		 			continue;
   		 		if (l == r){
   		 			dp[l][r] = 1;
   		 			continue;
   		 		}

   		 		if (l + 1 == r){
   		 			dp[l][r] = bToInt(isPalindrome[l][r]) + 2;
   		 			continue;
   		 		}

   		 		dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1] + bToInt(
   		 			isPalindrome[l][r]);
   		 	}
   		 }
   }

   static int bToInt(boolean bool)
   {
   		return bool ? 1 : 0;
   }

}