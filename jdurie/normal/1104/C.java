import java.util.*;
public class C {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.nextLine();
		sc.close();
		boolean hor=false,ver=false;
		for(int i=0;i<s.length();i++)
			if(s.charAt(i)=='0'){
				if(ver)
					System.out.println("1 1");
				else
					System.out.println("3 1");
				ver=!ver;
			}else{
				if(hor)
					System.out.println("1 1");
				else
					System.out.println("1 3");
				hor=!hor;
			}
	}
}