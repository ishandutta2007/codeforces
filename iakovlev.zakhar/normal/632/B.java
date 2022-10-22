import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		String s = in.next();
		long bob = 0;
		int[] b = new int[n];
		for (int i = 0; i < a.length; i++) {
			if (s.charAt(i) == 'A') {
				b[i] = 1;
			} else {
				bob += a[i];
				b[i] = -1;
			}
		}
		long maxL = bob;
		long l = bob;
		for (int i = 0; i < b.length; i++) {
			l += b[i] * a[i];
			if (l > maxL) {
				maxL = l;
			}
		}
		long maxR = bob;
		long r = bob;
		for (int i = b.length - 1; i >= 0; i--) {
			r += b[i] * a[i];
			if (r > maxR) {
				maxR = r;
			}
		}
		System.out.println(Math.max(maxL, maxR));
	}

}