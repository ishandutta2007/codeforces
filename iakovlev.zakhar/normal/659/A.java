import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a = in.nextInt();
		int b = in.nextInt();
		int x = (n * 105 + a + b) % n;
		if(x != 0)
		System.out.println((n * 105 + a + b) % n);
		else 
		System.out.println(n);
		in.close();
	}

}