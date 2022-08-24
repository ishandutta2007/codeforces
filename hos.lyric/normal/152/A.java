import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		new A().run();
	}
	Scanner in = new Scanner(System.in);
	
	void run() {
		for (; in.hasNext(); ) {
			int n = in.nextInt(), m = in.nextInt();
			char[][] cs = new char[n][];
			for (int i = 0; i < n; ++i) {
				cs[i] = in.next().toCharArray();
			}
			char[] best = new char[m];
			for (int i = 0; i < n; ++i) for (int a = 0; a < m; ++a) {
				if (best[a] < cs[i][a]) {
					best[a] = cs[i][a];
				}
			}
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				boolean ok = false;
				for (int a = 0; a < m; ++a) {
					if (best[a] == cs[i][a]) {
						ok = true;
						break;
					}
				}
				if (ok) ++ans;
			}
			System.out.println(ans);
		}
	}
	
	void _out(Object...os) {
		System.out.println(deepToString(os));
	}
}