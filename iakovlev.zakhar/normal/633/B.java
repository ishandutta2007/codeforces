import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int x = 0;
		for (int i = 1; ; i++) {
			int y = i * 5;
			while (y % 5 == 0) {
				y /= 5;
				x++;
			}
			if (x == n) {
				System.out.println(5);
				for (int j = 0; j < 5; j++) {
					System.out.print(i * 5 + j + " ");
				}
				return;
			} else if (x > n) {
				System.out.println(0);
				return;
			}
		}
	}

}