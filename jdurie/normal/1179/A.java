//package cf569d1;
import java.io.*;
import java.util.*;

public class A {
	// ------------------------
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),q=sc.nextInt();
		LinkedList<Integer>deque=new LinkedList<Integer>();
		String[]ops=new String[3*n];
		for(int i=0;i<n;i++)
			deque.add(sc.nextInt());
		for(int i=1;i<ops.length;i++){
			int a=deque.pollFirst(),b=deque.pollFirst();
			ops[i]=a+" "+b;
			deque.addLast(Math.min(a, b));
			deque.addFirst(Math.max(a, b));
		}
		int a=deque.pollFirst(),b=deque.pollFirst();
		ops[0]=a+" "+b;
		for(int i=0;i<q;i++){
			long m=sc.nextLong();
			if(m>ops.length)
				m-=(n-1)*((m-ops.length)/(n-1));
			while(m>=ops.length)
				m-=n-1;
			System.out.println(ops[(int)m]);
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