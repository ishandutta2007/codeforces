import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;
import java.io.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}
	Scanner in = new Scanner(System.in);
	
	void run() {
		final long INF = 1001001001001001001L;
		for (; in.hasNext(); ) {
			long m = in.nextLong(), n = in.nextLong();
			long x = in.nextLong(), y = in.nextLong();
			int k = in.nextInt();
			long[] xs = new long[k], ys = new long[k];
			for (int i = 0; i < k; ++i) {
				xs[i] = in.nextLong();
				ys[i] = in.nextLong();
			}
			long ans = 0;
			for (int i = 0; i < k; ++i) {
				long tmp = INF;
				if (xs[i] < 0) {
					if (tmp > (x - 1) / -xs[i]) {
						tmp = (x - 1) / -xs[i];
					}
				} else if (xs[i] > 0) {
					if (tmp > (m - x) / xs[i]) {
						tmp = (m - x) / xs[i];
					}
				}
				if (ys[i] < 0) {
					if (tmp > (y - 1) / -ys[i]) {
						tmp = (y - 1) / -ys[i];
					}
				} else if (ys[i] > 0) {
					if (tmp > (n - y) / ys[i]) {
						tmp = (n - y) / ys[i];
					}
				}
// _out(tmp);
				x += xs[i] * tmp;
				y += ys[i] * tmp;
				ans += tmp;
			}
			System.out.println(ans);
		}
	}
	
	void _out(Object...os) {
		System.out.println(deepToString(os));
	}
}