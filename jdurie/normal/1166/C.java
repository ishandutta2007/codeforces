import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		TreeMap<Integer,Integer>set=new TreeMap<Integer,Integer>();
		for(int i=0;i<n;i++){
			int x=Math.abs(sc.nextInt());
			set.put(x,set.containsKey(x)?set.get(x)+1:1);
		}
		LinkedList<Integer>queue=new LinkedList<Integer>();
		long ans=0;
		while(!set.isEmpty()){
			int x=pollFirst(set);
			while(!queue.isEmpty()&&2*queue.peekFirst()<x)
				queue.pollFirst();
			ans+=queue.size();
			queue.addLast(x);
		}
		System.out.println(ans);
		// ------------------------
		out.close();
	}
	//------------------------
	private static int pollFirst(TreeMap<Integer,Integer>set){
		int x=set.firstKey();
		if(set.get(x)==1)
			set.remove(x);
		else
			set.put(x,set.get(x)-1);
		return x;
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