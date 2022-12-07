import java.util.*;

public class prob
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		
		long a;
		a=sc.nextLong();
		
		long temp=a,count=0;
		
		while(temp!=0)
		{
			if(temp%10==4||temp%10==7)
				count++;
			temp/=10;
		}
		
		if(count==4||count==7)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}