import java.util.*;
public class VasyaTriangle {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong();
		long m=sc.nextLong();
		long k=sc.nextLong();
		sc.close();
		if(2*n*m%k!=0)
			System.out.println("NO");
		else{
			System.out.println("YES");
			long kN=1;
			if(2*n%k==0)
				kN=k;
			else if(2*m%k==0)
				kN=1;
			else{
				for(int i=2;i<=k/kN;i++)
					while(k/kN%i==0&&n/kN%i==0)
						kN*=i;
			}
			long kM=k/kN;
			long x=(2*n)/kN;
			long y=(2*m)/kM;
			if(y<m&&x%2==0)
				x/=2;
			else
				y/=2;
			System.out.println("0 0");
			System.out.println(x+" 0");
			System.out.println("0 "+y);
		}
	}
}