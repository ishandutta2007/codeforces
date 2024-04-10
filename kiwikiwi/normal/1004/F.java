
import java.io.*;
import java.util.*;

public class F {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}

	static class info {
		int val[] = new int[22];
		int pos[] = new int[22];
		int len = 0;
		public void init() {
			len = 0;
		}
		public void init(int v, int p) {
			val[0] = v;
			pos[0] = p;
			len = 1;
		}
		public void add(info b) {
			int v = 0;
			if (len != 0) v = val[len - 1];
			for (int i = 0; i < b.len; i++) {
				if ((v | b.val[i]) > v || len == 0) {
					v |= b.val[i];
					val[len] = v;
					pos[len] = b.pos[i];
					len++;
				}
			}
		}
	}

	static class Task {
		info candl[];
		info candr[];
		long s[];
		int a[];
		int x = 0;
		int xl = 0;
		long ans = 0;
		info queryl = new info();
		info tmp = new info();

		long merge(int l, int r, info cl, info cr) {
			long ans = 0;
			if (cl.len == 0 || cr.len == 0) return ans;
			int j = 0;
			int val = cl.val[0];
			while (j < cr.len && (cr.val[j] | val) < x)
				j++;
			for (int i = 0; i < cl.len; i++) {
				val = cl.val[i];
				while (j > 0 && (cr.val[j - 1] | val) >= x) --j;
				if (j < cr.len) {
					long h = 0;
					if (i < cl.len - 1)
						h = cl.pos[i] - cl.pos[i + 1];
					else
						h = cl.pos[i] - l + 1;

					ans += (r - cr.pos[j] + 1) * h;
				}
			}
			return ans;
		}
		void upd(int p, int l, int r) {
			candl[p].init();
			candl[p].add(candl[p + p]);
			candl[p].add(candl[p + p + 1]);
			candr[p].init();
			candr[p].add(candr[p + p + 1]);
			candr[p].add(candr[p + p]);
			s[p] = s[p + p] + s[p + p + 1] + merge(l, r, candr[p + p], candl[p + p + 1]);
		}

		void build(int p, int l, int r) {
			candl[p] = new info();
			candr[p] = new info();
			if (l == r) {
				candl[p].init(a[l], l);
				candr[p].init(a[l], l);
				s[p] = (a[l] >= x) ? 1 : 0;
			} else {
				int md = (l + r) >> 1;
				build(p + p, l, md);
				build(p + p + 1, md + 1, r);
				upd(p, l, r);
			}
		}
		void modify(int p, int l, int r, int c, int v) {
			if (l == r) {
				a[l] = v;
				candl[p].init(a[l], l);
				candr[p].init(a[l], l);
				s[p] = (a[l] >= x) ? 1 : 0;
			} else {
				int md = (l + r) >> 1;
				if (c <= md) modify(p + p, l, md, c, v);
				else modify(p + p + 1, md + 1, r, c, v);
				upd(p, l, r);
			}
		}
		void query(int p, int l, int r, int tl, int tr) {
			if (l == tl && r == tr) {
				ans += s[p] + merge(xl, r, queryl, candl[p]);
				tmp.init();
				tmp.add(candr[p]);
				tmp.add(queryl);
				queryl.init();
				queryl.add(tmp);
			} else {
				int md = (l + r) >> 1;
				if (tr <= md) query(p + p, l, md, tl, tr);
				else if (tl > md) query(p + p + 1, md + 1, r, tl, tr);
				else {
					query(p + p, l, md, tl, md);
					query(p + p + 1, md + 1, r, md + 1, tr);
				}
			}
		}

		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int n = in.nextInt();
			int m = in.nextInt();
			a = new int[n + 1];
			candl = new info[4 * n + 10];
			candr = new info[4 * n + 10];
			s = new long [4 * n + 10];
			x = in.nextInt();
			for (int i = 1; i <= n; i++) {
				a[i] = in.nextInt();
			}
			build(1, 1, n);
			for (int i = 0; i < m; i++) {
				int op = in.nextInt();
				int l = in.nextInt();
				int r = in.nextInt();
				if (op == 1) {
					modify(1, 1, n, l, r);
				} else {
					ans = 0;
					queryl.init();
					xl = l;
					query(1, 1, n, l, r);
					out.println(ans);
				}
			}
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