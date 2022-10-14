import java.util.*;

public class ZeroTree {
	private static HashMap<Integer, HashSet<Integer>>tree = new HashMap<Integer, HashSet<Integer>>();
	private static long[] plus;
	private static long[] minus;
	private static long[] v;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0; i<n; i++)
			tree.put(i, new HashSet<Integer>());
		for(int i=0; i<n-1; i++){
			int a = sc.nextInt()-1, b = sc.nextInt()-1;
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		v = new long[n];
		for(int i=0; i<n; i++)
			v[i] = sc.nextLong();
		sc.close();
		plus = new long[n];
		minus = new long[n];
		fillPM(0, -1);
		System.out.println(plus[0]+minus[0]);
	}
	private static void fillPM(int a, int par){
		for(int i:tree.get(a))
			if(i!=par){
				fillPM(i, a);
				plus[a] = Math.max(plus[a], plus[i]);
				minus[a] = Math.max(minus[a], minus[i]);
			}
		v[a] += plus[a]-minus[a];
		if(v[a]>0)
			minus[a]+=v[a];
		else
			plus[a]-=v[a];
	}
}