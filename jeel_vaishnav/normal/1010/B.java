import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);

		int m = sc.nextInt();
		int n = sc.nextInt();

		int truth[] = new int[n];

		for(int i = 0; i < n; ++i) {
			System.out.println("1");
			System.out.flush();

			int val = sc.nextInt();

			if(val == 0) {
				return;
			}

			if(val == 1)
				truth[i] = -1;
			else
				truth[i] = 1;
		}

		int curMove = 0;
		int start = 2, end = m;
		while(start <= end) {
			int req = (start + end) >> 1;
			System.out.println(req);
			System.out.flush();

			int val = sc.nextInt() * truth[curMove];

			curMove = (curMove + 1) % n;

			if(val == 0)
				return;

			if(val == -1)
				start = req + 1;
			else
				end = req - 1;
		}
	}
}