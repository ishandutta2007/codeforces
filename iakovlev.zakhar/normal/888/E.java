import java.util.Scanner;
import java.util.TreeSet;

public class E {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		TreeSet<Integer> set = new TreeSet();
		set.add(1);
		set.add(2);
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		if (n == 1) {
			System.out.println(a[0] % m);
			return;
		}
		TreeSet<Integer> b = new TreeSet<>();
		b.add(0);
		for (int i = 0; i <= n / 2; i++) {
			TreeSet<Integer> b1 = new TreeSet<>();
			for (int l : b) {
				b1.add(l);
				b1.add((l + a[i]) % m);
			}
			b = b1;
		}
		TreeSet<Integer> c = new TreeSet<>();
		c.add(0);
		for (int i = n / 2 + 1; i < a.length; i++) {
			TreeSet<Integer> c1 = new TreeSet<>();
			for (int l : c) {
				c1.add(l);
				c1.add((l + a[i]) % m);
			}
			c = c1;
		}
		if (b.contains(m - 1)) {
			System.out.println(m - 1);
			return;
		}
		int ans = 0;
		for (int l : b) {
			ans = Math.max(ans, (l + c.last()) % m);
			ans = Math.max(ans, (l + c.floor(m - 1 - l)));
		}
		System.out.println(ans);
	}

}