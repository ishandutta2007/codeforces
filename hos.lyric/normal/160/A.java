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
	void _out(Object...os) {
		System.out.println(deepToString(os));
	}
	
	void run() {
		for (; in.hasNext(); ) {
			int n = in.nextInt();
			int[] as = new int[n];
			for (int i = 0; i < n; ++i) {
				as[i] = in.nextInt();
			}
			sort(as);
			int sum = 0;
			for (int i = 0; i < n; ++i) {
				sum += as[i];
			}
			int ans = 0;
			int now = 0;
			for (int i = n - 1; i >= 0; --i) {
				if (now > sum - now) break;
				++ans;
				now += as[i];
			}
			System.out.println(ans);
		}
	}
}