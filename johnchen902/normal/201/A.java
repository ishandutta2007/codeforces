import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		while (scan.hasNextInt()) {
			int n = scan.nextInt();
			int i;
			for (i = 1; !f(i, n); i += 2)
				;
			System.out.println(i);
		}
	}

	private static boolean f(int i, int n) {
		int capacity;
		capacity = i * i / 2;
		boolean b = n % 2 == 1;
		if (n % 2 == 1)
			n--;
		if (n % 4 == 2) {
			if (b && i < 5)
				return false;
			n -= 2;
			capacity -= 4;
		}
		return capacity >= n;
	}
}