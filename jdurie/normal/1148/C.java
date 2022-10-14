//package cfglobal3;
import java.io.*;
import java.util.*;

public class C{
	// ------------------------
	private static int[]perm;
	private static int[]rlkup;
	private static int n;
	private static ArrayList<String>swaps=new ArrayList<String>();
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		n=sc.nextInt();
		perm=new int[n];
		rlkup=new int[n];
		for(int i=0;i<n;i++){
			perm[i]=sc.nextInt()-1;
			rlkup[perm[i]]=i;
		}
		for(int i=n-1;i>=0;i--)
			if(i!=rlkup[i]&&Math.abs(i-rlkup[i])<(n/2))
				tripleSwap(rlkup[i],i);
			else if(i!=rlkup[i])
				swap(i,rlkup[i]);
		out.println(swaps.size());
		for(String s:swaps)
			out.println(s);
		// ------------------------
		out.close();
	}
	//------------------------
	private static void tripleSwap(int i1,int i2){
		int i3=i1/(n/2)==0?n-1:0;
		int i4=i2/(n/2)==0?n-1:0;
		if(i3==i4){
			swap(i1,i3);
			swap(i2,i3);
			swap(i1,i3);
		}else{
			swap(i1,i3);
			swap(i2,i4);
			swap(i3,i4);
			swap(i1,i3);
			swap(i2,i4);
		}
	}
	private static void swap(int i1,int i2){
		swaps.add((i1+1)+" "+(i2+1));
		int temp=perm[i1];
		perm[i1]=perm[i2];
		perm[i2]=temp;
		rlkup[perm[i1]]=i1;
		rlkup[perm[i2]]=i2;
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