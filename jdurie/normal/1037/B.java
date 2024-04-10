//package manthan18;
import java.io.*;
import java.util.*;

public class B {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n = sc.nextInt(), s = sc.nextInt();
		Integer[] arr = new Integer[n];
		for(int i = 0; i < n; i++)
			arr[i] = sc.nextInt();
		Arrays.sort(arr);
		long ops = 0;
		int i = n / 2;
		if(arr[i] > s) 
			while(i >= 0 && arr[i] > s)
				ops += arr[i--] - s;
		else
			while(i < n && arr[i] < s)
				ops += s - arr[i++];
		out.println(ops);
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