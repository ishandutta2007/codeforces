import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		sc.nextLine();
		String s=sc.nextLine();
		sc.close();
		int k=1;
		for(int i=0;i<s.length();i+=k++)
			System.out.print(s.charAt(i));
	}
}