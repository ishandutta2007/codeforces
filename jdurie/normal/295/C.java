//package a2oj;
import java.util.*;

public class GregAndFriends {
	static int n, k, a = 0, b = 0;
	static long MOD = 1000000007, ans = 0;
	static long[][] choose = new long[100][100];
	static LinkedList<Integer> q = new LinkedList<Integer>();
	static HashMap<Integer, Pair> ways = new HashMap<Integer, Pair>();
	static class Pair {
		int d;
		long w;
		public Pair(int D, long W) {
			d = D;
			w = W;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		for(int i = 0; i < n; i++)
			if(sc.nextInt() == 50)
				a++;
			else
				b++;
		sc.close();
		fillChoose();
		int startMask = 1000000 + 100 * a + b;
		q.add(startMask);
		ways.put(startMask, new Pair(0, 1));
		while(!q.isEmpty())
			bfs(q.pollFirst());
		System.out.println(ways.containsKey(0) ? ways.get(0).d + "\n" + ways.get(0).w : "-1\n0");
	}
	static void bfs(int mask) {
		int boat = mask / 1000000;
		int nA = (mask % 1000000) / 100, nB = mask % 100;
		if(boat > 0) {
			for(int i = nA; i >= 0 && 50 * (nA - i) <= k; i--)
				for(int j = nB; j >= 0 && 50 * (nA - i) + 100 * (nB - j) <= k; j--)
					if(i != nA || j != nB)
						resolve(i, j, boat, mask, choose[nA][i] * choose[nB][j] % MOD);
		} else {
			for(int i = nA; i <= a && 50 * (i - nA) <= k; i++)
				for(int j = nB; j <= b && 50 * (i - nA) + 100 * (j - nB) <= k; j++)
					if(i != nA || j != nB)
						resolve(i, j, boat, mask, choose[a - nA][i - nA] * choose[b - nB][j - nB] % MOD);
		}
	}
	static void resolve(int i, int j, int boat, int mask, long edgeWays) {
		int newMask = 1000000 * (1 - boat) + i * 100 + j;
		int newD = ways.get(mask).d + 1;
		if(!ways.containsKey(newMask)) {
			ways.put(newMask, new Pair(newD, 0));
			q.add(newMask);
		}
		if(ways.get(newMask).d == newD)
			ways.get(newMask).w = (ways.get(newMask).w + ways.get(mask).w * edgeWays % MOD) % MOD;
	}
	static void fillChoose() {
		for(int i = 0; i < 100; i++)
			choose[i][0] = 1;
		for(int i = 1; i < 100; i++)
			for(int j = 1; j <= i; j++)
				choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
	}
}