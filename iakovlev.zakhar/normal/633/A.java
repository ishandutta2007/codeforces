import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int x = Math.max(a, b);
		int y = Math.min(a, b);
		if (c % a == 0 || c % b == 0) {
			System.out.println("Yes");
			return;
		}
		for (int i = 0; i * x <= c; i++) {
			if ((c - x * i) % y == 0) {
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}

}