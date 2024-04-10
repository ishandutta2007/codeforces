import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		int[]a=new int[n];
		int zeroes=n;
		for(int i=0;i<m;i++){
			int x=sc.nextInt()-1;
			a[x]++;
			if(a[x]==1)
				zeroes--;
			if(zeroes==0){
				for(int j=0;j<n;j++){
					a[j]--;
					if(a[j]==0)
						zeroes++;
				}
				System.out.print(1);
			}else
				System.out.print(0);
		}
		
		sc.close();
	}
}