import java.io.*;
import java.util.*;

public class Task {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final long INF = Long.MAX_VALUE / 10;
	
	static class Segment {
		long l, r;

		public Segment(long l, long r) {
			this.l = l;
			this.r = r;
		}
	}
	
	void solve() throws IOException {
		int n = nextInt();
		
		List<Segment> lst = new ArrayList<>();
		
		lst.add(new Segment(1, INF));
		
		outer: for (int i = 0; i < n; i++) {
			long from = nextLong();
			long len = nextLong();
			
			long to = from + len - 1;
			
			int bestIdx = -1;
			long leftmost = INF;
			
			for (int j = 0; j < lst.size(); j++) {
				Segment s = lst.get(j);
				if (s.l <= from && to <= s.r) {
					lst.remove(j);
					lst.add(new Segment(s.l, from - 1));
					lst.add(new Segment(to + 1, s.r));
					out.println(from + " " + to);
					continue outer;
				}
				
				if (s.r - s.l + 1 >= len) {
					if (s.l < leftmost) {
						leftmost = s.l;
						bestIdx = j;
					}
				}
			}
			
			Segment s = lst.get(bestIdx);
			s.l += len;
			
			out.println(leftmost + " " + (leftmost + len - 1));
		}
		
	}
	
	void run() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		solve();
		
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new Task().run();
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