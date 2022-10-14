//package cf573d1;
import java.io.*;
import java.util.*;

public class B {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long n=sc.nextInt(),sum=0;
		HashMap<Long,Integer>map=new HashMap<Long,Integer>();
		for(long i=0;i<n;i++){
			long l=sc.nextLong();
			sum+=l;
			map.put(l,map.containsKey(l)?map.get(l)+1:1);
		}
		int max=0,ct2=0;
		long below=0;
		for(long i:map.keySet()){
			max=Math.max(max,map.get(i));
			if(map.get(i)==2){
				ct2++;
				below=i-1;
			}
		}
		long x=sum-n*(n-1)/2;
		System.out.println((max<3&&(ct2==0||(ct2==1&&!map.containsKey(below)&&below>=0))&&x%2==1&&x>0)?"sjfnb":"cslnb");
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