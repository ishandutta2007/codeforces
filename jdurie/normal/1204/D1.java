//package cf581d2;
import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		char[] s = sc.nextLine().toCharArray();
		int[] zeroes = new int[s.length];
		int[] ones = new int[s.length];
		for(int i = 0; i < s.length; i++) {
			if(i > 0) {
				zeroes[i] = zeroes[i - 1];
				ones[i] = ones[i - 1];
			}
			if(s[i] == '0')
				zeroes[i]++;
			else
				ones[i]++;
		}
		int[] subs = new int[s.length];
		for(int i = 0; i < s.length; i++) {
			subs[i] = Math.max(zeroes[i], ones[i]);
			for(int j = 0; j < i; j++)
				subs[i] = Math.max(subs[i], zeroes[j] + ones[i] - ones[j]);
		}
		int[] zsToAdd = new int[s.length];
		for(int i = 0; i < s.length; i++)
			zsToAdd[i] = subs[i] - zeroes[i];
		for(int i = s.length - 2; i >= 0; i--)
			zsToAdd[i] = Math.min(zsToAdd[i], zsToAdd[i + 1]);
		int added = 0;
		for(int i = 0; i < s.length; i++)
			if(s[i] == '0')
				out.print('0');
			else if(zsToAdd[i] > added){
				out.print('0');
				added++;
			} else
				out.print('1');
		out.println();
		out.close();
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