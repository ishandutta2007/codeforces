
import java.io.*;
import java.util.*;

public class E {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		int[]rows=new int[n+1];
		for(int i=1;i<n;i++){
			System.out.println("? 1 1 "+i+" "+n);
			System.out.flush();
			rows[i]=sc.nextInt();
		}
		int[]cols=new int[n+1];
		for(int i=1;i<n;i++){
			System.out.println("? 1 1 "+n+" "+i);
			System.out.flush();
			cols[i]=sc.nextInt();
		}
		HashSet<Integer>goodR=new HashSet<Integer>();
		for(int i=1;i<rows.length;i++)
			if(rows[i]%2!=rows[i-1]%2)
				goodR.add(i);
		HashSet<Integer>goodC=new HashSet<Integer>();
		for(int i=1;i<cols.length;i++)
			if(cols[i]%2!=cols[i-1]%2)
				goodC.add(i);
		if(goodR.isEmpty())
			for(int i:goodC)
				goodR.add(bSearchR(1,n,i,sc));
		if(goodC.isEmpty())
			for(int i:goodR)
				goodC.add(bSearchC(1,n,i,sc));
		String ans="!";
		if(goodR.size()*goodC.size()>2){
			for(int i:goodR)
				for(int j:goodC){
					System.out.println("? "+i+" "+j+" "+i+" "+j);
					System.out.flush();
					if(sc.nextInt()==1)
						ans+=" "+i+" "+j;
				}
		}else
			for(int i:goodR)
				for(int j:goodC)
					ans+=" "+i+" "+j;
		System.out.println(ans);
		// ------------------------
		out.close();
	}
	//------------------------
	private static int bSearchR(int start,int end,int c,MyScanner sc){
		if(start==end)
			return start;
		int mid=(start+end)/2;
		System.out.println("? "+start+" "+c+" "+mid+" "+c);
		System.out.flush();
		if(sc.nextInt()%2==1)
			return bSearchR(start,mid,c,sc);
		else
			return bSearchR(mid+1,end,c,sc);
	}
	private static int bSearchC(int start,int end,int r,MyScanner sc){
		if(start==end)
			return start;
		int mid=(start+end)/2;
		System.out.println("? "+r+" "+start+" "+r+" "+mid);
		System.out.flush();
		if(sc.nextInt()%2==1)
			return bSearchC(start,mid,r,sc);
		else
			return bSearchC(mid+1,end,r,sc);
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