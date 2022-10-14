import java.util.*;
public class AntonAndLetters {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		sc.close();
		HashSet<Integer>chars=new HashSet<Integer>();
		for(int i=0;i<s.length();i++)
			if(s.charAt(i)>96&&s.charAt(i)<123)
				chars.add(0+s.charAt(i));
		System.out.println(chars.size());
	}
}