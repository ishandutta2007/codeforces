import java.util.*;
import java.io.*;
public class F{
	// ------------------------
	static HashMap<Integer,HashSet<Integer>>graph=new HashMap<Integer,HashSet<Integer>>();
	static boolean[]used;
	static LinkedList<Integer>q=new LinkedList<Integer>();
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		for(int i=0;i<n;i++)
			graph.put(i,new HashSet<Integer>());
		for(int i=0;i<m;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			graph.get(a).add(b);
			graph.get(b).add(a);
		}
		used=new boolean[n];
		int max=0;
		for(int i=1;i<n;i++)
			if(graph.get(i).size()>graph.get(max).size())
				max=i;
		q.add(max);
		while(!q.isEmpty())
			bfs(q.removeFirst());
		// ------------------------
		out.close();
	}
	//------------------------
	private static void bfs(int i){
		used[i]=true;
		for(int j:graph.get(i))
			if(!used[j]){
				out.println((i+1)+" "+(j+1));
				q.addLast(j);
				used[j]=true;
			}
	}
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