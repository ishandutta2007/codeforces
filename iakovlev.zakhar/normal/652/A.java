import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int h1 = in.nextInt();
		int h2 = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		h1 += (8 * a);
		if (h1 >= h2) {
			System.out.println(0);
			return;
		}
		if (a <= b) {
			System.out.println(-1);
			return;
		}
		int deltav = 12 * (a - b);
		System.out.println((h2 + deltav - 1 - h1) / deltav);
		in.close();
	}

}