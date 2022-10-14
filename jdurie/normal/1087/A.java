import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		sc.close();
		int l=s.length();
		String actual="";
		for(int i=0;i<l;i++)
			if(i%2==l%2){
				actual=s.charAt(s.length()-1)+actual;
				s=s.substring(0,s.length()-1);
			}else{
				actual=s.charAt(0)+actual;
				s=s.substring(1);
			}
		System.out.println(actual);
	}
}