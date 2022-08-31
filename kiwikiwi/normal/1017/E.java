import java.io.*;
import java.util.*;

public class E {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task {
		long cross(long p1[], long p2[], long p3[]) {
			return (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p3[0] - p1[0]) * (p2[1] - p1[1]);
		}
		int crossOp(long p1[], long p2[], long p3[]) {
			long det = cross(p1, p2, p3);
			if (det > 0) return 1;
			else if (det < 0) return -1;
			else return 0;
		}
		long [][] readhull(InputReader in, int n) {
			long p[][] = new long[n][2];
			long sp[] = new long[n];
			for (int i = 0; i < n; i++) {
				long x = in.nextInt();
				long y = in.nextInt();
				sp[i] = (x << 30) + y;
			}
			Arrays.sort(sp);
			for (int i = 0; i < n; i++) {
				p[i][0] = sp[i] >> 30;
				p[i][1] = sp[i] & ((1 << 30) - 1);
			}
			long [][] q = new long[2 * n][2];
			int k = 0;
			for (int i = 0; i < n; i++) {
				while (k > 1 && crossOp(q[k - 2], q[k - 1], p[i]) <= 0) --k;
				q[k][0] = p[i][0];
				q[k][1] = p[i][1];
				k++;
			}
			int t = k;
			for (int i = n - 2; i >= 0; i--) {
				while (k > t && crossOp(q[k - 2], q[k - 1], p[i]) <= 0) --k;
				q[k][0] = p[i][0];
				q[k][1] = p[i][1];
				k++;
			}
			k -= 1;
			long f[][] = new long[k][2];
			for (int i = 0; i < k; i++) {
				f[i][0] = q[i][0];
				f[i][1] = q[i][1];
			}
			return f;
		}
		boolean check(long p1[][], long p2[][]) {
			int n = p1.length;
			if (p2.length != n) return false;
			long dx = p2[0][0] - p1[0][0];
			long dy = p2[0][1] - p1[0][1];
			for (int i = 0; i < n; i++) {

				if (p2[i][0] != p1[i][0] + dx) return false;
				if (p2[i][1] != p1[i][1] + dy) return false;
			}
			return true;
		}
		void rotate(long p[][]) {
			int n = p.length;
			for (int i = 0; i < n; i++) {
				long x = p[i][0];
				long y = p[i][1];
				p[i][0] = -y;
				p[i][1] = x;
			}
			int pos = -1;
			long minx = 1l << 60;
			long miny = 1l << 60;
			for (int i = 0; i < n; i++) {
				if (p[i][0] < minx || (p[i][0] == minx && p[i][1] < miny)) {
					minx = p[i][0];
					miny = p[i][1];
					pos = i;
				}
			}
			long q[][] = new long[n][2];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < 2; j++) q[i][j] = p[(i + pos) % n][j];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < 2; j++) p[i][j] = q[i][j];
		}
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int n = in.nextInt();
			int m = in.nextInt();
			long l1[][] = readhull(in, n);
			long l2[][] = readhull(in, m);
			for (int i = 0; i < 4; i++) {
				if (check(l1, l2)) {
					out.println("YES");
					return;
				}
				rotate(l2);
			}
			out.println("NO");
		}
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

	}
}