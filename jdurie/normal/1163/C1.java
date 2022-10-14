import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		Point[]arr=new Point[n];
		for(int i=0;i<n;i++)
			arr[i]=new Point(sc.nextInt(),sc.nextInt());
		HashSet<Line>set=new HashSet<Line>();
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				set.add(new Line(arr[i],arr[j]));
		HashMap<String,Integer>slopes=new HashMap<String,Integer>();
		for(Line l:set){
			String m=l.slope();
			slopes.put(m,slopes.containsKey(m)?slopes.get(m)+1:1);
		}
		long ans=set.size()*(set.size()-1)/2;
		for(String s:slopes.keySet())
			ans-=slopes.get(s)*(slopes.get(s)-1)/2;
		out.println(ans);
		// ------------------------
		out.close();
	}
	//------------------------
	private static class Line{
		int a,b,c;
		Point P1,P2;
		public Line(Point p1,Point p2){
			a=p1.y-p2.y;
			b=p2.x-p1.x;
			c=a*p1.x+b*p1.y;
			P1=p1;
			P2=p2;
		}
		public boolean equals(Object o){
			Line l=(Line)o;
			return a*l.P1.x+b*l.P1.y==c&&a*l.P2.x+b*l.P2.y==c;
		}
		public int hashCode(){
			return 4;
		}
		public String slope(){
			int g=gcd(Math.abs(P1.x-P2.x),Math.abs(P1.y-P2.y));
			int a=(P1.y-P2.y)/g,b=(P1.x-P2.x)/g;
			if(a<0){
				a*=-1;
				b*=-1;
			}
			if(a==0)
				b=1;
			if(b==0)
				a=1;
			return a+" "+b;
		}
		public String toString(){
			return a+"x + "+b+"y  = "+c;
		}
	}
	private static int gcd(int a,int b){
		return b==0?a:gcd(b,a%b);
	}
	private static class Point{
		int x,y;
		public Point(int X,int Y){
			x=X;
			y=Y;
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