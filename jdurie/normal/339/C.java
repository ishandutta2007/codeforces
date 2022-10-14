import java.util.*;
public class XeniaAndWeights {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		int m=sc.nextInt();
		sc.close();
		boolean[][][]dp=new boolean[m][9][10];
		HashSet<Integer>weights=new HashSet<Integer>();
		int wt=0;
		for(int i=0;i<10;i++)
			if(s.charAt(i)=='1'){
				if(i<9)
					dp[0][i][i]=true;
				weights.add(i);
				wt=i;
			}
		if(m==1&&wt!=0)
			System.out.println("YES\n"+(wt+1));
		else{
			for(int i=1;i<m;i++)
				for(int w:weights)
					for(int j=0;j<w;j++)
						for(int k=0;k<10;k++)
							if(dp[i-1][j][k]&&w!=k)
								dp[i][w-j-1][w]=true;
			int lastJ=-1,lastK=-1;
			for(int j=0;j<9;j++)
				for(int k=0;k<10;k++)
					if(dp[m-1][j][k]){
						lastJ=j;
						lastK=k;
					}
			System.out.println(lastJ==-1?"NO":"YES");
			if(lastJ!=-1){
				Stack<Integer>st=new Stack<Integer>();
				st.push(lastK+1);
				for(int i=m-2;i>=0;i--){
					lastJ=lastK-lastJ-1;
					for(int k=0;k<10;k++)
						if(dp[i][lastJ][k]&&k!=lastK){
							lastK=k;
							break;
						}
					st.push(lastK+1);
				}
				while(!st.isEmpty())
					System.out.print(st.pop()+" ");
			}
		}
	}
}