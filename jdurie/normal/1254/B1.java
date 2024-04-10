//package cf601d1;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		long sum = 0;
		int[] a = new int[n];
		for(int i = 0; i < n; i++)
			sum += (a[i] = sc.nextInt());
		long ans = Long.MAX_VALUE;
		for(long fact = 2; fact * fact <= sum; fact++)
			if(sum % fact == 0) {
				while(sum % fact == 0) sum /= fact;
				ans = min(ans, getAns(fact, a, n));
			}
		if(sum > 1) ans = min(ans, getAns(sum, a, n));
		out.println(ans == Long.MAX_VALUE ? -1 : ans);
		out.close();
	}
	static long getAns(long fact, int[] a, int n) {
		int idx = 0;
		long ans = 0, neow = -1;
		LinkedList<Long> idxs = new LinkedList<Long>();
		for(int i = 0; i < n; i++)
			if(a[i] == 1) {
				if(idx < fact / 2)
					idxs.add((long)i);
				else if(idx == fact / 2) {
					while(!idxs.isEmpty())
						ans += (long) i - idxs.pollFirst();
					neow = i;
				} else
					ans += (long) i - neow;
				idx = (idx + 1) % (int)fact;
			}
		return ans;
	}
	static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	static class MyScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while (st == null || !st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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