import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
		int ans = 0;
		for (int i = 1; i < a.length - 1; i++) {
			if ((a[i] - a[i - 1]) * (a[i] - a[i + 1]) > 0) {
				ans++;
			}
		}
		System.out.println(ans);
		in.close();
	}

}