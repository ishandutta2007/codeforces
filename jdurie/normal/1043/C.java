import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		sc.close();
		for(int i=1;i<s.length();i++)
			System.out.print(s.charAt(i)==s.charAt(i-1)?"0 ":"1 ");
		System.out.print(s.charAt(s.length()-1)=='a'?"1 ":"0 ");
	}
}