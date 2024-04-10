//package cf582d3;
import java.io.*;
import java.util.*;

public class F {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), k = sc.nextInt();
		int[] p = new int[n], q = new int[n];
		for(int i = 0; i < n; i++)
			p[i] = sc.nextInt() - 1;
		for(int i = 0; i < n; i++)
			q[i] = sc.nextInt() - 1;
		int sets = 0;
		char[] str = new char[n];
		TreeSet<Integer> pExt = new TreeSet<Integer>();
		TreeSet<Integer> qExt = new TreeSet<Integer>();
		HashSet<Integer> last = new HashSet<Integer>();
		for(int i = 0; i < n; i++) {
			last.add(p[i]);
			last.add(q[i]);
			if(!qExt.remove(p[i]))
				pExt.add(p[i]);
			if(!pExt.remove(q[i]))
				qExt.add(q[i]);
			if(pExt.isEmpty() && qExt.isEmpty()) {
				for(int l : last)
					str[l] = (char)(Math.min('z', 'a' + sets));
				last = new HashSet<Integer>();
				sets++;
			}
		}
		out.println(sets >= k ? "YES" : "NO");
		if(sets >= k)
			for(int i = 0; i < n; i++)
				out.print(str[i]);
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