import java.util.Scanner;
import java.util.HashMap;
import java.util.HashSet;
public class EternalVictory {
	private static HashMap<Integer,HashSet<int[]>>tree=new HashMap<Integer,HashSet<int[]>>();
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long sum=0;
		for(int i=0;i<n-1;i++){
			int n1=sc.nextInt(),n2=sc.nextInt(),weight=sc.nextInt();
			sum+=2*weight;
			if(!tree.containsKey(n1))
				tree.put(n1,new HashSet<int[]>());
			tree.get(n1).add(new int[]{n2,weight});
			if(!tree.containsKey(n2))
				tree.put(n2,new HashSet<int[]>());
			tree.get(n2).add(new int[]{n1,weight});
		}
		System.out.println(n==1?0:sum-longestPathFrom(1,-1));
		sc.close();
	}
	public static int longestPathFrom(int node,int parent){
		int max=0;
		for(int[]i:tree.get(node))
			if(i[0]!=parent){
				int dist=i[1]+longestPathFrom(i[0],node);
				if(dist>max)
					max=dist;
			}
		return max;
	}
}