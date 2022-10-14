import java.util.*;
public class CaesarsLegions{
	private static long MOD=100000000;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n1=sc.nextInt(),n2=sc.nextInt(),k1=sc.nextInt(),k2=sc.nextInt();
		sc.close();
		long[][][]dp1=new long[n1+n2+1][n1+1][k1+1];
		long[][][]dp2=new long[n1+n2+1][n2+1][k2+1];
		dp1[1][1][1]=1;
		dp1[1][0][0]=1;
		dp2[1][1][1]=1;
		dp2[1][0][0]=1;
		for(int i=2;i<=n1+n2;i++){
			for(int j=1;j<=Math.min(i,n1);j++){
				if(i-j<=n2)
					for(int k=1;k<=k2;k++)
						dp1[i][j][1]=(dp1[i][j][1]+dp2[i-1][i-j][k])%MOD;
				for(int k=2;k<=k1;k++)
					dp1[i][j][k]=dp1[i-1][j-1][k-1];
			}
			for(int j=1;j<=Math.min(i,n2);j++){
				if(i-j<=n1)
					for(int k=1;k<=k1;k++)
						dp2[i][j][1]=(dp2[i][j][1]+dp1[i-1][i-j][k])%MOD;
				for(int k=2;k<=k2;k++)
					dp2[i][j][k]=dp2[i-1][j-1][k-1];
			}
		}
		long ans=0;
		for(int k=1;k<=k1;k++)
			ans=(ans+dp1[n1+n2][n1][k])%MOD;
		for(int k=1;k<=k2;k++)
			ans=(ans+dp2[n1+n2][n2][k])%MOD;
		System.out.println(ans);
	}
}