import java.io.*;
import java.util.*;

public class B{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		String s=sc.nextLine();
		char[]s1=s.toCharArray();
		int a=0;
		for(char c:s1)
			if(c=='a')
				a++;
		char[]s2=new char[s1.length-a];
		int ind=0;
		for(char c:s1)
			if(c!='a')
				s2[ind++]=c;
		if(s2.length%2==1)
			System.out.println(":(");
		else{
			boolean good=true;
			for(int i=0;i<s2.length/2;i++)
				if(s2[i]!=s2[i+s2.length/2])
					good=false;
			for(int i=s1.length-s2.length/2;i<s1.length;i++)
				if(s1[i]=='a')
					good=false;
			if(!good)
				System.out.println(":(");
			else
				System.out.println(s.substring(0,s.length()-s2.length/2));
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