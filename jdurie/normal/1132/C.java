import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),q=sc.nextInt();
		int[]l=new int[q];
		int[]r=new int[q];
		int[]ptrsAt=new int[n];
		for(int i=0;i<q;i++){
			l[i]=sc.nextInt()-1;
			r[i]=sc.nextInt()-1;
			ptrsAt[r[i]]++;
			if(l[i]>0)
				ptrsAt[l[i]-1]--;
		}
		for(int i=n-2;i>=0;i--)
			ptrsAt[i]+=ptrsAt[i+1];
		int tot=n;
		int[]ones=new int[n];
		int[]twos=new int[n];
		for(int i=0;i<n;i++){
			if(i>0){
				ones[i]=ones[i-1];
				twos[i]=twos[i-1];
			}
			if(ptrsAt[i]==1)
				ones[i]++;
			else if(ptrsAt[i]==2)
				twos[i]++;
			else if(ptrsAt[i]==0)
				tot--;
		}
		int min=Integer.MAX_VALUE;
		for(int i=0;i<q;i++)
			for(int j=0;j<i;j++){
					int num=0;
					int x=l[i]<l[j]?i:j;
					int y=x==i?j:i;
					int l1=l[x],r1=r[x],l2=l[y],r2=r[y];
					if(l2<=r1){
						int rR=Math.min(r1, r2);
						num+=twos[rR]-(l2==0?0:twos[l2-1]);
						//System.out.print(num+" ");
						l2=rR+1;
						if(r1==rR)
							r1=l2-1;
						if(r2==rR)
							r2=l2-1;
					}
					if(r1>=0&&r1>=l1)
						num+=ones[r1]-(l1==0?0:ones[l1-1]);
					if(l2<n&&l2<=r2)
						num+=ones[r2]-(l2==0?0:ones[l2-1]);
					min=Math.min(min,num);
					//System.out.println(i+" "+j+" "+num);
				}
		out.println(tot-min);
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