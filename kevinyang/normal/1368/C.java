import java.util.*;
import java.io.*;
public class C1368 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int n = readInt();
		/*
		 0000000000
		 0000000000
		 0000000000
		 0000000000
		 0000022200
		 0220020200
		 222222020
		 0220020200
		 0000022200
		
		 */
		
			//x = 0 and 2
			int t = n/4;
			int rem = n%4;
			int total = 20000;
			total+=t*12;
			total+=3*rem;
			total+=2;
			pr.println(total);
			for(int j = 0; j<10000; j++) {
				pr.println(2+ " " + j); pr.println(0+" " + j);
			}
			pr.println("1 0"); pr.println("1 9999");
			
			for(int j = 1; j<=t; j++) {
				int num = 11*j;
				pr.println(1+" " + num);
				pr.println(-1+" " + num);
				pr.println(3+" " + num);
				pr.println(-2+" " + num);
				pr.println(4+" " + num);
				pr.println(4+" " + (num+1));
				pr.println(4+" " + (num+2));
				pr.println(-2+" " + (num+1));
				pr.println(-2+" " + (num+2));
				pr.println(-1+" " + (num+2));
				pr.println(1+" " + (num+2));
				pr.println(3+" " + (num+2));
				
			}
			if(rem==1) {
				pr.println("0 -1");pr.println("-1 -1");pr.println("-1 0");
			}
			else if(rem==2) {
				pr.println("0 -1");pr.println("-1 -1");pr.println("-1 0");
				pr.println("2 -1");pr.println("3 -1");pr.println("3 0");
			}
			else if(rem==3) {
				pr.println("0 -1");pr.println("-1 -1");pr.println("-1 0");
				pr.println("2 -1");pr.println("3 -1");pr.println("3 0");
				pr.println("0 10000");pr.println("-1 10000");pr.println("-1 9999");
			}
		
		pr.close();
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readChar () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}