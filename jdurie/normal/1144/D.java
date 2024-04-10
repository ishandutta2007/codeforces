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
		HashMap<Integer,Integer>freq=new HashMap<Integer,Integer>();
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
			freq.put(a[i],freq.containsKey(a[i])?freq.get(a[i])+1:1);
		}
		int max=-1,val=0;
		for(int i:freq.keySet())
			if(freq.get(i)>val){
				max=i;
				val=freq.get(i);
			}
		int[]distFront=new int[n];
		distFront[0]=a[0]==max?0:1000000000;
		for(int i=1;i<n;i++)
			if(a[i]==max)
				distFront[i]=0;
			else
				distFront[i]=distFront[i-1]+1;
		int[]distBack=new int[n];
		distBack[n-1]=a[n-1]==max?0:1000000000;
		for(int i=n-2;i>=0;i--)
			if(a[i]==max)
				distBack[i]=0;
			else
				distBack[i]=distBack[i+1]+1;
		TreeMap<Integer,HashSet<String>>queries=new TreeMap<Integer,HashSet<String>>();
		int q=0;
		for(int i=0;i<n;i++)
			if(a[i]!=max){
				q++;
				int d=Math.min(distFront[i],distBack[i]);
				if(!queries.containsKey(d))
					queries.put(d,new HashSet<String>());
				queries.get(d).add((a[i]<max?"1":"2")+" "+(i+1)+" "+(d==distFront[i]?i:(i+2)));
			}
		System.out.println(q);
		for(int i:queries.keySet())
			for(String s:queries.get(i))
				System.out.println(s);
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