
import java.util.*;
import java.io.*;
public class G{
	// ------------------------
	static HashMap<Integer,HashSet<Integer>>graph=new HashMap<Integer,HashSet<Integer>>();
	static boolean[]used;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt(),d=sc.nextInt();
		for(int i=0;i<n;i++)
			graph.put(i,new HashSet<Integer>());
		for(int i=0;i<m;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			graph.get(a).add(b);
			graph.get(b).add(a);
		}
		//System.out.println(graph);
		if(d>graph.get(0).size())
			out.println("NO");
		else{
			used=new boolean[n];
			HashSet<Integer>sets=new HashSet<Integer>();
			for(int i:graph.get(0))
				if(!used[i]){
					dfs(i,false);
					sets.add(i);
				}
			//System.out.println(littleFeelers);
			if(sets.size()>d)
				out.println("NO");
			else{
				out.println("YES");
				used=new boolean[n];
				used[0]=true;
				int ct=0;
				HashSet<Integer>anotherSet=new HashSet<Integer>();
				for(int i:sets){
					out.println("1 "+(i+1));
					anotherSet.add(i);
					used[i]=true;
					ct++;
				}
				for(int j:graph.get(0))
					if(!used[j]&&ct<d){
						used[j]=true;
						out.println("1 "+(j+1));
						anotherSet.add(j);
						ct++;
					}
				for(int i:anotherSet)
					dfs2(i);
			}
		}
		// ------------------------
		out.close();
	}
	//------------------------
	private static void dfs2(int i){
		used[i]=true;
		for(int j:graph.get(i))
			if(!used[j]){
				out.println((i+1)+" "+(j+1));
				dfs2(j);
			}
	}
	private static void dfs(int i,boolean b){
		//System.out.println(i+" "+graph.get(i));
		used[i]=true;
		if(i!=0)
			for(int j:graph.get(i))
				if(!used[j]&&(j>0||b))
					dfs(j,true);
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