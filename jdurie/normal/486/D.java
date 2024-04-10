//package a2oj;
import java.util.*;

public class ValidSets {
	static final long MOD = 1000000007;
	static ArrayList<LinkedList<Integer>> tree = new ArrayList<LinkedList<Integer>>();
	static int[] a;
	static int d, n;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		d = sc.nextInt();
		n = sc.nextInt();
		a = new int[n];
		for(int i = 0; i < n; i++) {
			tree.add(new LinkedList<Integer>());
			a[i] = sc.nextInt();
		}
		for(int i = 0; i < n - 1; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			tree.get(u).add(v);
			tree.get(v).add(u);
		}
		sc.close();
		long ans = 0;
		for(int i = 0; i < n; i++)
			ans = (ans + f(i, -1, a[i], i) - 1) % MOD;
		System.out.println(ans);
	}
	static long f(int i, int p, int max, int x) {
		long res = 1;
		for(int j : tree.get(i))
			if(j != p && ((a[j] == max && j < x) || (a[j] < max && a[j] >= max - d)))
				res = res * f(j, i, max, x) % MOD;
		return res + 1;
	}
}