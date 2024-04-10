import java.util.*;
public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.nextLine();
		String t=sc.nextLine();
		sc.close();
		String vowels="aeiou";
		if(s.length()!=t.length())
			System.out.println("No");
		else{
			boolean b=true;
			for(int i=0;i<s.length();i++)
				if((vowels.indexOf(s.charAt(i))==-1)!=(vowels.indexOf(t.charAt(i))==-1))
					b=false;
			System.out.println(b?"Yes":"No");
		}
	}
}