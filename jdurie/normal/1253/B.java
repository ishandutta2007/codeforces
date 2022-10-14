//package cf600d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		TreeSet<Integer> in = new TreeSet<Integer>(), past = new TreeSet<Integer>();
		LinkedList<Integer> ans = new LinkedList<Integer>();
		int len = 0;
		boolean ok = true;
		for(int i = 0; i < n; i++) {
			int next = sc.nextInt();
			//out.println(next);
			if(next < 0 && in.contains(-next))
				in.remove(-next);
			else if(next < 0)
				ok = false;
			else if(!past.contains(next)) {
				in.add(next);
				past.add(next);
			} else
				ok = false;
			len++;
			//out.println(in);
			if(in.isEmpty()) {
				ans.add(len);
				in = new TreeSet<Integer>();
				past = new TreeSet<Integer>();
				len = 0;
			}
		}
		if(!in.isEmpty())
			ok = false;
		out.println(ok ? ans.size() : -1);
		if(ok)
			for(int x : ans)
				out.print(x + " ");
		out.println();
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