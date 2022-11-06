import java.util.*;
import java.io.*;
public class C1351 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			String s = next();
			Set<Long>set = new HashSet<Long>();
			int curx = 0;
			int cury = 0;
			int time = 0;
			for(int i = 0; i<s.length(); i++) {
				int num = set.size();
				if(s.charAt(i)=='N') {
					set.add((long)curx*1000000+(long)curx*1000000+cury+cury+1);
					if(set.size()==num)time+=1;
					else time+=5;
					cury++;
				}
				else if(s.charAt(i)=='S') {
					set.add((long)curx*1000000+(long)curx*1000000+cury+cury-1);
					if(set.size()==num)time+=1;
					else time+=5;
					cury--;
				}
				else if(s.charAt(i)=='E') {
					set.add((long)curx*1000000+((long)curx+1)*1000000+cury+cury);
					if(set.size()==num)time+=1;
					else time+=5;
					curx++;
				}
				else if(s.charAt(i)=='W') {
					set.add((long)curx*1000000+((long)curx-1)*1000000+cury+cury);
					if(set.size()==num)time+=1;
					else time+=5;
					curx--;
				}
			}
			pr.println(time);
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