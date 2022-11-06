import java.util.*;
import java.io.*;
public class C712 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int y = readInt(); int x = readInt();
		int[]array = new int[3];
		array[0] = x; array[1] = x; array[2] = x;
		int count = 0;
		while(true) {
			int nxt = array[0]+array[1]-1;
			if(y>nxt) {
				array[2] = nxt; count++;
			}
			else {
				count+=3;
				break;
			}
			nxt = array[0]+array[2]-1;
			if(y>nxt) {
				array[1] = nxt; count++;
			}
			else {
				count+=3;
				break;
			}
			nxt = array[1]+array[2]-1;
			if(y>nxt) {
				array[0] = nxt; count++;
			}
			else {
				count+=3;
				break;
			}
		}
		pr.println(count);
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