import java.util.*;
public class D {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.nextLine();
		char[]s=sc.nextLine().toCharArray();
		sc.close();
		int[][]changes=new int[n][3];
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++){
				if(s[i]!="RGB".charAt(j))
					changes[i][j]++;
				if(i>0)
					changes[i][j]+=Math.min(changes[i-1][(j+1)%3], changes[i-1][(j+2)%3]);
			}
		System.out.println(Math.min(Math.min(changes[n-1][0], changes[n-1][1]), changes[n-1][2]));
		Stack<Character>st=new Stack<Character>();
		int last=-1;
		for(int i=n-1;i>=0;i--){
			int minJ=-1;
			for(int j=0;j<3;j++)
				if(j!=last&&(minJ<0||changes[i][j]<changes[i][minJ]))
					minJ=j;
			last=minJ;
			st.push("RGB".charAt(minJ));
		}
		while(!st.isEmpty())
			System.out.print(st.pop());
	}
}