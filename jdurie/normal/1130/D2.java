import java.util.*;
public class F {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		long[]minDC=new long[n];
		long[]loops=new long[n];
		for(int i=0;i<n;i++){
			minDC[i]=-1;
			loops[i]=-1;
		}
		for(int i=0;i<m;i++){
			int s=sc.nextInt()-1,d=sc.nextInt()-1;
			if(minDC[s]==-1||minDC[s]>(d-s+n)%n)
				minDC[s]=(d-s+n)%n;
			loops[s]++;
		}
		sc.close();
		long dist[]=new long[n];
		for(int i=0;i<n;i++)
			dist[i]=loops[i]*n+minDC[i];
		for(int i=0;i<n;i++){
			long d=0;
			for(int j=0;j<n;j++)
				d=Math.max(d,j+dist[(i+j)%n]);
			System.out.print(d+" ");
		}
	}
}