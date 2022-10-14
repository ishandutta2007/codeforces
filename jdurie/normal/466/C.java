import java.util.*;

public class NumberOfWays {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long sum = sc.nextInt();
		long[] sumTo = new long[n];
		sumTo[0] = sum;
		for (int i = 1; i < n; i++) {
			int num = sc.nextInt();
			sumTo[i] = sumTo[i - 1] + num;
			sum += num;
		}
		sc.close();
		if (sum % 3 == 0) {
			int[] twoThirds = new int[n];
			if (sumTo[0] == 2 * sum / 3)
				twoThirds[0] = 1;
			for (int i = n-2; i>=0; i--) {
				twoThirds[i] = twoThirds[i+1];
				if (sumTo[i] == 2 * sum / 3)
					twoThirds[i]++;
			}
			long ways = 0;
			for (int i = 0; i < n - 2; i++)
				if (sumTo[i] == sum / 3)
					ways += twoThirds[i+1];
			System.out.println(ways);
		}else{
			System.out.println(0);
		}
	}
}