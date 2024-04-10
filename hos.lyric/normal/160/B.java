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
	void _out(Object...os) {
		System.out.println(deepToString(os));
	}
	
	void run() {
		for (; in.hasNext(); ) {
			int n = in.nextInt();
			char[] cs = in.next().toCharArray();
			int[] as = new int[n], bs = new int[n];
			for (int i = 0; i < n; ++i) {
				as[i] = cs[i];
			}
			for (int i = 0; i < n; ++i) {
				bs[i] = cs[n + i];
			}
			sort(as);
			sort(bs);
			boolean ans0 = true, ans1 = true;
			for (int i = 0; i < n; ++i) {
				if (!(as[i] < bs[i])) ans0 = false;
				if (!(as[i] > bs[i])) ans1 = false;
			}
			System.out.println((ans0 || ans1) ? "YES" : "NO");
		}
	}
}