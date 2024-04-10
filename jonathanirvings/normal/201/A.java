import java.util.Scanner;
public class Main
{
	public static void main (String[] args)
	{
		Scanner in = new Scanner(System.in);
		int ans[];
		int f[];
		ans = new int[105];
		f = new int[105];
		ans[0] = 0;
		int N = in.nextInt();
		f[0] = 0;
		for (int i = 1; i <= N; ++i)
		{
			f[i] = f[i-1];
			if (f[i] * f[i] / 2 < i) ++f[i];
			//System.out.printf("%d %d\n",i,f[i]);
		}
		ans[1] = 1;
		for (int i = 2; i <= N; ++i)
		{
			ans[i] = ans[i-1];
			if ((ans[i] * ans[i] + 1) / 2 < i) ans[i] += 2;
			//System.out.printf("%d %d\n",i,ans[i]);
		}
		ans[3] = 5;
		System.out.println(ans[N]);
	}
}