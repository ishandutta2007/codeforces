import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int x = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (in.nextInt() >= 4) {
				x++;
			} else {
				x = 0;
			}
			if (x == 3) {
				x = 0;
				ans++;
			}
		}
		System.out.println(ans);
	}

}