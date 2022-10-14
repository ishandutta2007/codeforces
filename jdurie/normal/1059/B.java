import java.util.*;
public class Forgery {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		sc.nextLine();
		int[][]grid=new int[n][m];
		for(int i=0;i<n;i++){
			String s=sc.nextLine();
			for(int j=0;j<m;j++)
				if(s.charAt(j)=='#')
					grid[i][j]=2;
				else
					grid[i][j]=0;
		}
		sc.close();
		for(int i=1;i<n-1;i++)
			for(int j=1;j<m-1;j++)
				if(canPaint(grid,i,j))
					paint(grid,i,j);
		System.out.println(test(grid));
	}
	public static boolean canPaint(int[][]grid,int i,int j){
		for(int a=-1;a<=1;a++)
			for(int b=-1;b<=1;b++)
				if((a!=0||b!=0)&&grid[i+a][j+b]==0)
					return false;
		return true;
	}
	public static void paint(int[][]grid,int i,int j){
		for(int a=-1;a<=1;a++)
			for(int b=-1;b<=1;b++)
				if(a!=0||b!=0)
					grid[i+a][j+b]=1;
	}
	public static String test(int[][]grid){
		for(int[]i:grid)
			for(int j:i)
				if(j==2)
					return "NO";
		return "YES";
	}
}