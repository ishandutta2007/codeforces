import java.util.*;
import java.io.*;
import java.nio.file.WatchEvent.Kind;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    public static void f() {
		for (int i = 2; i <= Math.sqrt(k); i++) {
			if (k % i == 0) {
				long th = i;
				k /= i;
				while (k % i == 0) {
					k /= i;
					th *= i;
				}
				h.add((int) th);
			}
		}
		if (k != 1) {
			h.add(k);
		}
	}
    
    static int k;
    static HashSet<Integer> h = new HashSet<>();
    
    public void solve() {
    	int n = in.nextInt();
    	k = in.nextInt();
    	int[] c = new int[n];
    	for (int i = 0; i < c.length; i++) {
			c[i] = in.nextInt();
		}
    	f();
    	ArrayList<Integer> a = new ArrayList<>();
    	for (int i = 0; i < c.length; i++) {
			if (h.size() == 0) {
				System.out.println("Yes");
				return;
			}
			for (int x : h) {
				if (c[i] % x == 0) {
					a.add(x);
				}
			}
			for (int j = 0; j < a.size(); j++) {
				h.remove(a.get(j));
			}
			a.clear();
		}
    	if (h.size() == 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
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