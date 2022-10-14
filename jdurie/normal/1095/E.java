import java.util.*;
public class E {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.nextLine();
		String s=sc.nextLine();
		sc.close();
		int[]cts=new int[n];
		cts[0]=s.charAt(0)=='('?1:-1;
		int badI=s.charAt(0)=='('?Integer.MAX_VALUE:0;
		for(int i=1;i<n;i++)
			if(s.charAt(i)=='(')
				cts[i]=cts[i-1]+1;
			else{
				cts[i]=cts[i-1]-1;
				if(cts[i]==-1&&badI==Integer.MAX_VALUE)
					badI=i;
			}
		if(n%2==1||Math.abs(cts[n-1])!=2)
			System.out.println(0);
		else if(cts[n-1]==2){
			int ind=n-1,ans=0;
			while(ind<=badI&&cts[ind]>=2){
				if(s.charAt(ind)=='(')
					ans++;
				ind--;
			}
			System.out.println(ans);
		}else{
			int[]cts2=new int[n];
			int badI2=s.charAt(n-1)==')'?Integer.MIN_VALUE:n-1;
			cts2[n-1]=s.charAt(n-1)==')'?1:-1;
			for(int i=n-2;i>=0;i--)
				if(s.charAt(i)==')')
					cts2[i]=cts2[i+1]+1;
				else{
					cts2[i]=cts2[i+1]-1;
					if(cts2[i]==-1&&badI2==Integer.MIN_VALUE)
						badI2=i;
				}
			int ind=0,ans=0;
			while(ind>=badI2&&cts2[ind]>=2){
				if(s.charAt(ind)==')')
					ans++;
				ind++;
			}
			System.out.println(ans);
		}
	}
}