import java.util.*;
public class PaintingFence{
	private static int[]fence;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		fence=new int[n];
		for(int i=0;i<n;i++)
			fence[i]=sc.nextInt();
		sc.close();
		System.out.println(strokes(0,n,0));
	}
	private static int strokes(int start,int end,int del){
		int min=fence[start];
		for(int i=start;i<end;i++)
			if(fence[i]<min)
				min=fence[i];
		int temp=min-del;
		for(int i=start;i<end;i++){
			int st=i;
			while(i<end&&fence[i]>min)
				i++;
			int en=i;
			if(st!=en)
				temp+=strokes(st,en,min);
		}
		return Math.min(end-start,temp);
	}
}