import java.util.*;
import java.io.*;
public class Ladder {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		PrintWriter out=new PrintWriter(new BufferedOutputStream(System.out));
		int n=sc.nextInt(),m=sc.nextInt();
		int[]nums=new int[n];
		int[]maxInd=new int[n];
		nums[0]=sc.nextInt();
		boolean inc=true;
		int lastChange=-1;
		for(int i=1;i<n;i++){
			nums[i]=sc.nextInt();
			if(inc&&nums[i]<nums[i-1])
				inc=false;
			else if(!inc&&nums[i]>nums[i-1]){
				maxInd[lastChange]=i-1;
				inc=true;
			}
			if(nums[i]!=nums[i-1])
				lastChange=i-1;
		}
		maxInd[n-1]=n-1;
		int lastMax=n-1;
		for(int i=n-2;i>=0;i--)
			if(maxInd[i]==0||nums[i]==nums[i+1])
				maxInd[i]=lastMax;
			else
				lastMax=maxInd[i];
		for(int i=0;i<m;i++)
			out.println(maxInd[sc.nextInt()-1]>=sc.nextInt()-1?"Yes":"No");
		out.close();
		sc.close();
	}
}