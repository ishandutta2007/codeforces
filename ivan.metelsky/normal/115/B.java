import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	InputStreamReader inp = new InputStreamReader(System.in);
	BufferedReader br = new BufferedReader(inp);
	Scanner sc = new Scanner(inp);
	
	// input data
	
	int n, m;
	char[][] brd;
	void inputData() {
		n = sc.nextInt();
		m = sc.nextInt();
		brd = new char[n][m];
		for (int i=0; i<n; i++)
			brd[i] = sc.next().toCharArray();
	}

	// intermediate
	int ans;
	void solve() {
		int[] left = new int[n];
		int[] right = new int[n];
		Arrays.fill(left, 10000);
		Arrays.fill(right, -10000);
		for (int i=0; i<n; i++) for (int j=0; j<m; j++)
			if (brd[i][j] == 'W') {
				left[i] = Math.min(left[i], j);
				right[i] = Math.max(right[i], j);
			}
		
		int[][] best = new int[n+1][m];
		for (int i=0; i<best.length; i++)
			Arrays.fill(best[i], 1000000000);
		
		best[0][0] = 0;
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++) {
				int dir = i % 2 == 0 ? 1 : -1;
				for (int k=j; k<m && k>=0; k += dir) {
					if (left[i] >= Math.min(j, k) && right[i] <= Math.max(j, k))
						best[i+1][k] = Math.min(best[i+1][k], best[i][j] + Math.abs(k - j) + 1);
				}
			}
		
		ans = 1000000000;
		for (int j=0; j<m; j++)
			ans = Math.min(ans, best[n][j] - 1);
		
		int i = n - 1;
		while (i > 0 && left[i] == 10000) {
			i--; ans--;
		}
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