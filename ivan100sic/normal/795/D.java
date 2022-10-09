import java.util.*;
import java.io.*;
import java.lang.*;

public class Main {

	static Scanner in = new Scanner(System.in);

	static void countingSort(int[] a, int l, int r) {
		int[] c = new int[100005];
		for (int i=0; i<100005; i++) {
			c[i] = 0;
		}

		for (int i=l; i<r; i++) {
			c[a[i]]++;
		}

		for (int i=0; i<100005; i++) {
			while (c[i] > 0) {
				a[l++] = i;
				c[i]--;
			}
		}
	}

	public static void main(String[] args) {
		int n, l, r;
		n = in.nextInt();
		l = in.nextInt();
		r = in.nextInt();

		int[] a = new int[n+1];
		int[] b = new int[n+1];

		for (int i=1; i<=n; i++) {
			a[i] = in.nextInt();
		}

		for (int i=1; i<=n; i++) {
			b[i] = in.nextInt();
		}

		countingSort(a, l, r+1);
		countingSort(b, l, r+1);

		for (int i=1; i<=n; i++) {
			if (a[i] != b[i]) {
				System.out.println("LIE");
				return;
			}
		}

		System.out.println("TRUTH");
	}
}