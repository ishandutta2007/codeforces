import java.util.*;
public class D {
	private static int n;
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		int m=sc.nextInt();
		HashMap<Integer,HashMap<Integer,Integer>>candies=new HashMap<Integer,HashMap<Integer,Integer>>();
		for(int i=0;i<n;i++)
			candies.put(i,new HashMap<Integer,Integer>());
		for(int i=0;i<m;i++){
			int a=sc.nextInt()-1,b=sc.nextInt()-1;
			if(candies.get(a).containsKey(b))
				candies.get(a).put(b,candies.get(a).get(b)+1);
			else
				candies.get(a).put(b,1);
		}
		sc.close();
		for(int i=0;i<n;i++){
			int c=m,s=i;
			int tDest=-1;
			int ct=0;
			HashMap<Integer,HashMap<Integer,Integer>>cand=new HashMap<Integer,HashMap<Integer,Integer>>();
			for(int a:candies.keySet()){
				cand.put(a,new HashMap<Integer,Integer>());
				for(int b:candies.get(a).keySet())
					cand.get(a).put(b,candies.get(a).get(b));
			}
			while(c>0||tDest!=-1){
				if(!cand.get(s).isEmpty()){
					int b=bestCandy(cand.get(s),s);
					c--;
					if((b-s+n)%n>(tDest-s+n)%n||tDest==-1)
						tDest=b;
				}
				if(s==tDest)
					tDest=-1;
				ct++;
				s=(s+1)%n;
			}
			System.out.print(ct-1+" ");
		}
	}
	private static int bestCandy(HashMap<Integer,Integer>set,int station){
		int best=0,candy=-1;
		for(int i:set.keySet())
			if((i-station+n)%n>best){
				best=(i-station+n)%n;
				candy=i;
			}
		if(set.get(candy)==1)
			set.remove(candy);
		else
			set.put(candy,set.get(candy)-1);
		return candy;
	}
}