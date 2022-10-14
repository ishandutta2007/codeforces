import java.io.*;
import java.util.*;

public class C {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		//out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		Point[]arr=new Point[n];
		for(int i=0;i<n;i++)
			arr[i]=new Point(sc.nextInt(),sc.nextInt());
		HashSet<Line>set=new HashSet<Line>(n*(n-1)/2);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				set.add(new Line(arr[i],arr[j]));
		HashMap<Long,Integer>slopes=new HashMap<Long,Integer>(set.size());
		long ans=(long)set.size()*(long)(set.size()-1)/2;
		for(Line l:set){
			long m=l.slope();
			int x=slopes.containsKey(m)?slopes.get(m):0;
			ans-=x;
			slopes.put(m,x+1);
		}
		System.out.println(ans);
		// ------------------------
		//out.close();
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
			if(slope()==Double.MAX_VALUE)
				return Integer.MAX_VALUE;
			return (int)(slope()/100000);
		}
		public long slope(){
			if(a==0)
				return Long.MAX_VALUE;
			return (long)(1000000000.0*b/(double)a);
		}
		public String toString(){
			return a+"x + "+b+"y  = "+c;
		}
	}
	private static class Point{
		int x,y;
		public Point(int X,int Y){
			x=X;
			y=Y;
		}
	}
	//public static PrintWriter out;
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