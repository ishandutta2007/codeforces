import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;
import java.io.*;

public class C {
	public static void main(String[] args) {
		new C().run();
	}
	Scanner in = new Scanner(System.in);
	
	void run() {
		final long MO = 1000000007;
		for (; in.hasNext(); ) {
			int n = in.nextInt(), m = in.nextInt();
			char[][] cs = new char[n][m];
			for (int i = 0; i < n; ++i) {
				cs[i] = in.next().toCharArray();
			}
			long ans = 1;
			for (int j = 0; j < m; ++j) {
				boolean[] is = new boolean[26];
				for (int i = 0; i < n; ++i) {
					is[cs[i][j] - 'A'] = true;
				}
				int tmp = 0;
				for (int a = 0; a < is.length; ++a) if (is[a]) ++tmp;
				ans = ans * tmp % MO;
			}
			System.out.println(ans);
		}
	}
	
	void _out(Object...os) {
		System.out.println(deepToString(os));
	}
}