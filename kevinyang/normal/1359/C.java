import java.util.*;
import java.io.*;
public class C1359 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		loop:
		while(t--!=0) {
			int h = readInt(); int c = readInt(); int temp = readInt();
			int sum = h+c;
			if(h==temp) {
				pr.println(1); continue;
			}
			if(sum==temp*2) {
				pr.println(2); continue;
			}
			if((double)sum/2>temp) {
				pr.println(2); continue;
			}
			double close = 0;
			long times = 0;
			if(h>temp & (double)sum/2<temp) {
				long low = 0;
				long high = (long)1e9;
				long mid = (low+high)/2;
				while(low<high-1) {
					double ans = (h+(double)sum*mid)/(2*mid+1);
					if(Math.abs(ans-temp)<=0.000000000000001) {
						pr.println(2*mid+1);
						continue loop;
					}
					if(ans-temp>0.000000000000001) {
						low = mid;
					}
					else {
						high = mid;
					}
					mid = (low+high)/2;
				}
				double s1 = (h+(double)sum*low)/((long)2*low+1);
				double s2 = (h+(double)sum*high)/((long)2*high+1);
				
				if(Math.abs(s1-temp)<=Math.abs(s2-temp)+0.000000000000001) {
					close = Math.abs(s1-temp);
					times = 2*low+1;
				}
				else {
					close = Math.abs(s2-temp);
					times = 2*high+1;
				}
				if(low>6)
					for(int i = -5; i<=5; i++) {
						double an = (h+(double)sum*(low+i))/(2*(low+i)+1);
						if(Math.abs(an-temp)<=close+0.000000000000001) {
							close = Math.abs(an-temp);
							times = 2*(low+i)+1;
						}
					}
				pr.println(times);
				/*
				 
				if(Math.abs((double)sum/2-temp)<=close+0.00000000000001) {
					if(h-temp<=Math.abs((double)sum/2-temp)+0.00000000001) {
						pr.println(1);
					}
					else {
						pr.println(2);
					}
					continue;
				}
				else {
					pr.println(times);
					continue;
				}
				*/
			}
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
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}