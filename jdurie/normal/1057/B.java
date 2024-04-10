import java.util.*;
public class DDoS {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]requestsUpTo=new int[n+1];
		requestsUpTo[0]=0;
		for(int i=1;i<=n;i++)
			requestsUpTo[i]=requestsUpTo[i-1]+sc.nextInt();
		sc.close();
		int maxLength=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(requestsUpTo[j]-requestsUpTo[i-1]>100*(j-i+1))
					if(j-i+1>maxLength)
						maxLength=j-i+1;
		System.out.println(maxLength);
	}
}