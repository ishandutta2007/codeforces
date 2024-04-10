
import java.io.*;
import java.util.*;

public class B {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		TreeSet<Integer>set=new TreeSet<Integer>();
		for(int i=0;i<n;i++)
			set.add(sc.nextInt());
		if(set.size()>3)
			System.out.println(-1);
		else if(set.size()==1)
			System.out.println(0);
		else if(set.size()==2){
			int x=set.last()-set.first();
			System.out.println(x%2==0?x/2:x);
		}else{
			int one=set.pollFirst(),two=set.pollFirst(),three=set.pollFirst();
			System.out.println(two-one==three-two?two-one:-1);
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