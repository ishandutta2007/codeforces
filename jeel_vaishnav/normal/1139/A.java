import java.util.*;

public class SolutionA {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		char[] s = sc.next().toCharArray();

		int ans = 0;
		for(int i = 0; i < n; ++i) {
			if((s[i] - '0') % 2 == 0)
				ans += (i + 1);
		}

		System.out.print(ans);
	}
}