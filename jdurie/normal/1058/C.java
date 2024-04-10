import java.util.*;
public class GoldenTicket {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=Integer.parseInt(sc.nextLine());
		String s=sc.nextLine();
		sc.close();
		int[]sums=new int[n];
		sums[0]=Integer.parseInt(s.charAt(0)+"");
		for(int i=1;i<n;i++){
			sums[i]=sums[i-1]+Integer.parseInt(s.charAt(i)+"");
		}
		int totalSum=sums[n-1];
		ArrayList<Integer>divisors=new ArrayList<Integer>();
		for(int i=1;i<sums[n-1];i++){
			if(totalSum%i==0){
				divisors.add(i);
			}
		}
		boolean golden=false;
		for(int p:divisors){
			boolean goldenForP=true;
			boolean[]goldenForK=new boolean[sums[n-1]/p-1];
			for(int k=1;k<sums[n-1]/p;k++)
				for(int i=0;i<n;i++)
					if(sums[i]==k*p)
						goldenForK[k-1]=true;		
			for(boolean b:goldenForK)
				if(!b)
					goldenForP=false;
			if(goldenForP)
				golden=true;
		}
		if(golden||(totalSum==0&&n>1))
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}