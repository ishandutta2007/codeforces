//package cfed68;
import java.io.*;
import java.util.*;

public class C {
	// ------------------------
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int q=sc.nextInt();
		for(int w=0;w<q;w++){
			char[]s=sc.nextLine().toCharArray();
			char[]t=sc.nextLine().toCharArray();
			char[]p=sc.nextLine().toCharArray();
			int[]leftovers=new int[26];
			int iS=0,iT=0;
			while(iS<s.length&&iT<t.length){
				if(s[iS]==t[iT]){
					iS++;
					iT++;
				}else{
					leftovers[t[iT]-'a']++;
					iT++;
				}
			}
			while(iT<t.length)
				leftovers[t[iT++]-'a']++;
			if(iS!=s.length)
				out.println("NO");
			else{
				for(char c:p)
					leftovers[c-'a']--;
				boolean possible=true;
				for(int i:leftovers)
					if(i>0)
						possible=false;
				out.println(possible?"YES":"NO");
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