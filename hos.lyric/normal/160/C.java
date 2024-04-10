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
	// Scanner in = new Scanner(System.in);
	void _out(Object...os) {
		System.out.println(deepToString(os));
	}
	boolean eof = false;
	int _in() {
		int x = 0, c;
		try {
			while ((c = System.in.read()) < '0' || '9' < c) { if (c == -1) { eof = true; return -1; } if (c == '-') return -_in(); }
			do { x = (x << 3) + (x << 1) + (c - '0'); } while ('0' <= (c = System.in.read()) && c <= '9');
		} catch (Exception e) {}
		return x;
	}
	long _inLong() {
		long x = 0, c;
		try {
			while ((c = System.in.read()) < '0' || '9' < c) { if (c == -1) { eof = true; return -1; } if (c == '-') return -_inLong(); }
			do { x = (x << 3) + (x << 1) + (c - '0'); } while ('0' <= (c = System.in.read()) && c <= '9');
		} catch (Exception e) {}
		return x;
	}
	
	void mySort(int[] as) {
		int n = as.length;
		Integer[] bs = new Integer[n];
		for (int i = 0; i < n; ++i) bs[i] = as[i];
		sort(bs);
		for (int i = 0; i < n; ++i) as[i] = bs[i];
	}
	
	void run() {
		for (; ; ) {
			int n = _in();
			if (eof) break;
			long k = _inLong() - 1;
			int[] as = new int[n];
			for (int i = 0; i < n; ++i) {
				as[i] = _in();
			}
			// sort(as);
			mySort(as);
			for (int i = 0; i < n; ) {
				int j;
				for (j = i; j < n && as[i] == as[j]; ++j);
				if (0 <= k && k < (long)n * (j - i)) {
					System.out.println(as[i] + " " + as[(int)(k / (j - i))]);
					break;
				}
				k -= (long)n * (j - i);
				i = j;
			}
		}
	}
}