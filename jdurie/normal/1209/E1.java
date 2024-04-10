//package cf584d12;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class E {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		for(int w = 0; w < t; w++) {
			int n = sc.nextInt(), m = sc.nextInt();
			TreeSet<X> set = new TreeSet<X>();
			int[][] grid = new int[n][m];
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++) {
					grid[i][j] = sc.nextInt();
					set.add(new X(i, j, grid[i][j]));
				}
			Y[] top4 = new Y[n];
			int sum = 0;
			for(int i = 0; i < n; i++) {
				top4[i] = new Y(set.pollLast());
				sum += top4[i].a;
			}
			Arrays.sort(top4);
			HashSet<String> strs = new HashSet<String>();
			AAA[] sss = new AAA[n];
			boolean[] used = new boolean[n];
			if(n == 4) {
				for(int i = 0; i < 4; i++) {
					int max = -1, jj = -1;
					for(int j = 0; j < 4; j++) {
						if(!used[j] && top4[j].a > max) {
							max = top4[j].a;
							jj = j;
						}
					}
					used[jj] = true;
					sss[i] = new AAA(max, jj);
				}
				for(int i = 0; i < n; i++)
					strs.add(top4[i].i + " " + top4[i].j);
			}
			int ans = sum;
			if(n == 4 && top4[0].j == top4[1].j && top4[2].j == top4[3].j && top4[0].j != top4[2].j) {
				if(two(top4[0], top4[1]) != two(top4[2], top4[3])) {
					ans = 0;
					int oneCol = two(top4[0], top4[1]) ? top4[2].j : top4[0].j;
					for(int i = 0; i < n; i++)
						for(int j = 0; j < m; j++)
							if(!strs.contains(i + " " + j)){
								int no = -1;
								for(int k = 0; k < 4; k++)
									if(j == oneCol && top4[k].j == oneCol && two(top4[k], new Y(new X(i, j, 0))))
										no = k;
								ans = max(ans, sum - sss[no == sss[3].i ? 2 : 3].a + grid[i][j]);
							}
				}
			}
			out.println(ans);
		}
		out.close();
	}
	static class AAA {
		int a, i;
		public AAA(int A, int I) {
			a = A; 
			i = I;
		}
	}
	static boolean two(Y y1, Y y2) {
		return (y1.i - y2.i + 4) % 4 == 2;
	}
	static class Y implements Comparable<Y> {
		int i, j, a;
		public Y(X x) {
			i = x.i;
			j = x.j;
			a = x.a; 
		}
		public int compareTo(Y x) {
			if(j == x.j)
				return i - x.i;
			return j - x.j;
		}
	}
	static class X implements Comparable<X> {
		int i, j, a;
		public X(int I, int J, int A) {
			i = I;
			j = J;
			a = A; 
		}
		public int compareTo(X x) {
			if(a == x.a && i == x.i)
				return j - x.j;
			else if(a == x.a)
				return i - x.i;
			return a - x.a;
		}
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