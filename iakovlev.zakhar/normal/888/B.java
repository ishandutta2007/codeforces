import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String s = in.next();
		int u = 0;
		int d = 0;
		int r = 0;
		int l = 0;
		for (int i = 0; i < n; i++) {
			if (s.charAt(i) == 'U') {
				u++;
			} else if (s.charAt(i) == 'D') {
				d++;
			} else if (s.charAt(i) == 'R') {
				r++;
			} else {
				l++;
			}
		}
		System.out.println(2 * Math.min(r, l) + 2 * Math.min(d, u));
		in.close();
	}

}