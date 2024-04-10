//package cfed71;
import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			int n = sc.nextInt();
			long a = sc.nextLong(), b = sc.nextLong();
			char[] s = sc.nextLine().toCharArray();
			LinkedList<Integer> ll = new LinkedList<Integer>();
			ll.add(1);
			for(int i = 1; i < n; i++)
				if(s[i] == s[i - 1])
					ll.addLast(ll.removeLast() + 1);
				else
					ll.addLast(1);
			if(ll.size() == 1)
				out.println(ll.removeFirst() * (a + b) + b);
			else {
				long ans = ll.removeFirst() * (a + b) + a;
				boolean ones = true;
				while(ll.size() > 1) {
					if(ones)
						ans += ll.removeFirst() * (2 * b + a) + 2 * b;
					else {
						int z = ll.removeFirst();
						ans += Math.min((z - 1) * b + (z + 2) * a, (z - 1) * 2 * b + z * a);
					}
					ones = !ones;
				}
				ans += ll.removeFirst() * (a + b) + a;
				out.println(ans);
			}
		}
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