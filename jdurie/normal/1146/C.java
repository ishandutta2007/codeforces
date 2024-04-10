import java.io.*;
import java.util.*;

public class C{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int t=sc.nextInt();
		for(int w=0;w<t;w++){
			int n=sc.nextInt(),max=0;
			for(int i=0;i<=7;i++){
				HashSet<Integer>s1=new HashSet<Integer>();
				HashSet<Integer>s2=new HashSet<Integer>();
				for(int x=1;x<=n;x++)
					if((x&(1<<i))>0)
						s1.add(x);
					else
						s2.add(x);
				if(!s1.isEmpty()&&!s2.isEmpty()){
					System.out.print(s1.size()+" "+s2.size());
					for(int x:s1)
						System.out.print(" "+x);
					for(int x:s2)
						System.out.print(" "+x);
					System.out.println();
					System.out.flush();
					max=Math.max(max,sc.nextInt());
				}
			}
			System.out.println("-1 "+max);
			System.out.flush();
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