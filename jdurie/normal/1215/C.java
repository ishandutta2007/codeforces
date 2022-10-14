//package cf585d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		char[] s = sc.nextLine().toCharArray();
		char[] t = sc.nextLine().toCharArray();
		int aCt = 0;
		for(char c : s)
			if(c == 'a')
				aCt++;
		for(char c : t)
			if(c == 'a')
				aCt++;
		if(aCt % 2 == 1)
			out.println(-1);
		else {
			int ab = -1, ba = -1;
			LinkedList<String> ops = new LinkedList<String>();
			for(int i = 0; i < n; i++)
				if(s[i] == 'a' && t[i] == 'b') {
					if(ab == -1)
						ab = i + 1;
					else {
						ops.add(ab + " " + (i + 1));
						ab = -1;
					}
				} else if(s[i] == 'b' && t[i] == 'a') {
					if(ba == -1)
						ba = i + 1;
					else {
						ops.add(ba + " " + (i + 1));
						ba = -1;
					}
				}
			if(ab != -1) {
				ops.add(ab + " " + ab);
				ops.add(ba + " " + ab);
			}
			out.println(ops.size());
			for(String str : ops)
				out.println(str);
		}
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