//package cfglobal3;
import java.io.*;
import java.util.*;

public class E{
	// ------------------------
	private static ArrayList<String>swaps=new ArrayList<String>();
	public static class Rock implements Comparable<Rock>{
		int x,i;
		public Rock(int X,int I){
			x=X;
			i=I;
		}
		public int compareTo(Rock r){
			return ((Integer)x).compareTo(r.x);
		}
	}
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		Rock[]s=new Rock[n];
		int[]d=new int[n];
		for(int i=0;i<n;i++)
			s[i]=new Rock(sc.nextInt(),i+1);
		Arrays.sort(s);
		TreeMap<Integer,Integer>t=new TreeMap<Integer,Integer>();
		for(int i=0;i<n;i++){
			int x=sc.nextInt();
			t.put(x,t.containsKey(x)?t.get(x)+1:1);
		}
		for(int i=0;i<n;i++)
			d[i]=pollF(t)-s[i].x;
		int iP=0,iN=0;
		boolean ok=true;
		while(iP<n&&ok){
			if(d[iP]==0){
				iP++;
				iN=Math.max(iN,iP);
			}else if(d[iP]<0)
				ok=false;
			else{
				while(iN<n&&d[iN]>=0)
					iN++;
				if(iN==n)
					ok=false;
				else{
					int k=Math.min(d[iP],-d[iN]);
					//out.println(iP+" "+iN+" "+k);
					d[iP]-=k;
					d[iN]+=k;
					swaps.add(s[iP].i+" "+s[iN].i+" "+k);
				}
			}
		}
		out.println(ok?"YES":"NO");
		if(ok){
			out.println(swaps.size());
			for(String str:swaps)
				out.println(str);
		}
		// ------------------------
		out.close();
	}
	//------------------------
	private static int pollF(TreeMap<Integer,Integer>t){
		int x=t.firstKey();
		if(t.get(x)==1)
			t.pollFirstEntry();
		else
			t.put(x,t.get(x)-1);
		return x;
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