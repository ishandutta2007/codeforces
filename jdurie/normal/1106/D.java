import java.util.*;
public class D {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		HashMap<Integer,HashSet<Integer>>graph=new HashMap<Integer,HashSet<Integer>>();
		for(int i=1;i<=n;i++)
			graph.put(i,new HashSet<Integer>());
		for(int i=0;i<m;i++){
			int a=sc.nextInt(),b=sc.nextInt();
			graph.get(a).add(b);
			graph.get(b).add(a);
		}
		sc.close();
		HashSet<Integer>used = new HashSet<Integer>();
		TreeSet<Integer>canReach = new TreeSet<Integer>();
		canReach.add(1);
		while(!canReach.isEmpty()){
			int min=canReach.pollFirst();
			used.add(min);
			System.out.print(min+" ");
			for(int i:graph.get(min))
				if(!used.contains(i))
					canReach.add(i);
		}
	}
}