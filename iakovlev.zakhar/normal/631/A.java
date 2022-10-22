import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a = in.nextInt();
		for (int i = 0; i < n - 1; i++) {
			a |= in.nextInt();
		}
		int b = in.nextInt();
		for (int i = 0; i < n - 1; i++) {
			b |= in.nextInt();
		}
		System.out.println(a + b);
	}

}