import java.util.Arrays;
import java.util.Scanner;

public class C {
	
	static class Str implements Comparable<Str> {
		String s;
		
		public Str(String s) {
			this.s = s;
		}
		
		public int compareTo(Str that) {
			for (int i = 0; ; i++) {
				if (i == this.s.length()) {
					if (i == that.s.length()) {
						return 0;
					} else {
						return  this.compareTo(new Str(that.s.substring(i)));
					}
				} else if (i == that.s.length()) {
					return -that.compareTo(new Str(this.s.substring(i)));
				} else if (this.s.charAt(i) != that.s.charAt(i)) {
					return this.s.charAt(i) - that.s.charAt(i);
				}
			}
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		Str[] s = new Str[n];
		for (int i = 0; i < s.length; i++) {
			s[i] = new Str(in.next());
		}
		Arrays.sort(s);
		for (int i = 0; i < s.length; i++) {
			System.out.print(s[i].s);
		}
	}

}