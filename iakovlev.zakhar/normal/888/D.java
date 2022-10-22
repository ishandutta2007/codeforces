import java.util.Scanner;

public class D {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		int x = in.nextInt();
		long ans = 1;
		if (x >= 2) {
			ans += n * (n - 1) / 2;
		}
		if (x >= 3) {
			ans += n * (n - 1) * (n - 2) / 3;
		}
		if (x == 4) {
			ans += 3 * n * (n - 1) * (n - 2) * (n - 3) / 8;
		}
		System.out.println(ans);
	}

}