import java.util.Scanner;
public class Main
{
	public static void main (String[] args)
	{
		Scanner sc=new Scanner(System.in);
		int n, k;
		int x[]=new int [200], y[]=new int [200]; 
		n=sc.nextInt();
		k=sc.nextInt();
		for (int i=0; i<n; i++)
		{
			x[i]=sc.nextInt();
			y[i]=sc.nextInt();
		}
		double ans=0.0;
		for (int i=1; i<n; i++)
		{
			double cur=Math.sqrt ( (double)(x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]) );
			ans+=cur;
		}
		ans=(double)ans*k;
		System.out.println(ans/50.00);
	}
}