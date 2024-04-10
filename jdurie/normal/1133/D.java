import java.io.*;
import java.util.*;

public class D {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		int[]a=new int[n];
		int[]b=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		for(int i=0;i<n;i++)
			b[i]=sc.nextInt();
		HashMap<String,Integer>map=new HashMap<String,Integer>();
		int dZ=0;
		for(int i=0;i<n;i++){
			if(a[i]==0&&b[i]!=0)
				continue;
			int g=gcd(a[i],b[i]);
			if(g==0)
				dZ++;
			else{
				String s=a[i]/g+" "+b[i]/g;
				map.put(s,(map.containsKey(s)?map.get(s):0)+1);
			}
		}
		int max=0;
		//System.out.println(map);
		for(String i:map.keySet())
			max=Math.max(max,map.get(i));
		System.out.println(max+dZ);
		// ------------------------
		out.close();
	}
	//------------------------
	private static int gcd(int a,int b){
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