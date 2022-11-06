import java.util.*;
import java.io.*;
public class C1364 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt();
		int[]array = new int[n];
		boolean[]vis = new boolean[(int)3e5+5];
		for(int i = 0; i<n; i++) {
			array[i] = readInt();
			vis[array[i]] = true;
		}
		ArrayList<Integer>ans = new ArrayList<Integer>();
		PriorityQueue<Integer>q = new PriorityQueue<Integer>();
		for(int i = 0; i<=250000; i++) {
			if(!vis[i])q.add(i);
		}
		for(int i = 0; i<n; i++) {
			int cur = q.poll();
			ans.add(cur);
			if(i<n-1) {
				if(array[i]<array[i+1])
				q.add(array[i]);
			}
		}
		for(int i = 0; i<n; i++) {
			if(i>0)pr.print(" ");
			pr.print(ans.get(i));
		}
		pr.println();
		pr.close();
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}