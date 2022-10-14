//package a2oj;
import java.util.*;
public class SuperM {
	private static HashMap<Integer, HashSet<Integer>> tree = new HashMap<Integer, HashSet<Integer>>();
	private static boolean[] bad;
	private static Pair[] longPath;
	private static int n, m;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		bad = new boolean[n];
		longPath = new Pair[n];
		for(int i = 0; i < n; i++)
			tree.put(i, new HashSet<Integer>());
		for(int i = 0; i < n - 1; i++) {
			int a = sc.nextInt() - 1, b = sc.nextInt() - 1;
			tree.get(a).add(b);
			tree.get(b).add(a);
		}
		for(int i = 0; i < m; i++)
			bad[sc.nextInt() - 1] = true;
		sc.close();
		Pair root = fixTree(0, -1);
		int dist = 2 * dfs(root.i, root.j) - 2;
		lPath(root.i, root.j);
		Pair lPath = longPath[root.i];
		for(int i = 0; i < n; i++)
			if(longPath[i] != null && longPath[i].greater(lPath))
				lPath = longPath[i];
		System.out.println(lPath.i + 1);
		System.out.println(dist - lPath.j);
	}
	static class Pair {
		int i, j;
		public Pair(int I, int J) {
			i = I;
			j = J;
		}
		public boolean greater(Pair p) {
			if(j == p.j)
				return i < p.i;
			return j > p.j;
		}
	}
	private static Pair lPath(int i, int p) {
		Pair max = new Pair(i, 0), sMax = new Pair(i, 0);
		for(int j : tree.get(i))
			if(j != p) {
				Pair lP = lPath(j, i);
				lP.j++;
				if(lP.greater(max)) {
					sMax = max;
					max = lP;
				} else if(lP.greater(sMax))
					sMax = lP;
			}
		longPath[i] = new Pair(Math.min(max.i, sMax.i), max.j + sMax.j);
		return max;
	}
	private static Pair fixTree(int i, int p) {
		LinkedList<Integer> remove = new LinkedList<Integer>();
		Pair root = bad[i] ? new Pair(i, p) : new Pair(-1, -1);
		for(int j : tree.get(i)) 
			if(j != p) {
				Pair jRoot = fixTree(j,i);
				if(jRoot.i == -1)
					remove.add(j);
				else if(root.i == -1)
					root = jRoot;
				else
					root = new Pair(i, p);
			}
		for(int x : remove)
			tree.get(i).remove(x);
		return root;
	}
	private static int dfs(int i, int p) {
		int ans = 1;
		for(int j : tree.get(i))
			if(j != p)
				ans += dfs(j, i);
		return ans;
	}
}