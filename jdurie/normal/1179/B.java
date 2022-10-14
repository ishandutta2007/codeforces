//package cf569d1;
import java.io.*;
import java.util.*;

public class B {
	// ------------------------
	static int n,m;
	static LinkedList<String>squares=new LinkedList<String>();
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		n=sc.nextInt();
		m=sc.nextInt();
		fill(1,n);
		/*String st=squares.removeFirst();
		HashSet<String>set=new HashSet<String>();
		while(!squares.isEmpty()){
			System.out.println(st);
			String d=delta(squares.getFirst(),st);
			if(set.contains(d))
				System.out.println("!"+d);
			set.add(d);
			st=squares.removeFirst();
		}
		System.out.println(st);
		if(set.size()!=n*m-1)
			System.out.println("YOU FUCKED UP");*/
		for(String s:squares)
			out.println(s);

		//out.println(squares.contains("1 501"));
		// ------------------------
		out.close();
	}
	//------------------------
	static String delta(String a,String b){
		String[]aArr=a.split(" "),bArr=b.split(" ");
		int dx=Integer.parseInt(bArr[0])-Integer.parseInt(aArr[0]);
		int dy=Integer.parseInt(bArr[1])-Integer.parseInt(aArr[1]);
		return dx+" "+dy;
	}
	static void fill(int r1,int r2){
		if(r1==r2){
			for(int i=1;i<=(m+1)/2;i++){
				squares.add(r1+" "+i);
				if(i!=m+1-i)
					squares.add(r1+" "+(m+1-i));
			}
		}else{
			for(int i=0;i<m;i++){
				squares.add(r1+" "+(1+i));
				squares.add(r2+" "+(m-i));
			}
			if(Math.abs(r1-r2)!=1)
				fill(r1+1,r2-1);
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