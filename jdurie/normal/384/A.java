import java.util.*;
public class Coder {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.close();
		System.out.println((int)Math.ceil(n*n/2.0));
		String s1="",s2="";
		for(int i=0;i<n;i++){
			s1+=i%2==0?"C":".";
			s2+=i%2==0?".":"C";
		}
		for(int i=0;i<n;i++)
			System.out.println(i%2==0?s1:s2);
	}
}