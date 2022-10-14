import java.util.*;
public class CountGoodSubstrings {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		sc.close();
		int[][]dp=new int[s.length()][4];
		for(int i=s.length()-1;i>=0;i--){
			if(i+1<s.length())
				for(int j=0;j<4;j++)
					dp[i][j]=dp[i+1][j];
			if(s.charAt(i)=='a')
				dp[i][i%2]++;
			else
				dp[i][2+i%2]++;
		}
		long odds=0,evens=0;
		for(int i=0;i<s.length();i++)
			if(s.charAt(i)=='a'){
				odds+=dp[i][i%2];
				evens+=dp[i][1-i%2];
			}else{
				odds+=dp[i][2+i%2];
				evens+=dp[i][3-i%2];
			}
		System.out.println(evens+" "+odds);
	}
}