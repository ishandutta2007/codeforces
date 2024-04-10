//package helvetic2019mirror;
import java.util.*;

public class B1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int s = sc.nextInt(), b = sc.nextInt();
		int[] a = new int[s];
		for(int i = 0; i < s; i++)
			a[i] = sc.nextInt();
		Pair[] d = new Pair[b];
		for(int i = 0; i < b; i++)
			d[i] = new Pair(sc.nextInt(), sc.nextInt(), i);
		Arrays.sort(d);
		for(int i = 1; i < b; i++)
			d[i].g += d[i-1].g;
		for(int i = 0; i < s; i++)
			System.out.print(bSearch(d, 0, b - 1, a[i]) + " ");
		sc.close();
	}
	public static long bSearch(Pair[]d, int l, int r, int a) {
		if(d[l].d > a)
			return 0;
		if(l == r)
			return d[l].g;
		int m = (l + r + 1) / 2;
		if(d[m].d > a)
			return bSearch(d, l, m - 1, a);
		return bSearch(d, m, r, a);
	}
	static class Pair implements Comparable<Pair> {
		int d, i;
		long g;
		public Pair(int D, long G, int I) {
			d = D;
			g = G;
			i = I;
		}
		public int compareTo(Pair p) {
			if(d == p.d)
				return i - p.i;
			return d - p.d;
		}
 	}
}