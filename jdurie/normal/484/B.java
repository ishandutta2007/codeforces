//package a2oj;
import java.io.*;
import java.util.*;

public class MaximumValue {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		TreeSet<Integer>set=new TreeSet<Integer>();
		for(int i=0;i<n;i++)
			set.add(sc.nextInt());
		TreeSet<Integer>gtrSet=new TreeSet<Integer>();
		gtrSet.add(set.pollLast());
		int max=0;
		while(!set.isEmpty()&&set.last()>max){
			int first=(int)Math.ceil((gtrSet.first()+1)/(double)set.last());
			int last=(int)Math.ceil((gtrSet.last()+1)/(double)set.last());
			for(int i=first; i<=last; i++)
				max=Math.max(max,gtrSet.floor(set.last()*i-1)%set.last());
			gtrSet.add(set.pollLast());
		}
		out.println(max);
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