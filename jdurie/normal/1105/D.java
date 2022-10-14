import java.util.*;
public class D {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt(), m=sc.nextInt(), p=sc.nextInt();
		int[]s=new int[p];
		for(int i=0;i<p;i++)
			s[i]=sc.nextInt();
		sc.nextLine();
		char[][]grid=new char[n][m];
		for(int i=0;i<n;i++)
			grid[i]=sc.nextLine().toCharArray();
		sc.close();
		HashMap<Integer,HashMap<Integer,HashSet<Integer>>>castles=new HashMap<Integer,HashMap<Integer,HashSet<Integer>>>();
		for(int i=0;i<p;i++){
			castles.put(i,new HashMap<Integer,HashSet<Integer>>());
			for(int r=0;r<n;r++)
				for(int c=0;c<m;c++)
					if(grid[r][c]==i+49)
						add(castles.get(i),i,r,c,grid);
		}
		HashSet<Integer>stuck=new HashSet<Integer>();
		while(stuck.size()<p)
			for(int i=0;i<p;i++){
				if(!stuck.contains(i)){
					for(int q=0;q<s[i];q++){
						HashMap<Integer,HashSet<Integer>>temp=new HashMap<Integer,HashSet<Integer>>();
						for(int r:castles.get(i).keySet()){
							for(int c:castles.get(i).get(r))
								addNeighbors(grid,r,c,i,temp);
						}
						castles.put(i, temp);
						if(castles.get(i).isEmpty())
							break;
					}
					if(castles.get(i).keySet().isEmpty())
						stuck.add(i);
				}
			}
		int[]controlled=new int[p];
		for(int r=0;r<n;r++)
			for(int c=0;c<m;c++)
				if(grid[r][c]>48&&grid[r][c]<58)
					controlled[grid[r][c]-49]++;
		for(int i:controlled)
			System.out.print(i+" ");
	}
	public static void addNeighbors(char[][]grid,int r,int c,int p,HashMap<Integer,HashSet<Integer>>ca){
		if(r>0&&grid[r-1][c]=='.')
			add(ca,p,r-1,c,grid);
		if(r+1<grid.length&&grid[r+1][c]=='.')
			add(ca,p,r+1,c,grid);
		if(c>0&&grid[r][c-1]=='.')
			add(ca,p,r,c-1,grid);
		if(c+1<grid[0].length&&grid[r][c+1]=='.')
			add(ca,p,r,c+1,grid);
	}
	public static void add(HashMap<Integer,HashSet<Integer>>ca,int p,int r,int c,char[][]grid){
		if(!ca.containsKey(r))
			ca.put(r, new HashSet<Integer>());
		ca.get(r).add(c);
		grid[r][c]=(char)(p+49);
	}
}