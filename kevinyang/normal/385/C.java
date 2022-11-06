import java.util.*;
import java.io.*;
public class C385 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt();
		//int[]array = new int[n];
		int len = 10000000;
		boolean[]prime= new boolean[len+1];
		Arrays.fill(prime, true);
		prime[0] = false;
		prime[1] = false;
		for(int i = 2; i<=(int)Math.sqrt(prime.length); i++) {
			for(int j = i*i;j<prime.length; j+=i) {
				prime[j] = false;
			}
		}
		int[]freq = new int[len+1];
		int[]array = new int[len+1];
		for(int i = 0; i<n; i++)freq[readInt()]++;
		for(int i = 0; i<=len; i++) {
			if(prime[i]) {
				for(int j = i;j<=len; j+=i) {
					array[i]+=freq[j];
				}
			}
		}
		int[]psa = new int[len+1];
		for(int i = 1; i<=len; i++) {
			psa[i]=psa[i-1]+array[i];
		}
		int queries = readInt();
		for(int q = 0; q<queries; q++) {
			int l = readInt();
			int r = readInt();
			if(r>10000000)r = 10000000;
			if(l>10000000)l = 10000000;
			pr.println(psa[r]-psa[l-1]);
		}
		pr.close();
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