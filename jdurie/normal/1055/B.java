import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt(),l=sc.nextInt();
		long[]lengths=new long[n];
		for(int i=0;i<n;i++)
			lengths[i]=sc.nextLong();
		int count=lengths[0]>l?1:0;
		for(int i=1;i<n;i++)
			if(lengths[i]>l&&lengths[i-1]<=l)
				count++;
		for(int i=0;i<m;i++){
			if(sc.nextInt()==0)
				System.out.println(count);
			else{
				int ind=sc.nextInt()-1,d=sc.nextInt();
				if(lengths[ind]<=l&&lengths[ind]+d>l&&(ind==0||lengths[ind-1]<=l)&&(ind==n-1||lengths[ind+1]<=l))
					count++;
				else if(lengths[ind]<=l&&lengths[ind]+d>l&&ind!=0&&ind!=n-1&&lengths[ind-1]>l&&lengths[ind+1]>l)
					count--;
				lengths[ind]+=d;
			}
		}
		sc.close();
	}
}