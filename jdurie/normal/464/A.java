import java.util.*;
public class NoToPalindromes {
	private static int modInd;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),p=sc.nextInt()+97;
		sc.nextLine();
		char[]c=sc.nextLine().toCharArray();
		sc.close();
		modInd=n-1;
		increment(c,p,n-1);
		while(modInd>=0&&bad(c,p))
			increment(c,p,n-1);
		if(modInd<0)
			System.out.print("NO");
		else
			for(char ch:c)
				System.out.print(ch);
	}
	private static void rewrite(char[]c,int p,int i){
		increment(c,p,i);
		if(p>=99){
			char[]fill={'a','b','c'};
			for(int j=i+1;j<c.length;j++)
				c[j]=fill[(j-i-1)%3];
		}
	}
	private static boolean bad(char[]c,int p){
		for(int i=modInd;i<c.length;i++)
			if((i>0&&c[i]==c[i-1])||(i>1&&c[i]==c[i-2])){
				rewrite(c,p,i);
				return bad(c,p);
			}
		return false;
	}
	private static void increment(char[]c,int p,int ind){
		c[ind]++;
		modInd=Math.min(modInd,ind);
		if(c[ind]==p){
			c[ind--]='a';
			modInd=Math.min(modInd,ind);
			if(ind>=0)
				increment(c,p,ind);
		}
	}
}