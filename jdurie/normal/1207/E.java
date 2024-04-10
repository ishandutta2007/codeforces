//package cfed71;
import java.util.*;

public class D {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		System.out.println("! " + (ask(0) + ask(1)));
		System.out.flush();
	}
	private static int ask(int i) {
		System.out.print("? ");
		int count = 0, x = 1;
		while(count < 100) {
			boolean ok = true;
			for(int j = i; (1 << j) <= x; j += 2)
				if(((1 << j) & x) > 0)
					ok = false;
			if(ok) {
				System.out.print(x + " ");
				count++;
			}
			x++;
		}
		System.out.flush();
		int res = sc.nextInt();
		for(int j = 1 - i; (1 << j) <= res; j += 2)
			if(((1 << j) & res) > 0)
				res -= (1 << j);
		return res;
	}
}