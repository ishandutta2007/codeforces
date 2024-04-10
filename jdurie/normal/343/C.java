//package a2oj;
import java.util.*;

public class ReadTime {
	static int n, m;
	static long[] h;
	static TreeSet<Long> p = new TreeSet<Long>();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		h = new long[n];
		for(int i = 0; i < n; i++)
			h[i] = sc.nextLong();
		for(int i = 0; i < m; i++)
			p.add(sc.nextLong());
		sc.close();
		System.out.println(bSearch(0, 20000000000L));
	}
	private static long bSearch(long l, long r) {
		if(l == r)
			return l;
		long m = (l + r) / 2;
		if(works(m))
			return bSearch(l, m);
		return bSearch(m + 1, r);
	}
	private static boolean works(long l) {
		Long next = p.first();
		for(int i = 0; i < n; i++) {
			if(h[i] > next) {
				if(h[i] - next > l)
					return false;
				long finalPos = Math.max(2 * next + l - h[i], h[i] + (l - h[i] + next) / 2);
				next = p.ceiling(finalPos + 1);
			} else
				next = p.ceiling(h[i] + l + 1);
			if(next == null)
				break;
		}
		return next == null;
	}
}