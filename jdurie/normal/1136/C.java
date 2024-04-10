import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		HashMap<Integer,HashMap<Integer,Integer>>bs=new HashMap<Integer,HashMap<Integer,Integer>>();
		for(int i=0;i<=n-1+m-1;i++)
			bs.put(i,new HashMap<Integer,Integer>());
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				int x=sc.nextInt();
				if(!bs.get(i+j).containsKey(x))
					bs.get(i+j).put(x,1);
				else
					bs.get(i+j).put(x,bs.get(i+j).get(x)+1);
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				int x=sc.nextInt();
				if(bs.get(i+j).containsKey(x)){
					if(bs.get(i+j).get(x)==1){
						bs.get(i+j).remove(x);
						if(bs.get(i+j).isEmpty())
							bs.remove(i+j);
					}else
						bs.get(i+j).put(x,bs.get(i+j).get(x)-1);
				}
			}
		System.out.println(bs.isEmpty()?"YES":"NO");
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