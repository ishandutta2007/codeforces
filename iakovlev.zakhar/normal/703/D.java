import java.util.*;
import java.io.*;
import java.nio.file.WatchEvent.Kind;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    public static class Question implements Comparable<Question> {
		int l;
		int r;
		int numberOfTheQuestion;
		
		public Question(int l, int r, int numberOfTheQuestion) {
			this.l = l - 1;
			this.r = r;
			this.numberOfTheQuestion = numberOfTheQuestion;
		}

		@Override
		public int compareTo(Question that) {
			// TODO Auto-generated method stub
			return this.r - that.r;
		}
	}
    
    public static class SegmentTree {
		private int[] tree;
		private final int pow;
		private final int ideal = 0;
		final int ideal1 = 0;
		
		public SegmentTree(int[] a) {
			int length = a.length;
			int p = 1;
			while (p < length) {
				p *= 2;
			}
			pow = p;
			tree = new int[2 * pow];
			for (int i = 0; i < a.length; i++) {
				tree[pow + i] = a[i];
			}
			for (int i = pow + a.length; i < tree.length; i++) {
				tree[i] = ideal;
			}
			make(1);
		}
		
		public SegmentTree(int length) {
			int p = 1;
			while (p < length) {
				p *= 2;
			}
			pow = p;
			tree = new int[2 * pow];
			for (int i = 0; i < pow; i++) {
				tree[pow + i] = ideal;
			}
			make(1);
		}
		
		public void make(int i) {
			if (i >= pow) {
				return;
			}
			make(2 * i);
			make(2 * i + 1);
			tree[i] = function(tree[2 * i], tree[2 * i + 1]);
		}
		
		private int function(int a, int b) {
			return a ^ b;
		}
		
		public int get(int l, int r) {
			return get(l, r, 0, pow, 1);
		}
		
		private int get(int l, int r, int l1, int r1, int i) {
			if (l == l1 && r == r1) {
				return tree[i];
			}
			int m = (l1 + r1) / 2;
			if (r <= m) {
				return get(l, r, l1, m, 2 * i);
			}
			if (l >= m) {
				return get(l, r, m, r1, 2 * i + 1);
			}
			return function(get(l, m, l1, m, 2 * i), get(m, r, m, r1, 2 * i + 1));
		}
		
		public void set(int x, int pos) {
			int i = pow + pos;
			tree[i] = x;
			i /= 2;
			while (i > 0) {
				tree[i] = function(tree[2 * i], tree[2 * i + 1]);
				i /= 2;
			}
		}
	}
    
    public void solve() {
    	int n = in.nextInt();
    	int[] a = new int[n];
    	for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
    	int m = in.nextInt();
    	Question[] question = new Question[m];
    	for (int i = 0; i < question.length; i++) {
			question[i] = new Question(in.nextInt(), in.nextInt(), i);
//			  ,  - 
		}
    	int[] ans = new int[m];
    	Arrays.sort(question);
    	int[] begin = new int[n + 1];
    	for (int i = 0; i < begin.length - 1; i++) {
			begin[i + 1] = begin[i] ^ a[i];
		}
    	HashMap<Integer, Integer> last = new HashMap<>();
    	int i = 0;
    	int j = 0;
    	SegmentTree tree = new SegmentTree(a.length);
    	while (j < question.length) {
			while (i < question[j].r) {
				if (last.containsKey(a[i])) {
					tree.set(tree.ideal1, last.get(a[i]));
				}
				last.put(a[i], i);
				tree.set(a[i], i);
				i++;
			}
			int x1 = begin[question[j].l] ^ begin[question[j].r];
			int x2 = tree.get(question[j].l, question[j].r);
			ans[question[j].numberOfTheQuestion] = x1 ^ x2;
			j++;
		}
    	
    	for (int k = 0; k < ans.length; k++) {
			out.println(ans[k]);
		}
    }

    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("segments.in"));
                out = new PrintWriter(new File("segments.out"));
            }
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;


        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

    }
    public static void main(String[] arg) {
        new D().run();
    }
}