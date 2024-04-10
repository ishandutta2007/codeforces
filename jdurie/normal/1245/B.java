//package cf597d2;
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		int t = sc.nextInt();
		while(t-- > 0) {
			int n = sc.nextInt(), R = sc.nextInt(), P = sc.nextInt(), S = sc.nextInt();
			char[] st = sc.nextLine().toCharArray();
			int r = 0, p = 0, s = 0;
			for(char c : st)
				if(c == 'R') r++;
				else if(c == 'P') p++;
				else s++;
			int playR = min(R, s), playP = min(P, r), playS = min(S, p);
			int spareR = R - playR, spareP = P - playP, spareS = S - playS;
			if(playR + playP + playS >= (n + 1) / 2) {
				out.println("YES");
				for(char c : st) {
					if(c == 'R') {
						if(playP > 0) {
							out.print("P");
							playP--;
						} else if(spareR > 0) {
							out.print("R");
							spareR--;
						} else if(spareS > 0) {
							out.print("S");
							spareS--;
						}
					} else if(c == 'P') {
						if(playS > 0) {
							out.print("S");
							playS--;
						} else if(spareR > 0) {
							out.print("R");
							spareR--;
						} else if(spareP > 0) {
							out.print("P");
							spareP--;
						}
					} else {
						if(playR > 0) {
							out.print("R");
							playR--;
						} else if(spareP > 0) {
							out.print("P");
							spareP--;
						} else if(spareS > 0) {
							out.print("S");
							spareS--;
						}
					}
				}
				out.println();
			} else
				out.println("NO");
		}
		out.close();
	}
	static PrintWriter out  = new PrintWriter(new BufferedOutputStream(System.out));
	static class MyScanner {
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