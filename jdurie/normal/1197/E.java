
import java.io.*;
import java.util.*;

public class E {
	// ------------------------
	static class O implements Comparable<O>{
		int out,in,idx;
		public O(int o,int i,int d){
			out=o;
			in=i;
			idx=d;
		}
		public int compareTo(O other){
			if(other.out==out&&other.in==in)
				return idx-other.idx;
			if(other.out==out)
				return in-other.in;
			return out-other.out;
		}
	}
	static class I implements Comparable<I>{
		int out,in,idx;
		public I(O o){
			out=o.out;
			in=o.in;
			idx=o.idx;
		}
		public int compareTo(I other){
			if(other.out==out&&other.in==in)
				return idx-other.idx;
			if(other.in==in)
				return out-other.out;
			return in-other.in;
		}
	}
	static class P{
		long es;
		long ct;
		public P(long e,long c){
			es=e;
			ct=c;
		}
		public String toString(){
			return es+":"+ct;
		}
	}
	static long MOD=1000000007;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		O[]matO=new O[n];
		I[]matI=new I[n];
		long maxIn=0;
		for(int i=0;i<n;i++){
			matO[i]=new O(sc.nextInt(),sc.nextInt(),i);
			matI[i]=new I(matO[i]);
			maxIn=Math.max(maxIn,matO[i].in);
		}
		Arrays.sort(matO);
		Arrays.sort(matI);
		long minES=Integer.MAX_VALUE;
		long es=Integer.MAX_VALUE,ct=0;
		HashMap<String,P>map=new HashMap<String,P>();
		long ans=0;
		int index=0;
		for(int i=0;i<n;i++){
			while(index<n&&matO[index].out<=matI[i].in){
				P p=map.get(matO[index].out+"/"+matO[index].in);
				if(p.es<es){
					es=p.es;
					ct=p.ct;
				}else if(p.es==es){
					ct=(ct+p.ct)%MOD;
				}
				index++;
			}
			P p=new P(matI[i].in-matI[i].out,1);
			if(es<0){
				p.es+=es;
				p.ct=ct;
			}
			if(matI[i].out>maxIn){
				if(p.es+matI[i].out==minES)
					ans=(ans+p.ct)%MOD;
				else if(p.es+matI[i].out<minES){
					ans=p.ct;
					minES=p.es+matI[i].out;
				}
			}
			String s=matI[i].out+"/"+matI[i].in;
			map.put(s, p);
		}
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