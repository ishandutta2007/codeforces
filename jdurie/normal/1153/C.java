
import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		if(n%2!=0)
			System.out.println(":(");
		else{
			char[]s=sc.nextLine().toCharArray();
			int opens=0;
			for(char c:s)
				if(c=='(')
					opens++;
			char[]newS=new char[n];
			int i=0;
			for(char c:s)
				if(c!='?')
					newS[i++]=c;
				else{
					if(opens<n/2){
						opens++;
						newS[i++]='(';
					}else
						newS[i++]=')';
				}
			boolean good=true;
			int ct=0;
			for(int w=0;w<newS.length;w++){
				char c=newS[w];
				if(c=='(')
					ct++;
				else
					ct--;
				if(ct<=0&&w!=n-1)
					good=false;
			}
			if(ct!=0)
				good=false;
			if(!good)
				System.out.println(":(");
			else{
				for(char c:newS)
					out.print(c);
				out.println();
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