import java.util.*;
public class C {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.nextLine();
		char[]s=sc.nextLine().toCharArray();
		sc.close();
		int[][]colors=new int[3][3];//first ind is mod position, second is color
		for(int i=0;i<3;i++){
			for(int j=i;j<n;j+=3)
				colors[i]["RGB".indexOf(s[j])]++;
		}
		int[][]ways=new int[][]{{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
		int max=0,maxInd=-1;
		for(int i=0;i<6;i++){
			int noChanges=0;
			for(int j=0;j<3;j++)
				noChanges+=colors[ways[i][j]][j];
			if(noChanges>max){
				max=noChanges;
				maxInd=i;
			}
		}
		System.out.println(n-max);
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				if(ways[maxInd][j]==i%3)
					System.out.print("RGB".charAt(j));
	}
}