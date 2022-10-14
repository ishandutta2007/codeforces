import java.util.*;
public class FoxAndCross {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.nextLine();
		boolean[][]grid=new boolean[n][n];
		for(int i=0;i<n;i++){
			String s=sc.nextLine();
			for(int j=0;j<n;j++)
				grid[i][j]=s.charAt(j)=='#';
		}
		sc.close();
		for(int i=1;i<n-1;i++)
			for(int j=1;j<n-1;j++)
				if(grid[i][j]&&grid[i-1][j]&&grid[i+1][j]&&grid[i][j-1]&&grid[i][j+1]){
					grid[i][j]=false;
					grid[i-1][j]=false;
					grid[i+1][j]=false;
					grid[i][j-1]=false;
					grid[i][j+1]=false;
				}
		boolean b=true;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(grid[i][j])
					b=false;
		System.out.println(b?"YES":"NO");
	}
}