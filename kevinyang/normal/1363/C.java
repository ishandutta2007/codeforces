import java.util.*;
import java.io.*;
public class C1363 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt(); int x = readInt();
			List<Integer>adj[] = new ArrayList[n+1];
			for(int i = 1; i<=n; i++)adj[i] = new ArrayList();
			for(int i = 0; i<n-1; i++) {
				int a = readInt(); int y = readInt();
				adj[a].add(y); adj[y].add(a);
			}
			int nodes = adj[x].size();
			int num = n-1;
			if(nodes<=1) {
				pr.println("Ayush"); continue;
			}
			if(num%2==0) {
				pr.println("Ashish");
			}
			else {
				pr.println("Ayush");
			}
		}
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