import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	InputStreamReader inp = new InputStreamReader(System.in);
	BufferedReader br = new BufferedReader(inp);
	Scanner sc = new Scanner(inp);
	
	// input data
	
	int n;
	int[] p;
	void inputData() {
		n = sc.nextInt();
		p = new int[n];
		for (int i=0; i<n; i++) {
			p[i] = sc.nextInt();
			if (p[i]>0) p[i]--;
		}
	}

	// intermediate

	int ans = 0;
	void solve() {
		for (int i=0; i < n; i++) {
			int cur = i;
			int h = 0;
			while (cur != -1) {
				h++;
				cur = p[cur];
			}
			ans = Math.max(ans, h);
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