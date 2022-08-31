import java.io.*;
import java.util.*;

public class Task_new {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	long ceilDiv(long a, long b) {
		return Math.floorDiv(a + b - 1, b);
	}
	
	static final int LIMIT = 100_000;
	
	void solve() throws IOException {
		int n = nextInt();
		long r = nextLong();
		
		List<Long> ans = new ArrayList<>(100000);
		long ansSize = 0;
		
		long remDur = 0;
		
		long[] lens = new long[n];
		long[] times = new long[n];
		
		for (int i = 0; i < n; i++) {
			lens[i] = nextLong() * 2;
			
		}
		
		for (int i = 0; i < n; i++) {
			times[i] = nextLong();
			
		}
		
		long curTime = 0;
		
		for (int i = 0; i < n; i++) {
			long len = lens[i];
			long time = times[i];
			
			if (len > 2 * time) {
				out.println(-1);
				return;
			}
			
			if (2 * remDur >= len) {
				remDur -= len / 2;
				curTime += len / 2;
				continue;
			}
			
			time -= remDur;
			len -= 2 * remDur;
			curTime += remDur;
			
			remDur = 0;
			
			if (time >= len) {
				curTime += len;
				remDur = 0;
				continue;
			}
			if (2 * time < len) {
				throw new AssertionError();
			}
			
			
			long walk = 2 * time - len;
			long run = time - walk;
			
			curTime += walk;
			
			long count = ceilDiv(run, r);
			ansSize += count;
			if (ansSize <= LIMIT) {
				for (int j = 0; j < count; j++) {
					ans.add(curTime + j * r);
				}
			}
			
			curTime += run;
			remDur = count * r - run;
		}
		
		out.println(ansSize);
		if (ansSize <= LIMIT) {
			for (long x : ans) {
				out.print(x + " ");
			}
			out.println();
		}
		
	}
	
	void run() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		solve();
		
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Task_new().run();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}