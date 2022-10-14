import java.util.*;
public class D {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long s=2*sc.nextLong();
		HashMap<Integer,HashSet<Integer>>tree=new HashMap<Integer,HashSet<Integer>>();
		for(int i=1;i<=n;i++)
			tree.put(i,new HashSet<Integer>());
		for(int m=0;m<n-1;m++){
			int a=sc.nextInt(),b=sc.nextInt();
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		sc.close();
		double ct=0;
		for(int i:tree.keySet())
			if(tree.get(i).size()==1)
				ct++;
		System.out.println(s/ct);
	}
}