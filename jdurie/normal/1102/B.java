//package cf531d3;
import java.io.*;
import java.util.*;

public class B{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),k=sc.nextInt();
		HashMap<Integer,HashSet<Integer>>colors=new HashMap<Integer,HashSet<Integer>>();
		LinkedList<Integer>ll=new LinkedList<Integer>();
		boolean ok=true;
		int max=0;
		for(int i=0;i<n;i++){
			int x=sc.nextInt();
			int c=0;
			while(c<colors.size()&&colors.get(c).contains(x))
				c++;
			if(c==colors.size())
				colors.put(c,new HashSet<Integer>());
			colors.get(c).add(x);
			ll.add(c+1);
			if(c+1>k)
				ok=false;
			max=Math.max(max,c+1);
		}
		System.out.println(ok?"YES":"NO");
		if(ok){
			HashSet<Integer>used=new HashSet<Integer>();
			for(int i:ll){
				if(max<k&&used.contains(i)){
					System.out.println(max+1);
					max++;
				}else
					System.out.print(i+" ");
				used.add(i);
			}
			System.out.println();
		}
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