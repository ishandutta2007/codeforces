import java.util.*;
public class C {
	private static int[][]grid;
	private static int x=0;
	private static int y=0;
	private static int n;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		int[]nums=new int[1001];
		for(int i=0;i<n*n;i++)
			nums[sc.nextInt()]++;
		sc.close();
		grid=new int[n][n];
		int removed=0;
		for(int i=0;i<1001;i++)
			while(x<n/2&&y<n/2&&nums[i]>=4){
				add(i,true);
				nums[i]-=4;
				removed+=4;
			}
		if(n%2==0&&removed!=n*n||n%2==1&&removed!=n*n-2*n+1)
			System.out.println("NO");
		else if(n%2==0)
			print();
		else{
			x=n/2;
			y=0;
			int c=-1;
			boolean possible=true;
			for(int i=0;i<1001;i++){
				while(removed<n*n&&nums[i]>=2){
					add(i,false);
					nums[i]-=2;
					removed+=2;
				}
				if(nums[i]==1&&c==-1)
					c=i;
				else if(nums[i]==1)
					possible=false;
			}
			grid[n/2][n/2]=c;
			if(possible)
				print();
			else
				System.out.println("NO");
		}
	}
	private static void print(){
		System.out.println("YES");
		for(int[]i:grid){
			for(int j:i)
				System.out.print(j+" ");
			System.out.println();
		}
	}
	private static void add(int i,boolean bs){
		grid[x][y]=i;
		grid[x][n-1-y]=i;
		grid[n-1-x][y]=i;
		grid[n-1-x][n-1-y]=i;
		if(bs){
			y++;
			if(y==n/2){
				y=0;
				x++;
			}
		}else{
			if(x==n/2){
				y++;
				if(y==n/2){
					x=0;
					y=n/2;
				}
			}else
				x++;
		}
	}
}