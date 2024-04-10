import java.io.*;
import java.util.*;

public class D{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long m=sc.nextLong(),a=sc.nextLong(),b=sc.nextLong(),g=gcd(a,b);
		long x=a,max=a;
		HashMap<Long,Long>f=new HashMap<Long,Long>();
		f.put(0L,0L);
		f.put(a,a);
		while(f.size()<=max/g){
			if(!f.containsKey(x))
				f.put(x,max);
			if(f.size()<=max/g){
				if(x>b)
					x-=b;
				else{
					x+=a;
					max=Math.max(max, x);
				}
			}
		}
		long ans=0;
		for(long i:f.keySet())
			if(m-f.get(i)+1>0)
				ans+=m-f.get(i)+1;
		long bs=(m-m%g-max)/g;
		if(bs>0){
			ans-=g*(sumI(m/g)-sumI(max/g));
			ans+=bs*(m+1);
		}
		System.out.println(ans);
		// ------------------------
		out.close();
	}
	//------------------------
	private static long sumI(long i){
		return i*(i+1)/2;
	}
	private static long gcd(long a,long b){
		return b==0?a:gcd(b,a%b);
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