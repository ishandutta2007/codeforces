import java.util.*;
import static java.lang.Math.*;

public class SolutionC {
	static void dfs(int i) {
		vis[i] = 1;
		cnt++;

		for(int j : adj[i]) {
			if(vis[j] == 0)
				dfs(j);
		}
	}

	static long fast_pow(long a, long b) {
		if(b == 0)
			return 1L;

		long val = fast_pow(a, b / 2);

		if(b % 2 == 0)
			return val * val % mod;
		else 
			return val * val % mod * a % mod;
	}
	static long mod = (long)1e9 + 7;

	static ArrayList<Integer> adj[];
	static int vis[];
	static long cnt = 0;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int k = sc.nextInt();

		adj = new ArrayList[n];
		for(int i = 0; i < n; ++i)
			adj[i] = new ArrayList<>();

		for(int i = 0; i < n - 1; ++i) {
			int u = sc.nextInt() - 1;
			int v = sc.nextInt() - 1;
			int col = sc.nextInt();

			if(col == 0) {
				adj[u].add(v);
				adj[v].add(u);
			}
		}

		long ans = fast_pow(n, k);
		long rem = 0;

		vis = new int[n];
		for(int i = 0; i < n; ++i) {
			if(vis[i] == 0) {
				cnt = 0;
				dfs(i);
				rem += fast_pow(cnt, k);
			}
		}

		rem %= mod;
		ans = (ans - rem + mod) % mod;

		System.out.print(ans);
	}
}