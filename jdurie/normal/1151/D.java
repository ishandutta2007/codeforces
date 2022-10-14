
import java.io.*;
import java.util.*;

public class D {
	// ------------------------
	private static int n;
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		n=sc.nextInt();
		Person[]arr=new Person[n];
		for(int i=0;i<n;i++)
			arr[i]=new Person(sc.nextInt(),sc.nextInt());
		Arrays.sort(arr);
		long ans=0;
		for(int i=0;i<n;i++)
			ans+=arr[i].value(i);
		System.out.println(ans);
		// ------------------------
		out.close();
	}
	//------------------------
	private static class Person implements Comparable<Person>{
		long a;
		long b;
		public Person(long a,long b){
			this.a=a;
			this.b=b;
		}
		public int compareTo(Person p){
			return -((Long)(a+p.b-b-p.a)).compareTo(b+p.a-a-p.b);
		}
		public String toString(){
			return a+" "+b;
		}
		public long value(long i){
			return a*i+b*(n-1-i);
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