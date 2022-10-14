//package cf582d3;
import java.io.*;
import java.util.*;

public class E {
	static char[] s, t;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		s = sc.nextLine().toCharArray();
		t = sc.nextLine().toCharArray();
		out.println("YES");
		if(s[0] == s[1] && t[0] == t[1]) {
			for(int i = 0; i < n; i++)
				out.print("abc");
		} else if(s[0] == s[1] || t[0] == t[1]) {
			if(s[0] == s[1]) swap();
			if(s[0] == t[0] || s[1] == t[0]) {
				char c = (char)('a' + 'b' + 'c' - s[0] - s[1]);
				char d = (char)(s[0] + s[1] - t[0]);
				for(int i = 0; i < n; i++)
					out.print(d);
				for(int i = 0; i < n; i++)
					out.print(c + "" + t[0]);
			} else {
				for(int i = 0; i < n; i++)
					out.print(s[0]);
				for(int i = 0; i < n; i++)
					out.print(t[0] + "" + s[1]);
			}
		} else if(s[0] == t[1] && s[1] == t[0]) {
			char c = (char)('a' + 'b' + 'c' - s[0] - s[1]);
			for(int i = 0; i < n; i++)
				out.print(s[0]);
			for(int i = 0; i < n; i++)
				out.print(c);
			for(int i = 0; i < n; i++)
				out.print(s[1]);
		} else {
			if(s[0] == t[0]) {
				for(int i = 0; i < 3; i++)
					if(i + 'a' != s[0])
						for(int j = 0; j < n; j++)
							out.print((char)(i + 'a'));
				for(int i = 0; i < n; i++)
					out.print(s[0]);
			} else {
				if(s[0] != t[1]) swap();
				for(int i = 0; i < n; i++)
					out.print(s[1]);
				for(int i = 0; i < n; i++)
					out.print(s[0]);
				for(int i = 0; i < n; i++)
					out.print(t[0]);
			}
		}
		out.close();
	}
	static void swap() {
		char[] x = {s[0], s[1]};
		s = new char[] {t[0], t[1]};
		t = new char[] {x[0], x[1]};
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