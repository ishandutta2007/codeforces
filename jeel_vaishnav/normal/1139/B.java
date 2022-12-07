import java.util.*;
import static java.lang.Math.*;

public class SolutionB {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		long a[] = new long[n];
		for(int i = 0; i < n; ++i)
			a[i] = sc.nextLong();

		long ans = 0;
		long curV = 1000000001;
		for(int i = n - 1; i >= 0; --i) {
			curV = max(0, min(curV - 1, a[i]));
			ans += curV;
		}

		System.out.print(ans);
	}
}