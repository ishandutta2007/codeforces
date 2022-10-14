import java.io.*;
import java.util.*;

public class B {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		HashMap<Integer,Integer>forward=new HashMap<Integer,Integer>();
		TreeMap<Integer,HashSet<Integer>>backward=new TreeMap<Integer,HashSet<Integer>>();
		int max=1;
		for(int i=1;i<=n;i++){
			int x=sc.nextInt();
			int y=forward.containsKey(x)?forward.get(x):0;
			forward.put(x, y+1);
			if(y>0){
				backward.get(y).remove(x);
				if(backward.get(y).isEmpty())
					backward.remove(y);
			}
			if(!backward.containsKey(y+1))
				backward.put(y+1,new HashSet<Integer>());
			backward.get(y+1).add(x);
			if((backward.firstKey()+1==backward.lastKey()&&backward.get(backward.lastKey()).size()==1)||
					(backward.keySet().size()==2&&backward.containsKey(1)&&backward.get(1).size()==1)||
					(backward.keySet().size()==1&&backward.get(backward.firstKey()).size()==1)||
					(backward.keySet().size()==1&&backward.containsKey(1)))
				max=i;
			//System.out.println(backward+" "+max);
		}
		System.out.println(max);
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