
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class AAA {
	static class Node {
		Node z, o;
		void insert(int l, int i) {
			int bit = (l & (1 << i)) >> i;
			if(bit > 0) {
				if(o == null)
					o = new Node();
				if(i > 0)
					o.insert(l, i - 1);
			} else {
				if(z == null)
					z = new Node();
				if(i > 0)
					z.insert(l, i - 1);
			}
		}
		long ans(int i) {
			if(i < 0) return 0;
			if(z == null)
				return o.ans(i - 1);
			if(o == null)
				return z.ans(i - 1);
			return (1 << i) + min(z.ans(i - 1), o.ans(i - 1));
		}
	}
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		Node root = new Node();
		for(int i = 0; i < n; i++)
			root.insert(sc.nextInt(), 31);
		out.println(root.ans(31));
		out.close();
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