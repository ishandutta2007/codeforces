import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a = in.nextInt();
		if (a % 2 == 1) {
			System.out.println(a / 2 + 1);
		} else {
			System.out.println((n - a) / 2 + 1);
		}
		in.close();
	}

}