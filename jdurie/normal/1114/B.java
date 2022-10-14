import java.util.*;

public class B2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
		TreeMap<Integer,TreeSet<Integer>>a=new TreeMap<Integer,TreeSet<Integer>>();
		for(int i=0;i<n;i++){
			int x=sc.nextInt();
			if(!a.containsKey(x))
				a.put(x,new TreeSet<Integer>());
			a.get(x).add(i+1);
		}
		sc.close();
		Integer[]inds=new Integer[k*m];
		long sum=0;
		for(int i=0;i<k*m;i++){
			int l=a.lastKey();
			sum+=l;
			inds[i]=a.get(l).pollLast();
			if(a.get(l).size()==0)
				a.remove(l);
		}
		Arrays.sort(inds);
		int ind=-1;
		System.out.println(sum);
		for(int i=1;i<=k-1;i++)
			System.out.print((inds[ind+=m])+" ");
	}
}