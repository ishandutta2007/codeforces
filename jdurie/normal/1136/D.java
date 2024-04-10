import java.io.*;
import java.util.*;

public class D {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),m=sc.nextInt();
		int[]p=new int[n];
		for(int i=0;i<n;i++)
			p[i]=sc.nextInt()-1;
		HashMap<Integer,HashSet<Integer>>swaps=new HashMap<Integer,HashSet<Integer>>();
		for(int i=0;i<n;i++)
			swaps.put(i,new HashSet<Integer>());
		for(int i=0;i<m;i++)
			swaps.get(sc.nextInt()-1).add(sc.nextInt()-1);
		HashSet<Integer>blocks=new HashSet<Integer>();
		int ans=0;
		for(int i=n-2;i>=0;i--){
			if(swaps.get(p[i]).contains(p[n-1])&&swaps.get(p[i]).size()>blocks.size()){
				boolean good=true;
				for(int b:blocks)
					if(!swaps.get(p[i]).contains(b)){
						good=false;
						break;
					}
				if(good)
					ans++;
				else
					blocks.add(p[i]);
			}else
				blocks.add(p[i]);
		}
		System.out.println(ans);
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