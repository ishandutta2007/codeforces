import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]rot=new int[n];
		for(int i=0;i<n;i++)
			rot[i]=sc.nextInt();
		sc.close();
		boolean possible=false;
		int i=0;
		while(i<Math.pow(2,n+1)&&!possible){
			int sum=0;
			for(int j=0;j<n;j++)
				if((i/(int)Math.pow(2,j))%2==1)
					sum+=rot[j];
				else
					sum-=rot[j];
			if(sum%360==0)
				possible=true;
			i++;
		}
		System.out.println(possible?"YES":"NO");
	}
}