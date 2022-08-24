import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;
import java.io.*;

public class E {
	public static void main(String[] args) {
		new E().run();
	}
	Scanner in = new Scanner(System.in);
	
	final int INF = 501001001;
	int m, n;
	int k;
	int mn;
	int[] weights;
	int[] ts;
	int[][] dist;
	int[][] mid;
	int[][] dp;
	int[][] prev;
	boolean[] pave;
	
	void run() {
		for (; in.hasNext(); ) {
			m = in.nextInt();
			n = in.nextInt();
			k = in.nextInt();
			mn = m * n;
			weights = new int[mn];
			for (int u = 0; u < mn; ++u) {
				weights[u] = in.nextInt();
			}
			ts = new int[k];
			for (int i = 0; i < k; ++i) {
				int x = in.nextInt() - 1, y = in.nextInt() - 1;
				ts[i] = x * n + y;
			}
			int weightsSum = 0;
			for (int i = 0; i < k; ++i) {
				int u = ts[i];
				weightsSum += weights[u];
				weights[u] = 0;
			}
			dist = new int[mn][mn];
			mid = new int[mn][mn];
			for (int u = 0; u < mn; ++u) for (int v = 0; v < mn; ++v) {
				dist[u][v] = INF;
				mid[u][v] = -1;
			}
			for (int u = 0; u < mn; ++u) for (int v = 0; v < mn; ++v) {
				if (abs(u / n - v / n) + abs(u % n - v % n) <= 1) {
					dist[u][v] = 0;
				}
			}
			for (int w = 0; w < mn; ++w) for (int u = 0; u < mn; ++u) for (int v = 0; v < mn; ++v) {
				if (dist[u][v] > dist[u][w] + weights[w] + dist[w][v]) {
					dist[u][v] = dist[u][w] + weights[w] + dist[w][v];
					mid[u][v] = w;
				}
			}
// _out(dist);
			dp = new int[1 << k][mn];
			prev = new int[1 << k][mn];
			for (int p = 0; p < 1 << k; ++p) {
				fill(dp[p], INF);
				fill(prev[p], -1);
			}
			for (int p = 1; p < 1 << k; ++p) {
				if ((p & p - 1) != 0) {
					for (int q = p; ; ) {
						--q; q &= p; if (q == 0) break;
						for (int u = 0; u < mn; ++u) {
							if (dp[p][u] > dp[q][u] + dp[p ^ q][u]) {
								dp[p][u] = dp[q][u] + dp[p ^ q][u];
								prev[p][u] = mn + q;
							}
						}
					}
					for (int u = 0; u < mn; ++u) for (int v = 0; v < mn; ++v) {
						if (dp[p][u] > dp[p][v] + dist[u][v] + weights[v]) {
							dp[p][u] = dp[p][v] + dist[u][v] + weights[v];
							prev[p][u] = v;
						}
					}
				} else {
					int i = Integer.numberOfTrailingZeros(p);
					for (int u = 0; u < mn; ++u) {
						dp[p][u] = dist[ts[i]][u];
					}
				}
// _out("dp",p,":",dp[p]);
			}
			int opt;
			pave = new boolean[mn];
			opt = INF;
			int pm = (1 << k) - 1, um = -1;
			for (int u = 0; u < mn; ++u) {
				if (opt > dp[pm][u] + weights[u]) {
					opt = dp[pm][u] + weights[u];
					um = u;
				}
			}
// _out("um",um);
			// opt = dp[pm][u] + weights[u];
			recover(pm, um);
			pave[um] = true;
			opt += weightsSum;
			for (int i = 0; i < k; ++i) {
				pave[ts[i]] = true;
			}
			System.out.println(opt);
			for (int x = 0; x < m; ++x) {
				for (int y = 0; y < n; ++y) {
					int u = x * n + y;
					System.out.print(pave[u] ? 'X' : '.');
				}
				System.out.println();
			}
int sum=weightsSum;for(int u=0;u<mn;++u)if(pave[u])sum+=weights[u];
// _out("sum =",sum);
if(sum<opt)for(;;);
if(sum>opt)sum=1/0;
		}
	}
	void recover(int p, int u) {
// _out("recover",p,u);
		if (prev[p][u] < 0) {
			// dp[p][u] = dist[ts[i]][u];
			int i = Integer.numberOfTrailingZeros(p);
			recoverPath(ts[i], u);
		} else if (prev[p][u] < mn) {
			// dp[p][u] = dp[p][v] + dist[u][v] + weights[v];
			int v = prev[p][u];
			recover(p, v);
			recoverPath(u, v);
			pave[v] = true;
		} else {
			// dp[p][u] = dp[q][u] + dp[p ^ q][u];
			int q = prev[p][u] - mn;
			recover(q, u);
			recover(p ^ q, u);
		}
	}
	void recoverPath(int u, int v) {
// _out("recoverPath",u,v);
		if (mid[u][v] < 0) {
		} else {
			// dist[u][v] = dist[u][w] + weights[w] + dist[w][v];
			int w = mid[u][v];
			recoverPath(u, w);
			pave[w] = true;
			recoverPath(w, v);
		}
	}
	
	void _out(Object...os) {
		System.out.println(deepToString(os));
	}
}