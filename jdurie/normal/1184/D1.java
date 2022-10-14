import java.util.*;
public class D1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt(), m = sc.nextInt(), t = sc.nextInt();
		for(int i = 0; i < t; i++) {
			if(sc.nextInt() == 1) {
				int x = sc.nextInt();
				if(x <= k)
					k++;
				n++;
			} else {
				int x = sc.nextInt();
				if(k > x) {
					k -= x;
					n -= x; 
				} else
					n -= (n - x);
			}
			System.out.println(n + " " + k);
		}
		sc.close();
	}
}