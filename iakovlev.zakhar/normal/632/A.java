import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int p = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			String s = in.next();
			if (s.equals("half")) {
				a[n - i - 1] = 0;
			} else {
				a[n - i - 1] = 1;
			}
		}
		long x = 2;
		long b = 1;
		for (int i = 1; i < a.length; i++) {
			if (a[i] == 1) {
				x = 2 * x + 2;
				b++;
			} else {
				x *= 2;
			}
		}
		long d = (x - b) * p / 2;
		System.out.println(d);
	}

}