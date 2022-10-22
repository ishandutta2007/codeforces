import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n - 1];
		int[] b = new int[n - 1];
		int y = 0;
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			if (x == 0) {
				y = 1;
			} else {
				a[i - y] = x;
			}
		}
		y = 0;
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			if (x == 0) {
				y = 1;
			} else {
				b[i - y] = x;
			}
		}
		int x = 0;
		for (int i = 0; i < b.length; i++) {
			if (b[i] == a[0]) {
				x = i;
			}
		}
		for (int i = 0; i < b.length; i++) {
			if (b[(x + i) % (n - 1)] != a[i]) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}

}