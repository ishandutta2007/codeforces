import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	InputStreamReader inp = new InputStreamReader(System.in);
	BufferedReader br = new BufferedReader(inp);
	Scanner sc = new Scanner(inp);
	
	// input data
	
	int n, m;
	long[] repair;
	
	Race[] race;
	
	class Race implements Comparable<Race> {
		int from, to;
		long cost;
		public Race(int from, int to, long cost) {
			this.from = from;
			this.to = to;
			this.cost = cost;
		}
		public int compareTo(Race other) {
			return this.to - other.to;
		}
	}
	
	void inputData() throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		repair = new long[n+1];
		for (int i=1; i<=n; i++)
			repair[i] = Integer.parseInt(br.readLine());
		race = new Race[m];
		for (int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			race[i] = new Race(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 
					Integer.parseInt(st.nextToken()));
		}
		Arrays.sort(race);
	}
	
	class MaximumTree {
		int l, r;
		MaximumTree left, right;
		long max, add;
		public MaximumTree(int l, int r) {
			this.l = l;
			this.r = r;
			this.max = 0;
			this.add = 0;
			if (l < r) {
				this.left = new MaximumTree(l, (l + r) / 2);
				this.right = new MaximumTree((l + r) / 2 + 1, r);
			}
		}
		void modify(int l, int r, long value) {
			if (l == this.l && r == this.r)
				this.add += value;
			else {
				if (l <= this.left.r)
					this.left.modify(l, Math.min(this.left.r, r), value);
				if (r >= this.right.l)
					this.right.modify(Math.max(this.right.l, l), r, value);
				this.max = Math.max(this.left.max + this.left.add, this.right.max + this.right.add);
			}
		}
		long findMax(int l, int r) {
			return findMax(l, r, this.add);
		}
		long findMax(int l, int r, long sumAdd) {
			if (l == this.l && r == this.r)
				return sumAdd + this.max;
			else {
				long res = -1000000000000000000l;
				if (l <= this.left.r)
					res = Math.max(res, this.left.findMax(l, Math.min(this.left.r, r), sumAdd + this.left.add));
				if (r >= this.right.l)
					res = Math.max(res, this.right.findMax(Math.max(this.right.l, l), r, sumAdd + this.right.add));
				return res;
			}
		}
	}

	// intermediate
	long ans;
	void solve() {
		long[] combRepair = new long[n+1];
		combRepair[0] = 0;
		for (int i=1; i<=n; i++)
			combRepair[i] = combRepair[i-1] + repair[i];
		
		MaximumTree tree = new MaximumTree(0, n);
		long totalRaceProfit = 0;
		int curRace = 0;
		long[] F = new long[n+1];
		F[0] = 0;
		for (int i=1; i<=n; i++) {
			F[i] = F[i-1];
			while (curRace < m && race[curRace].to == i) {
				tree.modify(race[curRace].from, n, - race[curRace].cost);
				totalRaceProfit += race[curRace].cost;
				curRace++;
			}
			F[i] = Math.max(F[i], tree.findMax(0, i-1) - combRepair[i] + totalRaceProfit);
			tree.modify(i, i, F[i] + combRepair[i]);
		}
		ans = 0;
		for (int i=0; i<=n; i++)
			ans = Math.max(ans, F[i]);
	}
	
	// output data
	
	void writeData() {
		System.out.println(ans);
	}
		
	// ================================================== //
	
	void solveAlternative() {
	}
	
	public Solution () {
	}
	
	// generate test case
	public Solution(Random rnd) {
	}
	
	// ================================================== //
	
	static void solveTask() throws Exception {
		Solution sol = new Solution();
		sol.inputData();
		sol.solve();
		sol.writeData();
	}
	
	static void stressTest() {
		Random rnd = new Random();
		int it = 0;
		while (true) {
			it++;
			System.out.println("testing case #" + it);
			
			long seed = rnd.nextLong();
			
			// generate test case into sol
			Random g = new Random();
			g.setSeed(seed);
			Solution sol = new Solution(g);

			// copy test case into sol1
			g = new Random();
			g.setSeed(seed);
			Solution sol1 = new Solution(g);

			// launch
			sol.solve();
			sol1.solveAlternative();
			
			// compare answers
		}
	}
	
	public static void main(String[] args) throws Exception {
		solveTask();
		// stressTest()
	}
}