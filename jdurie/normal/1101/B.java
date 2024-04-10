import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		sc.close();
		if(s.indexOf('[')==-1||s.indexOf(']')==-1||s.indexOf('[')>s.lastIndexOf(']'))
			System.out.println(-1);
		else{
			s=s.substring(s.indexOf('[')+1,s.lastIndexOf(']'));
			if(s.indexOf(':')==s.lastIndexOf(':'))
				System.out.println(-1);
			else{
				s=s.substring(s.indexOf(':')+1,s.lastIndexOf(':'));
				int l=4;
				for(int i=0;i<s.length();i++)
					if(s.charAt(i)=='|')
						l++;
				System.out.println(l);
			}
		}
	}
}