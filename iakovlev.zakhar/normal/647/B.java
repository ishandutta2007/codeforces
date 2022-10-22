import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = in.nextInt();
		int up = a;
		int down = 0;
		int left = b;
		int right = 0;
		for (int i = 0; i < a; i++) {
			String s = in.next();
			for (int j = 0; j < b; j++) {
				if (s.charAt(j) == '*') {
					if (i < up) {
						up = i;
					}
					if (i > down) {
						down = i;
					}
					if (j < left) {
						left = j;
					}
					if (j > right) {
						right = j;
					}
				}
			}
		}
		System.out.println(Math.max(right - left, down - up) + 1);
	}

}