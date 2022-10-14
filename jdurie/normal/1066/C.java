import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int q=sc.nextInt();
		sc.nextLine();
		TreeMap<Integer,Integer>numAdded=new TreeMap<Integer,Integer>();
		int[]nLeftsUpTo=new int[q];
		int[]nRightsUpTo=new int[q];
		for(int i=0;i<q;i++){
			String s=sc.nextLine();
			char c=s.charAt(0);
			int n=Integer.parseInt(s.substring(2));
			if(i>0){
				nLeftsUpTo[i]=nLeftsUpTo[i-1];
				nRightsUpTo[i]=nRightsUpTo[i-1];
			}
			if(c=='L'){
				numAdded.put(n,-i);
				nLeftsUpTo[i]++;
			}else if(c=='R'){
				numAdded.put(n,i);
				nRightsUpTo[i]++;
			}else{
				int j=numAdded.get(n);
				int size=nLeftsUpTo[Math.abs(j)]+nRightsUpTo[Math.abs(j)];
				int lAfter=nLeftsUpTo[i]-nLeftsUpTo[Math.abs(j)];
				int rAfter=nRightsUpTo[i]-nRightsUpTo[Math.abs(j)];
				if(j>0)
					System.out.println(Math.min(rAfter,size-1+lAfter));
				else
					System.out.println(Math.min(lAfter,size-1+rAfter));
			}
		}
		sc.close();
	}
}