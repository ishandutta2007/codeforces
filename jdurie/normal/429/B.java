import java.util.Scanner;
public class WorkingOut {
	private static int n,m;
	private static int[][]a;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		m=sc.nextInt();
		a=new int[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i][j]=sc.nextInt();
		sc.close();
		int[][]aStart=pSum(1,1);
		int[][]aEnd=pSum(-1,-1);
		int[][]bStart=pSum(1,-1);
		int[][]bEnd=pSum(-1,1);
		int max=-1;
		for(int i=2;i<=n-1;i++)
			for(int j=2;j<=m-1;j++){
				int way1=aStart[i-1][j]+aEnd[i+1][j]+bStart[i][j-1]+bEnd[i][j+1];
				int way2=aStart[i][j-1]+aEnd[i][j+1]+bStart[i+1][j]+bEnd[i-1][j];
				max=Math.max(max,Math.max(way1,way2));
			}
		System.out.println(max);
	}
	public static int[][]pSum(int dx,int dy){
		int[][]pSum=new int[n+2][m+2];
		for(int i=dy==1?1:n;dy==1?i<=n:i>0;i+=dy)
			for(int j=dx==1?1:m;dx==1?j<=m:j>0;j+=dx)
				pSum[i][j]=a[i-1][j-1]+Math.max(pSum[i-dy][j],pSum[i][j-dx]);
		return pSum;
	}
}