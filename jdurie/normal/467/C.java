import java.util.*;
public class GeorgeAndJob{
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
        long[]p=new long[n];
        for(int i=0;i<n;i++)
            p[i]=sc.nextLong();
        long[]sum=new long[n-m+1];
        for(int i=0;i<m;i++)
            sum[0]+=p[i];
        for(int i=1;i<sum.length;i++)
            sum[i]=sum[i-1]+p[i+m-1]-p[i-1];
        long[]dp1=new long[n-m+1];
        for(int i=0;i<dp1.length;i++)
            dp1[i]=Math.max(sum[i],i>0?dp1[i-1]:0);
        for(int i=1;i<k;i++){
            long[]dp2=new long[n-m+1];
            for(int j=i*m;j<n-m+1;j++)
                dp2[j]=Math.max(dp1[j-m]+sum[j],dp2[j-1]);
            dp1=dp2;
        }
        System.out.println(dp1[n-m]);
    }
}