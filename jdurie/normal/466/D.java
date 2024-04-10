import java.util.*;
public class IncreaseSequence {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),h=sc.nextInt(),lastH=h;
		boolean possible=true;
		long starts=0,w1=1,w2=1;
		for(int i=0;i<=n;i++){
			int thisH=i==n?h:sc.nextInt();
			if(thisH==lastH)
				w2=(w2*(long)(h-thisH+1))%1000000007;
			else if(thisH==lastH-1)
				starts++;
			else if(thisH==lastH+1&&thisH<=h)
				w1=(w1*starts--)%1000000007;
			else
				possible=false;
			lastH=thisH;
		}
		sc.close();
		System.out.println(possible?w1*w2%1000000007:0);
	}
}