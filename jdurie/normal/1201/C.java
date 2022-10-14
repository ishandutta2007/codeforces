//package cf577d2;
import java.io.*;
import java.util.*;

public class C {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt();
		long k = sc.nextInt();
		Long[] a = new Long[n + 1];
		for(int i = 0; i < n; i++)
			a[i] = sc.nextLong();
		a[n] = (long)Integer.MAX_VALUE;
		Arrays.sort(a);
		long med = a[n / 2];
		for(int i = n / 2; i < n; i++) {
			long d = a[i + 1] - a[i];
			if((i - n / 2 + 1) * d > k) {
				med += k / (i - n / 2 + 1);
				break;
			} else {
				med += d;
				k -= (i - n / 2 + 1) * d;
			}
		}
		out.println(med);
		// ------------------------
		out.close();
	}
	//------------------------
	
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