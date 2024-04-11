import java.util.Scanner;
public class Main
{
	public static void main (String[] args)
	{
		Scanner sc=new Scanner(System.in);
		String s;
		s=sc.next();
		int x=0, y=0;
		for (int i=0; i<s.length(); i++)
			if (s.toCharArray()[i]=='4')
				x++;
			else 
				if (s.toCharArray()[i]=='7')
					y++;
		if (x==0 && y==0)
		{
			System.out.println("-1");
			return;
		}
		if ( x<y )
			System.out.println('7');
		else 
			System.out.println('4');
	}
}