//package cf539d1;
import java.io.*;
import java.util.*;

public class A{
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		long xor=0;
		HashMap<Long,Long>evens=new HashMap<Long,Long>();
		HashMap<Long,Long>odds=new HashMap<Long,Long>();
		odds.put(0L,1L);
		for(int i=0;i<n;i++){
			xor^=sc.nextInt();
			if(i%2==0)
				evens.put(xor,evens.containsKey(xor)?evens.get(xor)+1:1);
			else
				odds.put(xor,odds.containsKey(xor)?odds.get(xor)+1:1);
		}
		long ans=0;
		for(long i:evens.keySet())
			ans+=evens.get(i)*(evens.get(i)-1)/2;
		for(long i:odds.keySet())
			ans+=odds.get(i)*(odds.get(i)-1)/2;
		out.println(ans);
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