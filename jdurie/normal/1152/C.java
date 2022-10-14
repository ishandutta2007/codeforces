import java.io.*;
import java.util.*;

public class C{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		long a=sc.nextlong(),b=sc.nextlong();
		long d=Math.abs(a-b);
		if(d==0)
			System.out.println(0);
		else{
			long min=Long.MAX_VALUE,minK=-1;
			HashSet<Long>f=factors(d);
			for(long i:f){
				//System.out.println(i);
				long k=(i-a%i)%i;
				long lcm=(a+k)*(b+k)/gcd(a+k,b+k);
				if(lcm<min){
					min=lcm;
					minK=k;
				}
			}
			System.out.println(minK);
		}
		// ------------------------
		out.close();
	}
	//------------------------
	private static long gcd(long a,long b){
		return b==0?a:gcd(b,a%b);
	}
	private static HashSet<Long>factors(long x){
		HashSet<Long>set=new HashSet<Long>();
		for(long i=1;i<=Math.sqrt(x);i++)
			if(x%i==0){
				set.add(i);
				if(!set.contains(x/i))
					set.add(x/i);
			}
		return set;
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
		long nextlong() {
			return Long.parseLong(next());
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