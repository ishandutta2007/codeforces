import java.io.*;
import java.util.*;
 
public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), k = sc.nextInt();
		int[] a = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		ArrayList<ArrayList<Integer>> l = new ArrayList<ArrayList<Integer>>();
		for(int i = 0; i <= 200000; i++)
			l.add(new ArrayList<Integer>());
		for(int i = 0; i < n; i++) {
			int ops = 0;
			l.get(a[i]).add(0);
			while(a[i] / 2 != a[i]) {
				a[i] /= 2;
				l.get(a[i]).add(++ops);
			}
		}
		long min = Long.MAX_VALUE;
		for(int i = 0; i <= 200000; i++)
			if(l.get(i).size() >= k) {
				Collections.sort(l.get(i));
				long sum = 0;
				for(int x = 0; x < k; x++)
					sum += l.get(i).get(x);
				min = Math.min(min, sum);
			}
		out.println(min);
		out.close();
	}
	public static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	public static class MyScanner {
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