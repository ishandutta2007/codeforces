//package cf586d12;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;
 
public class D {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		ArrayList<TreeSet<Long>> list = new ArrayList<TreeSet<Long>>();
		for(int i = 0; i < 65; i++)
			list.add(new TreeSet<Long>());
		for(int i = 0; i < n; i++) {
			long x = sc.nextLong(), y = x;
			int twos = 0;
			while(y % 2 == 0) {
				twos++;
				y /= 2;
			}
			list.get(twos).add(x);
		}
		int maxI = 0;
		for(int i = 1; i < 65; i++)
			if(list.get(i).size() > list.get(maxI).size())
				maxI = i;
		out.println(n - list.get(maxI).size());
		for(int i = 0; i < 65; i++)
			if(i != maxI)
				for(long j : list.get(i))
					out.print(j + " ");
		out.close();
	}
	static void print(TreeSet<Long> s1, TreeSet<Long> s2) {
		out.println(s1.size() + s2.size());
		for(long i : s1)
			out.print(i + " ");
		for(long i : s2)
			out.print(i + " ");
		out.println();
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