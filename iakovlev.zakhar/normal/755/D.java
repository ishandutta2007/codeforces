import java.util.*;
import java.io.*;
import java.math.BigInteger;
import java.nio.file.WatchEvent.Kind;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    
    
    public void solve() {
    	int n = in.nextInt();
    	int k = in.nextInt();
    	if (k > n / 2) {
			k = n - k;
		}
    	int th = 1;
    	long ans = 1;
    	int v = 0;
    	for (int i = 0; i < n; i++) {
			v = v + k;
			ans += th;
			if (v > n) {
				v -= n;
				ans++;
				th += 2;
			}
			out.print(ans + " ");
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