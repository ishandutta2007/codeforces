import java.util.*;
import java.io.*;
public class D1352 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[]array = new int[n];
			for(int i = 0; i<n; i++) {
				array[i] = readInt();
			}
			int left = 0;
			int right = n-1;
			int alice = array[0];
			int cur = alice+1;
			left++;
			int bob = 0;
			int turn = 1;
			loop:
			while(left<=right) {
				turn++;
				if(turn%2==1) {
					int i = left;
					int sum = 0;
					while(true) {
						sum+=array[i];
						alice+=array[i];
						i++;
						if(i>right) {
							break loop;
						}
						if(sum>=cur) {
							cur = sum+1;
							break;
						}
					}
					left = i;
				}
				else {
					int i = right;
					int sum = 0;
					while(true) {
						sum+=array[i];
						bob+=array[i];
						i--;
						if(i<left) {
							break loop;
						}
						if(sum>=cur) {
							cur = sum+1;
							break;
						}
					}
					right = i;
				}
			}
			pr.println(turn+ " " + alice+ " " + bob);
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