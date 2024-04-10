import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),k=sc.nextInt(),nOrig=n;
		int[]pows=new int[(int)Math.floor(Math.log(n)/Math.log(2))+1];
		int sum=0;
		for(int i=pows.length-1;i>=0;i--)
			if(n>=Math.pow(2,i)){
				pows[i]=1;
				sum++;
				n-=Math.pow(2,i);
			}
		if(sum>k||k>nOrig)
			System.out.println("NO");
		else{
			System.out.println("YES");
			int ind=pows.length-1;
			while(sum<k){
				while(pows[ind]==0)
					ind--;
				pows[ind]--;
				pows[ind-1]+=2;
				sum++;
			}
			for(int i=0;i<pows.length;i++)
				if(pows[i]>0)
					for(int j=0;j<pows[i];j++)
						System.out.print((int)Math.pow(2, i)+" ");
		}
	}
}