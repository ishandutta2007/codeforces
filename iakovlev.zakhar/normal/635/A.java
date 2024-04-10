import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

public class E {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int r = in.nextInt();
		int c = in.nextInt();
		int n = in.nextInt();
		int k = in.nextInt();
		int[][] a = new int[r][c];
		for (int i = 0; i < n; i++) {
			a[in.nextInt() - 1][in.nextInt() - 1] = 1;
		}
		int sum = 0;
		for (int i = 1; i <= c; i++) {
			for (int j = 1; j <= r; j++) {
				for (int x = 0; x <= c - i; x++) {
					for (int y = 0; y <= r - j; y++) {
						int alt = 0;
						for (int l = 0; l < i; l++) {
							for (int l2 = 0; l2 < j; l2++) {
								alt += a[y + l2]
										[x + l];
							}
						}
						if (alt >= k) {
							sum++;
						}
					}
				}
			}
		}
		System.out.println(sum);
	}

}