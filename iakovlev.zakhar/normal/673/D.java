import java.util.*;
import java.io.*;
import java.nio.file.WatchEvent.Kind;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    
    
    public void solve() {
    	int n = in.nextInt();
    	int k = in.nextInt();
    	if (n == 4 || k <= n || k >= n * (n - 1) / 2 - 1) {
			System.out.println(-1);
			return;
		}
    	int a = in.nextInt();
    	int b = in.nextInt();
    	int c = in.nextInt();
    	int d = in.nextInt();
    	HashSet<Integer> h = new HashSet<>();
    	for (int i = 0; i < n; i++) {
			h.add(i + 1);
		}
    	h.remove(a);
    	h.remove(b);
    	h.remove(c);
    	h.remove(d);
    	System.out.print(a + " " + c + " ");
    	for (int i : h) {
			System.out.print(i + " ");
		}
    	System.out.println(d + " " + b);
    	System.out.print(c + " " + a + " ");
    	for (int i : h) {
    		System.out.print(i + " ");
    	}
    	System.out.println(b + " " + d);
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