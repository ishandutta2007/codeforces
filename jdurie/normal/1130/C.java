import java.util.*;
public class C {
	private static int[][]grid;
	private static boolean[][]used;
	private static int n;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		int r1=sc.nextInt()-1,c1=sc.nextInt()-1;
		int r2=sc.nextInt()-1,c2=sc.nextInt()-1;
		sc.nextLine();
		grid=new int[n][n];
		used=new boolean[n][n];
		for(int i=0;i<n;i++){
			String s=sc.nextLine();
			for(int j=0;j<n;j++)
				grid[i][j]=Integer.parseInt(s.charAt(j)+"");
		}
		sc.close();
		HashSet<Integer>coast1=getCoast(r1,c1);
		HashSet<Integer>coast2=getCoast(r2,c2);
		int cost=Integer.MAX_VALUE;
		for(int i:coast1)
			for(int j:coast2)
				cost=Math.min(cost,dist(i,j));
		System.out.println(cost==Integer.MAX_VALUE?0:cost);
	}
	private static int dist(int i,int j){
		int rI=i/n,cI=i%n;
		int rJ=j/n,cJ=j%n;
		return (rI-rJ)*(rI-rJ)+(cI-cJ)*(cI-cJ);
	}
	private static boolean valid(int r,int c){
		return !(r<0||c<0||r>=n||c>=n);
	}
	private static HashSet<Integer>getCoast(int r,int c){
		if(!valid(r,c))
			return null;
		used[r][c]=true;
		HashSet<Integer>coast=new HashSet<Integer>();
		int[]dx={1,-1,0,0};
		int[]dy={0,0,1,-1};
		for(int i=0;i<4;i++)
			if(valid(r+dx[i],c+dy[i])&&!used[r+dx[i]][c+dy[i]]){
				if(grid[r+dx[i]][c+dy[i]]==1)
					coast.add(r*n+c);
				else
					coast.addAll(getCoast(r+dx[i],c+dy[i]));
			}
		return coast;
	}
}