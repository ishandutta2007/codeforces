import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		long n = in.nextInt();
		long k = in.nextInt();
		if (k >= n / 2) {
			System.out.println(n * (n - 1) / 2);
		} else {
			System.out.println(k * (2 * n - k - 1) / 2 + (n - 2 * k) * k + k * (k - 1) / 2);
		}
	}

}