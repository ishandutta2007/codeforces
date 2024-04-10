
import java.io.*;
import java.util.*;

public class E{
	// ------------------------
	static int n,k;
	static long[]a;
	static final long MOD=998244353;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		n=sc.nextInt();
		k=sc.nextInt();
		a=new long[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextLong();
		if(hasPar(a))
			out.println(0);
		else{
			long ans=1;
			for(int i=0;i<n;i++){
				if(i<2)
					ans=(ans*aaa(getL(i),-1,getJ(i)))%MOD;
				else if(a[i]==-1&&a[i-2]!=-1)
					ans=(ans*aaa(getL(i),i-2,getJ(i)))%MOD;
			}
			out.println(ans);
		}
		// ------------------------
		out.close();
	}
	//------------------------
	static int getL(int i){
		int j=i,ct=0;
		while(j<n&&a[j]==-1){
			j+=2;
			ct++;
		}
		return ct;
	}
	static int getJ(int i){
		int j=i;
		while(j<n&&a[j]==-1)
			j+=2;
		return j>=n?-1:j;
	}
	static boolean hasPar(long[]a){
		for(int i=2;i<n;i++)
			if(a[i]==a[i-2]&&a[i]!=-1)
				return true;
		return false;
	}
	private static long pow(long x,long p){
		if(p==0)
			return 1;
		long a=pow(x,p/2);
		return (((a*a)%MOD)*(p%2==1?x:1))%MOD;
	}
	static long aaa(int l,int left,int right){
		if(left==-1&&right==-1)
			return k*pow(k-1,l-1)%MOD;
		else if(left==-1||right==-1)
			return pow(k-1,l);
		else{
			long q=a[right];
			long ways=k-1,qWays=a[left]==q?0:1;
			for(int i=left+4;i<right;i+=2){
				qWays=(ways-qWays+MOD)%MOD;
				ways=(k-1)*ways%MOD;
			}
			return (ways-qWays+MOD)%MOD;
		}
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