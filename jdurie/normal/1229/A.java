//package cf588d1;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class A {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int n = sc.nextInt();
		long[] a = new long[n], b = new long[n];
		for(int i = 0; i < n; i++)
			a[i] = sc.nextLong();
		for(int i = 0; i < n; i++)
			b[i] = sc.nextLong();
		boolean[] in = new boolean[n];
		for(int i = 0; i < n; i++) 
			if(!in[i]){
				boolean hasEq = false;
				for(int j = i + 1; j < n; j++)
					if(a[i] == a[j]) {
						hasEq = true;
						break;
					}
				if(hasEq)
					for(int j = 0; j < n; j++)
						if((a[i] & a[j]) == a[j]) {
							in[i] = true;
							in[j] = true;
						}
			}
		long sum = 0;
		for(int i = 0; i < n; i++)
			if(in[i])
				sum += b[i];
		out.println(sum);
		out.close();
	}
	public static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	public static class MyScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String next() {
			while (st == null || !st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
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