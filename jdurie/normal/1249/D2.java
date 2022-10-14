//package cf595d3;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt(), k = sc.nextInt();
		S[] segs = new S[n];
		for(int i = 0; i < n; i++)
			segs[i] = new S(sc.nextInt(), sc.nextInt(), i + 1);
		Arrays.sort(segs);
		TreeSet<T> runningSegs = new TreeSet<T>();
		int idx = 0;
		LinkedList<Integer> ans = new LinkedList<Integer>();
		for(int i = 1; i <= 200000; i++) {
			while(idx < n && segs[idx].l == i)
				runningSegs.add(new T(segs[idx].r, segs[idx++].i));
			while(runningSegs.size() > k)
				ans.add(runningSegs.pollLast().i);
			while(!runningSegs.isEmpty() && runningSegs.first().r == i)
				runningSegs.pollFirst();
		}
		out.println(ans.size());
		for(int i : ans)
			out.print(i + " ");
		out.println();
		out.close();
	}
	static class S implements Comparable<S> {
		int l, r, i;
		public S(int L, int R, int I) {
			l = L;
			r = R;
			i = I;
		}
		public int compareTo(S s) {
			return l == s.l ? r - s.r : l - s.l;
		}
	}
	static class T implements Comparable<T> {
		int r, i;
		public T(int R, int I) {
			r = R;
			i = I;
		}
		public int compareTo(T s) {
			return r == s.r ? i - s.i : r - s.r;
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