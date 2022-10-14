import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x=sc.nextInt(),y=sc.nextInt(),z=sc.nextInt();
		int a=sc.nextInt(),b=sc.nextInt(),c=sc.nextInt();
		sc.close();
		System.out.println(a>=x&&(a+b)>=(x+y)&&(a+b+c)>=(x+y+z)?"YES":"NO");
	}
}