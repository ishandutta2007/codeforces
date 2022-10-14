//package a2oj;
import java.util.*;

public class ArrayAndOperations {
	static ArrayList<LinkedList<Integer>> good = new ArrayList<LinkedList<Integer>>();
	static int[] a, par, f;
	static int[][] cap;
	static int n, m;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		a = new int[n + 2];
		par = new int[n + 2];
		f = new int[n + 2];
		HashSet<Integer> primes = new HashSet<Integer>();
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			primes.addAll(factors(a[i]));
		}
		for(int i = 0; i < n + 2; i++)
			good.add(new LinkedList<Integer>());
		for(int i = 0; i < m; i++) {
			int u = sc.nextInt() - 1, v = sc.nextInt() - 1;
			if(u % 2 == 0)
				good.get(u).add(v);
			else
				good.get(v).add(u);
			primes.addAll(factors(gcd(a[u], a[v])));
		}
		sc.close();
		cap = new int[n + 2][n + 2];
		for(int i = 0; i < n; i++)
			if(i % 2 == 0)
				good.get(n).add(i);
			else
				good.get(i).add(n + 1);
		int ans = 0;
		for(int p : primes)
			ans += maxflow(p);
		System.out.println(ans);
	}
	static void display() {
		for(int[] i : cap) {
			for(int j : i)
				System.out.print(j + " ");
			System.out.println();
		}
		System.out.println("________________________________________");
	}
	static int maxflow(int p) {
		cap = new int[n + 2][n + 2];
		for(int i = 0; i < n + 2; i++)
			for(int j : good.get(i))
				cap[i][j] = maxPow(a[i], a[j], p);
		int flow = 0, newFlow;
		while((newFlow = bfs()) != 0) {
			flow += newFlow;
			int node = n + 1;
			while(node != n) {
				cap[par[node]][node] -= newFlow;
				cap[node][par[node]] += newFlow;
				node = par[node];
			}
		}
		return flow;
	}
	static int bfs() {
		for(int i = 0; i < n + 2; i++)
			par[i] = -1;
		boolean[] used = new boolean[n + 2];
		f[n] = Integer.MAX_VALUE;
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(n);
		while(!q.isEmpty()) {
			int i = q.pollFirst();
			if(!used[i]) {
				used[i] = true;
				for(int j = n + 1; j >= 0; j--)
					if(par[j] == -1 && cap[i][j] > 0) {
						par[j] = i;
						f[j] = Math.min(cap[i][j], f[i]);
						if(j == n + 1)
							return f[j];
						q.add(j);
					}
			}
		}
		return 0;
	}
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	static int maxPow(int a, int b, int p) {
		return a % p == 0 && b % p == 0 ? maxPow(a / p, b / p, p) + 1 : 0;
	}
	static HashSet<Integer> factors(int x) {
		HashSet<Integer> set = new HashSet<Integer>();
		for(int i = 2; i * i <= x; i++)
			if(x % i == 0) {
				set.add(i);
				while(x % i == 0)
					x /= i;
			}
		if(x > 1)
			set.add(x);
		return set;
	}
}