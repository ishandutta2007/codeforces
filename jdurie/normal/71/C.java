import java.util.*;
public class RoundTableKnights {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),temp=n;
		ArrayList<Integer>primes=new ArrayList<Integer>();
		for(int i=3;i<=temp;i++){
			if(temp%i==0)
				primes.add(i);
			while(temp%i==0)
				temp/=i;
		}
		boolean[][]dp=new boolean[n][primes.size()];
		for(int i=0;i<n;i++)
			if(sc.nextInt()==0)
				for(int j=0;j<primes.size();j++)
					dp[i][j]=true;
			else
				for(int j=0;j<primes.size();j++)
					if(i>=n/primes.get(j))
						dp[i][j]=dp[i-n/primes.get(j)][j];
		sc.close();
		boolean lucky=false;
		for(int j=0;j<primes.size();j++)
			for(int i=n-n/primes.get(j);i<n;i++)
				if(!dp[i][j])
					lucky=true;
		System.out.println(lucky?"YES":"NO");
	}
}