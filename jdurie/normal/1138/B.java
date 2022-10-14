import java.io.*;
import java.util.*;

public class B {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		boolean[]a=new boolean[n];
		String sA=sc.nextLine();
		for(int i=0;i<n;i++)
			a[i]=sA.charAt(i)=='1';
		boolean[]b=new boolean[n];
		String sB=sc.nextLine();
		for(int i=0;i<n;i++)
			b[i]=sB.charAt(i)=='1';
		int[]cts=new int[4];
		for(int i=0;i<n;i++)
			if(a[i]&&b[i])
				cts[0]++;
			else if(a[i])
				cts[1]++;
			else if(b[i])
				cts[2]++;
			else
				cts[3]++;
		int[]inFirst={0,cts[1],0,0};
		int secCt=cts[2],secCt2=0;
		int d=cts[1]-cts[2];
		inFirst[0]+=Math.min(Math.max(-d,0),cts[0]);
		secCt2+=Math.min(Math.max(d,0),cts[0]);
		cts[0]=Math.max(cts[0]-Math.abs(d),0);
		inFirst[0]+=cts[0]/2;
		secCt2+=cts[0]/2;
		if(cts[0]%2==1){
			if(inFirst[0]+inFirst[1]>secCt+secCt2)
				secCt++;
			else
				inFirst[0]++;
		}
		while(inFirst[0]+inFirst[1]>secCt+secCt2&&cts[3]>0&&inFirst[1]>0){
			inFirst[1]--;
			cts[3]--;
		}
		while(secCt+secCt2>inFirst[0]+inFirst[1]&&cts[3]>0&&secCt>0){
			secCt--;
			inFirst[2]++;
			cts[3]--;
		}
		inFirst[3]=n/2-inFirst[0]-inFirst[1]-inFirst[2];
		//System.out.println(inFirst[0]+" "+inFirst[1]+" "+inFirst[2]+" "+inFirst[3]);
		if(inFirst[0]+inFirst[1]!=secCt+secCt2)
			System.out.println(-1);
		else
			for(int i=0;i<n;i++){
				int ind=2*(a[i]?0:1)+(b[i]?0:1);
				if(inFirst[ind]>0){
					out.print((i+1)+" ");
					inFirst[ind]--;
				}
			}
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