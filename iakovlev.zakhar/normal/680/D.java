import java.util.*;
import java.io.*;
import java.nio.file.WatchEvent.Kind;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    public static class Pair {
		long x;
		long number;
		
		public Pair(long x, long number) {
			// TODO Auto-generated constructor stub
			this.number = number;
			this.x = x;
		}
	}
    
    public static boolean normal(ArrayList<Integer> a) {
//    	for (int i = 0; i < a.size(); i++) {
//			System.out.println(a.get(i));
//		}
//    	System.out.println();
		long sum = 0;
		for (int i = 0; i < a.size(); i++) {
			sum += cube[a.get(i)];
			if (sum >= cube[a.get(i) + 1]) {
				return false;
			}
		}
		if (sum > n) {
			return false;
		}
		return true;
	}
    
    static long n;
    static long[] cube;
    
    public void solve() {
    	n = in.nextLong();
//    	int l = 1;
//    	int r = 100001;
//    	while (l + 1 < r) {
//			int m = (l + r) / 2;
//			if (1L * m * m * m <= n) {
//				l = m;
//			} else {
//				r = m;
//			}
//		}
    	cube = new long[100010];
    	for (int i = 0; i < cube.length; i++) {
			cube[i] = 1L * i * i * i;
//			System.out.println(cube[i]);
		}
    	int c = 1;
    	int ans = 0;
    	long sum = 0;
    	TreeMap<Integer, Integer> used = new TreeMap<>();
    	while (sum + cube[c] <= n) {
			if (sum + cube[c] >= cube[c + 1]) {
				c++;
			} else {
				sum += cube[c];
				if (used.containsKey(c)) {
					used.put(c, used.get(c) + 1);
				} else {
					used.put(c, 1);
				}
				ans++;
			}
		}
    	System.out.print/*ln*/(ans + " "/* + sum*/);
    	ArrayList<Integer> a = new ArrayList<>();
    	for (int i : used.keySet()) {
    		for (int j = 0; j < used.get(i); j++) {
				a.add(i);
//				System.out.println(a.get(a.size() - 1));
			}
    	}
    	int lastUsed = used.lastKey();
    	int lastUnsed = 100000;
    	long thissum = sum;
    	long thissumUsed = sum;
    	int lastOut = -0;
    	for (int i = a.size() - 1; i >= 0; i--) {
    		int left = lastUsed;
    		int right = lastUnsed + 1;
			while (left + 1 < right) {
				int m = (left + right) / 2;
				a.set(i, m);
				if (normal(a)) {
					left = m;
				} else {
					right = m;
				}
			}
			a.set(i, left);
//			System.out.println(lastUsed + left);
			lastUnsed = a.get(i);
			if (i != 0) {
				lastUsed = a.get(i - 1);
			}
		}
    	sum = 0;
    	for (int i = 0; i < a.size(); i++) {
			sum += cube[a.get(i)];
		}
    	System.out.println(sum);
//    	ArrayList<Pair> a = new ArrayList<>();
//    	ArrayList<Integer> left = new ArrayList<>();
//    	a.add(new Pair(0, 0));
//    	left.add(0);
//    	int c = 1;
//    	long next = 1;
//    	int x = 0;
//    	long number = 1;
//    	boolean flag = false;
//    	while (next <= n) {
//    		System.out.println(next + " " + number + " " + x);
//			if (next >= cube[c]) {
//				c++;
//				if (next != 1) {
//					x = left.get((int) (a.get(a.size() - 1).number - 1));
//				}
//			} else {
//				a.add(new Pair(next, number));
//				if (left.size() == number) {
//					left.add(a.size() - 1);
//				}
//				x++;
//			}
//			next = cube[c - 1] + a.get(x).x;
//			number = a.get(x).number + 1;
//		}
//    	System.out.print(left.size() - 1 + " " + a.get(a.size() - 1).x);
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