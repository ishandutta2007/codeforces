import java.util.*;
import java.io.*;
public class D1365 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt(); int m = readInt();
			char[][]array = new char[n][m];
			boolean works = true;
			int gcount = 0;
			for(int i = 0; i<n; i++) {
				String s = next();
				for(int j = 0; j<m; j++) {
					array[i][j] = s.charAt(j);
					if(array[i][j]=='G')gcount++;
				}
			}
			boolean[]good = new boolean[gcount];
			boolean[]goodindex = new boolean[15000];
			int index = 0;
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
					if(array[i][j]=='B') {
						if(i-1>=0) {
							if(array[i-1][j]=='G')works = false;
						}
						if(i+1<n) {
							if(array[i+1][j]=='G')works = false;
						}
						if(j-1>=0) {
							if(array[i][j-1]=='G')works = false;
						}
						if(j+1<m) {
							if(array[i][j+1]=='G')works = false;
						}
					}
				}
			}
			if(!works) {
				pr.println("No");continue;
			}
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
					if(array[i][j]=='B') {
						if(i-1>=0) {
							if(array[i-1][j]=='.')array[i-1][j] = '#';
						}
						if(i+1<n) {
							if(array[i+1][j]=='.')array[i+1][j] = '#';
						}
						if(j-1>=0) {
							if(array[i][j-1]=='.')array[i][j-1] = '#';
						}
						if(j+1<m) {
							if(array[i][j+1]=='.')array[i][j+1] = '#';
						}
					}
				}
			}
			List<Integer>adj[] = new ArrayList[20000];
			for(int i = 0; i<=15000; i++)adj[i] = new ArrayList();
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
					if(array[i][j]=='G'||array[i][j]=='.') {
						if(i-1>=0) {
							if(array[i-1][j]=='G'||array[i-1][j]=='.') {
								int x = i*100+j;
								int y = (i-1)*100+j;
								adj[x].add(y);
								adj[y].add(x);
							}
						}
						if(i+1<n) {
							if(array[i+1][j]=='G'||array[i+1][j]=='.') {
								int x = i*100+j;
								int y = (i+1)*100+j;
								adj[x].add(y);
								adj[y].add(x);
							}
						}
						if(j-1>=0) {
							if(array[i][j-1]=='G'||array[i][j-1]=='.') {
								int x = i*100+j;
								int y = (i)*100+j-1;
								adj[x].add(y);
								adj[y].add(x);
							}
						}
						if(j+1<m) {
							if(array[i][j+1]=='G'||array[i][j+1]=='.') {
								int x = i*100+j;
								int y = (i)*100+j+1;
								adj[x].add(y);
								adj[y].add(x);
							}
						}
					}
				}
			}
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
					if(array[i][j]=='G') {
						goodindex[100*i+j] = true; 
					}
				}
			}
			for(int i = 0; i<12000; i++) {
				if(!goodindex[i])continue;
				int start = i;
				int end = (n-1)*100+(m-1);
				Queue<Integer>q = new LinkedList();
				boolean[]vis = new boolean[end+1];
				vis[start] = true;
				q.add(start);
				while(!q.isEmpty()) {
					int cur = q.poll();
					for(int nxt:adj[cur]) {
						if(!vis[nxt]) {
							vis[nxt] = true;
							goodindex[nxt] = false;
							q.add(nxt);
						}
					}
				}
				if(!vis[end])works = false;
			}
			if(works) {
				pr.println("Yes");
			}
			else {
				pr.println("No");
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