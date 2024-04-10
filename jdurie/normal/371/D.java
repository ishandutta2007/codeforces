import java.util.*;
import java.io.*;
public class Vessels {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		PrintWriter out=new PrintWriter(new BufferedOutputStream(System.out));
		int n=sc.nextInt();
		int[]capacity=new int[n+1];
		for(int i=0;i<n;i++)
			capacity[i]=sc.nextInt();
		capacity[n]=Integer.MAX_VALUE;
		int[]amount=new int[n+1];
		int[]overflowTo=new int[n+1];
		for(int i=0;i<=n;i++)
			overflowTo[i]=i;
		int m=sc.nextInt();
		for(int i=0;i<m;i++)
			if(sc.nextInt()==1){
				int pi=sc.nextInt()-1,xi=sc.nextInt();
				if(amount[pi]+xi<=capacity[pi])
					amount[pi]+=xi;
				else{
					while(pi<n&&amount[pi]+xi>capacity[pi]){
						xi-=capacity[pi]-amount[pi];
						amount[pi]=capacity[pi];
						overflowTo[pi]=getOF(overflowTo,pi+1);
						pi=overflowTo[pi];
					}
					amount[pi]+=xi;
				}
			}else
				out.println(amount[sc.nextInt()-1]);
		out.close();
		sc.close();
	}
	public static int getOF(int[]overflow,int ind){
		ArrayList<Integer>inds=new ArrayList<Integer>();
		while(overflow[ind]!=ind){
			inds.add(ind);
			ind=overflow[ind];
		}
		for(int i:inds)
			overflow[i]=ind;
		return ind;
	}
}