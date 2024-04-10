import java.util.*;

public class C {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),k=sc.nextInt();
		int[]a=new int[n];
		for(int i=0;i<n;i++)
			a[i]=sc.nextInt();
		sc.nextLine();
		String s=sc.nextLine()+"*";
		sc.close();
		long dmg=0;
		TreeMap<Integer,Integer>maxes=new TreeMap<Integer,Integer>();
		char last='*';
		for(int i=0;i<=n;i++){
			char next=s.charAt(i);
			if(next!=last){
				int count=0;
				while(!maxes.isEmpty()&&count++<k){
					int l=maxes.lastKey();
					dmg+=(long)l;
					if(maxes.get(l)==1)
						maxes.remove(l);
					else
						maxes.put(l,maxes.get(l)-1);
				}
				maxes=new TreeMap<Integer,Integer>();
			}
			if(i<n&&maxes.containsKey(a[i]))
				maxes.put(a[i],maxes.get(a[i])+1);
			else if(i<n)
				maxes.put(a[i],1);
			last=next;
		}
		System.out.println(dmg);
	}
}