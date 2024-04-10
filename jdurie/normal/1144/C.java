import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		TreeSet<Integer>one=new TreeSet<Integer>();
		TreeSet<Integer>two=new TreeSet<Integer>();
		boolean good=true;
		for(int i=0;i<n;i++){
			int x=sc.nextInt();
			if(one.contains(x)){
				if(two.contains(x))
					good=false;
				else
					two.add(x);
			}else
				one.add(x);
		}
		System.out.println(good?"YES":"NO");
		if(good){
			System.out.println(one.size());
			while(!one.isEmpty())
				System.out.print(one.pollFirst()+" ");
			System.out.println("\n"+two.size());
			while(!two.isEmpty())
				System.out.print(two.pollLast()+" ");
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