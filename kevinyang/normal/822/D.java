import java.util.*;
import java.io.*;
public class D822 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	static long mod = (int)1e9+7;
	
	public static void main(String[]args)throws IOException {
		int t = readInt();
		int l = readInt();
		int r = readInt();
		ArrayList<Integer>primes = new ArrayList<Integer>();
		long[]dp = new long[(int)5e6+1];
		long[]powers = new long[r-l+1];
		powers[0] = 1;
		for(int i = 1; i<powers.length; i++) {
			powers[i] =( powers[i-1]*t)%mod;
		}
		loop:
		for(int i = 2; i<=(int)5e6; i++) {
			int num = i;
			for(int j = 0; j<primes.size(); j++) {
				if(num%primes.get(j)==0) {
					dp[i] = (long)num/primes.get(j) * (primes.get(j)-1)* primes.get(j)/2 + dp[num/primes.get(j)];
					continue loop;
				}
				if(primes.get(j)*primes.get(j)>num) {
					primes.add(num);
					dp[i] = (long)num*(num-1)/2;
					continue loop;
				}
			}
			primes.add(num);
			dp[i] = (long)num*(num-1)/2;
			
		}
		long ans = 0;
		for(int i = l; i<=r; i++) {
			ans+=(dp[i]%mod)*powers[i-l];
			ans%=mod;
		}
		pr.println(ans);
		
		pr.close();
	}
	public static long fastpower(long base, long power) {
		long result = 1;
		while(power>0) {
			if(power%2==1) {
				result = (result*base)%mod;
			}
			power = power/2;
			base = (base*base)%mod;
		}
		return result;
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}