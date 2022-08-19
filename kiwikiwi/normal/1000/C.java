import java.io.*;
import java.util.*;

public class C {
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
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int n = in.nextInt();
			TreeMap<Long, Integer> cnt = new TreeMap<>();
			for (int i = 0; i < n; i++) {
				long l = in.nextLong();
				long r = in.nextLong();
				l = 2 * l - 1;
				r = 2 * r + 1;
				Integer cl = cnt.get(l);
				if (cl != null) cnt.put(l, cl + 1);
				else cnt.put(l, 1);
				Integer cr = cnt.get(r);
				if (cr != null) cnt.put(r, cr - 1);
				else cnt.put(r, -1);
			}
			long [] ans = new long[n + 1];
			long pre = -1;
			int c = 0;
			for (Map.Entry<Long, Integer> it : cnt.entrySet()) {
				Long pos = it.getKey();
				Integer val = it.getValue();
				ans[c] += (pos - pre) / 2;
				pre = pos;
				c += val;
			}
			for (int i = 1; i <= n; i++) {
				out.print(ans[i]+" ");
			}
			out.println();
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