import java.util.Scanner;
public class Main
{
	public static void main (String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int n;
		n=sc.nextInt();
		int num[]=new int [200];
		for (int i=0; i<n; i++)
		{
			int cur=sc.nextInt();
			num[cur]++;
		}
	for (int i=0; i<=100; i++)
		num[i]=num[i]/2;
	int sum=0;
	for (int i=0; i<=100; i++)
		sum+=num[i];
	System.out.println(sum/2);
	}
}