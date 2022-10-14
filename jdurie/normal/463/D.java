//package a2oj;
import java.util.*;

public class GargariAndPermutations {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), k = sc.nextInt();
		int[][] grid = new int[k][n];
		for(int i=0; i<k; i++)
			for(int j=0; j<n; j++)
				grid[i][j] = sc.nextInt()-1;
		sc.close();
		boolean[][] before = new boolean[n][n];
		for(int i=0; i<k; i++)
			for(int j=1; j<n; j++)
				for(int l=0; l<j; l++)
					before[grid[i][l]][grid[i][j]] = true;
		for(int i=0;i<n;i++)
			before[i][i]=true;
		int[]len=new int[n];
		for(int i=0;i<n;i++)
			fillLen(len,i,before);
		int max=0;
		for(int i=0;i<n;i++)
			max=Math.max(max, len[i]);
		System.out.println(max);
	}
	static int fillLen(int[]len,int i,boolean[][]before){
		if(len[i]>0)
			return len[i];
		len[i]=1;
		for(int j=0;j<before.length;j++)
			if(!before[j][i])
				len[i]=Math.max(len[i],1+fillLen(len,j,before));
		return len[i];
	}
}