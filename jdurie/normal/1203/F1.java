//package cf579d3;
import java.io.*;
import java.util.*;

public class F {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt(), r = sc.nextInt();
		int[] arr = new int[n];
		int pos = 0;
		int finalR = r;
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt(), b = sc.nextInt();
			arr[i] = a * 1000 + b + 300;
			if(b >= 0)
				pos++;
			finalR += b;
		}
		if(finalR < 0) {
			out.println("NO");
			out.close();
			return;
		}
		Integer[] positive = new Integer[pos];
		int[] negative = new int[n - pos];
		int iP = 0, iN = 0;
		for(int x : arr)
			if(x % 1000 >= 300)
				positive[iP++] = x;
			else
				negative[iN++] = x;
		Arrays.sort(positive);
		for(int i : positive) {
			if(r < i / 1000) {
				out.println("NO");
				out.close();
				return;
			}
			r += i % 1000 - 300;
		}
		for(int i = 0; i < n - pos; i++) {
			int ind = -1;
			for(int j = 0; j < n - pos; j++) {
				int a = negative[j] / 1000, b = negative[j] % 1000 - 300;
				if(finalR - b >= a) {
					ind = j;
					finalR -= b;
					break;
				}
			}
			if(ind == -1) {
				out.println("NO");
				out.close();
				return;
			}
		}
		out.println("YES");
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