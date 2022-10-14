//package cfglobal3;
import java.io.*;
import java.util.*;

public class D{
	// ------------------------
	public static class Pair implements Comparable<Pair>{
		int a, b, i;
		public Pair(int A,int B,int I){
			a=A;
			b=B;
			i=I;
		}
		public int compareTo(Pair p){
			return ((Integer)a).compareTo(p.a);
		}
	}
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		ArrayList<Pair>g=new ArrayList<Pair>();
		ArrayList<Pair>l=new ArrayList<Pair>();
		for(int i=0;i<n;i++){
			Pair p=new Pair(sc.nextInt(),sc.nextInt(),i+1);
			if(p.a>p.b)
				g.add(p);
			else
				l.add(p);
		}
		if(g.size()>l.size()){
			Collections.sort(g);
			out.println(g.size());
			for(Pair p:g)
				out.print(p.i+" ");
			out.println();
		}else{
			Collections.sort(l);
			out.println(l.size());
			for(int i=l.size()-1;i>=0;i--)
				out.print(l.get(i).i+" ");
			out.println();
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