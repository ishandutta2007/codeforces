//package cf602d1;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	static LinkedList<String> ops;
	static int n;
	static char[] s;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		while(t-- > 0) {
			n = sc.nextInt();
			int k = sc.nextInt();
			s = sc.nextLine().toCharArray();
			ops = new LinkedList<String>();
			for(int i = 0; i < k - 1; i++) {
				if(s[2 * i] == ')')
					swap(2 * i);
				if(s[2 * i + 1] == '(')
					swap(2 * i + 1);
			}
			for(int i = 2 * (k - 1); i < 2 * (k - 1) + (n - 2 * (k - 1)) / 2; i++)
				if(s[i] == ')') swap(i);
			out.println(ops.size());
			for(String s : ops) out.println(s);
		}
		out.close();
	}
	static void swap(int i) {
		for(int j = i + 1; j < n; j++)
			if(s[j] != s[i]) {
				ops.add((i + 1) + " " + (j + 1));
				char[] temp = new char[n];
				for(int k = 0; i + k <= j; k++)
					temp[i + k] = s[j - k];
				for(int k = 0; i + k <= j; k++)
					s[i + k] = temp[i + k];
				return;
			}
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