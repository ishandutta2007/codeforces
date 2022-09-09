import java.util.Scanner;
public class Main
{
	public static boolean happy (int n)
	{
		while (n>0)
		{
			if ( n%10!=7 && n%10!=4 )
				return false;
			n/=10;
		}
		return true;
	}
	public static void main (String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int n;
		n=sc.nextInt();
		for (int i=1; i<=n; i++)
			if ( happy(i) && n%i==0)
			{
				System.out.println("YES");
				return;
			}
		System.out.println("NO");
	}
}