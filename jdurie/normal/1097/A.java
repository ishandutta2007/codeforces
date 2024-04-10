import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		String[]sArr=sc.nextLine().split(" ");
		sc.close();
		boolean b=false;
		for(String str:sArr)
			if(str.charAt(0)==s.charAt(0)||str.charAt(1)==s.charAt(1))
				b=true;
		System.out.println(b?"YES":"NO");
	}
}