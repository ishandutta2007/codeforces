import java.util.Scanner;

public class A {

	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		char[] a = new char[3];
		char[] b = new char[3];
		String s1 = in.next();
		String s2 = in.next();
		int i = 0;
		if (s1.charAt(0) != 'X') {
			a[i] = s1.charAt(0);
			i++;
		}
		if (s1.charAt(1) != 'X') {
			a[i] = s1.charAt(1);
			i++;
		}
		if (s2.charAt(1) != 'X') {
			a[i] = s2.charAt(1);
			i++;
		}
		if (s2.charAt(0) != 'X') {
			a[i] = s2.charAt(0);
			i++;
		}
		s1 = in.next();
		s2 = in.next();
		i = 0;
		if (s1.charAt(0) != 'X') {
			b[i] = s1.charAt(0);
			i++;
		}
		if (s1.charAt(1) != 'X') {
			b[i] = s1.charAt(1);
			i++;
		}
		if (s2.charAt(1) != 'X') {
			b[i] = s2.charAt(1);
			i++;
		}
		if (s2.charAt(0) != 'X') {
			b[i] = s2.charAt(0);
			i++;
		}
		for (int j = 0; j < b.length; j++) {
			if (b[j] == a[0]) {
				if (b[(j + 1) % 3] == a[1]) {
					System.out.println("YES");
					return;
				} else {
					System.out.println("NO");
					return;
				}
			}
		}
	}

}