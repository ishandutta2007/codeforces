import java.util.*;
public class E {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		int[][]segs=new int[m][2];
		for(int i=0;i<m;i++)
			segs[i]=new int[]{sc.nextInt()-1,sc.nextInt()-1};
		sc.close();
		int bestI=-1,bestJ=-1,bestD=-1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				int d=a[i]-a[j];
				for(int k=0;k<m;k++)
					if(segs[k][0]<=j&&segs[k][1]>=j&&(segs[k][0]>i||segs[k][1]<i))
						d++;
				if(d>bestD){
					bestI=i;
					bestJ=j;
					bestD=d;
				}
			}
		System.out.println(bestD);
		System.out.println(bestD-(a[bestI]-a[bestJ]));
		for(int k=0;k<m;k++)
			if(segs[k][0]<=bestJ&&segs[k][1]>=bestJ&&(segs[k][0]>bestI||segs[k][1]<bestI))
				System.out.print((k+1)+" ");
	}
}