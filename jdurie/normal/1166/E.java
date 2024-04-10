import java.io.*;
import java.util.*;

public class E {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int m=sc.nextInt(),n=sc.nextInt();
		boolean[][]grid=new boolean[m][m];
		ArrayList<HashSet<Integer>>sets=new ArrayList<HashSet<Integer>>();
		for(int i=0;i<m;i++)
			sets.add(new HashSet<Integer>());
		boolean ok=true;
		for(int i=0;i<m;i++){
			if(ok){
				int s=sc.nextInt();
				for(int j=0;j<s;j++)
					sets.get(i).add(sc.nextInt()-1);
				for(int k=0;k<i;k++)
					if(!grid[i][k]){
						for(int l:sets.get(i))
							if(sets.get(k).contains(l)){
								grid[i][k]=true;
								break;
							}
						if(!grid[i][k])
							ok=false;
					}
			}
		}
		System.out.println(ok?"possible":"impossible");
		// ------------------------
		out.close();
	}
	//------------------------

	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
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