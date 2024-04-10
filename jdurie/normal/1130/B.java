import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[][]pos=new long[n][2];
		for(long i=1;i<=2*n;i++){
			int a=sc.nextInt()-1;
			if(pos[a][0]==0)
				pos[a][0]=i;
			else
				pos[a][1]=i;
		}
		long sum=pos[0][0]-1+pos[0][1]-1;
		for(int j=1;j<n;j++){
			long a=Math.abs(pos[j][0]-pos[j-1][0])+Math.abs(pos[j][1]-pos[j-1][1]);
			long b=Math.abs(pos[j][0]-pos[j-1][1])+Math.abs(pos[j][1]-pos[j-1][0]);
			sum+=Math.min(a, b);
		}
		System.out.println(sum);
		sc.close();
	}
}