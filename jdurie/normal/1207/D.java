//package cfed71;
import java.io.*;
import java.util.*;

public class E {
	static long[] fact;
	static long MOD = 998244353;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int n = sc.nextInt();
		fact = new long[n + 1];
		fillFact();
		int[] left = new int[n];
		int[] right = new int[n];
		HashMap<String, Integer> equals = new HashMap<String, Integer>();
		int[] minR = new int[n];
		int[] maxR = new int[n];
		for(int i = 0; i < n; i++) {
			minR[i] = n;
			maxR[i] = -1;
		}
		for(int i = 0; i < n; i++) {
			int l = sc.nextInt() - 1, r = sc.nextInt() - 1;
			left[l]++;
			right[r]++;
			minR[l] = Math.min(minR[l], r);
			maxR[l] = Math.max(maxR[l], r);
			String s = l + " " + r;
			equals.put(s, equals.containsKey(s) ? equals.get(s) + 1 : 1);
		}
		long lSorted = 1;
		for(int x : left)
			lSorted = (lSorted * fact[x]) % MOD;
		long rSorted = 1;
		for(int x : right)
			rSorted = (rSorted * fact[x]) % MOD;
		boolean canSortBoth = true;
		int last = 0;
		for(int i = 0; i < n; i++) 
			if(minR[i] != n) {
				if(minR[i] < last) {
					canSortBoth = false;
					break;
				}
				last = maxR[i];
			}
		long bSorted = canSortBoth ? 1 : 0;
		if(canSortBoth)
			for(String s : equals.keySet())
				bSorted = bSorted * fact[equals.get(s)] % MOD;
		out.println((fact[n] - lSorted - rSorted + bSorted + 10 * MOD) % MOD);
		out.close();
	}
	static void fillFact() {
		fact[0] = 1;
		for(int i = 1; i < fact.length; i++)
			fact[i] = (long)i * fact[i - 1] % MOD;
	}
	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}