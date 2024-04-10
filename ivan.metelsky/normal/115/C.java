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
	void inputData() throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		brd = new char[n][];
		for (int i=0; i<n; i++)
			brd[i] = br.readLine().toCharArray();
	}

	// intermediate

	int ans = 1;
	void solve() {
		for (int i=0; i<n; i++) {
			int ways = 0;
			for (int st=0; st<2; st++) {
				boolean ok = true;
				for (int j=0; j<m; j++) {
					int want = (st + j) % 2;
					if (brd[i][j] == '.') continue;
					if (want == 0 && (brd[i][j] == '3' || brd[i][j] == '4')) ok = false;
					if (want == 1 && (brd[i][j] == '1' || brd[i][j] == '2')) ok = false;
				}
				if (ok) ways++;
			}
			ans = (ans * ways) % 1000003;
		}
		for (int j=0; j<m; j++) {
			int ways = 0;
			for (int st=0; st<2; st++) {
				boolean ok = true;
				for (int i=0; i<n; i++) {
					int want = (st + i) % 2;
					if (brd[i][j] == '.') continue;
					if (want == 0 && (brd[i][j] == '2' || brd[i][j] == '3')) ok = false;
					if (want == 1 && (brd[i][j] == '1' || brd[i][j] == '4')) ok = false;
				}
				if (ok) ways++;
			}
			ans = (ans * ways) % 1000003;
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