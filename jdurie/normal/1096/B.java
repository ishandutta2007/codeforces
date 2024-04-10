import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextInt();
		sc.nextLine();
		char[]s=sc.nextLine().toCharArray();
		sc.close();
		boolean same=true;
		for(int c=0;c<n;c++)
			if(s[c]!=s[0])
				same=false;
		boolean endsSame=s[0]==s[(int)n-1];
		long frontL=1;
		int ind=1;
		while(s[ind++]==s[0])
			frontL++;
		long backL=1;
		int ind2=(int)n-2;
		while(s[ind2--]==s[(int)n-1])
			backL++;
		if(same)
			System.out.println((n*(n+1)/2+1)%998244353);
		else if(endsSame)
			System.out.println((frontL+1)*(backL+1)%998244353);
		else
			System.out.println((frontL+backL+1)%998244353);
	}
}