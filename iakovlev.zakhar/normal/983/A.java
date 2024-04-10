import java.io.*;
import java.util.*;
 
public class A {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    
    public long gcd(long a, long b) {
		if (a == 0) {
			return b;
		}
		if (b == 0) {
			return a;
		}
		a %= b;
		return gcd(b, a);
	}
    
    public void solve() throws IOException {
    	int n = in.nextInt();
    	for (int i = 0; i < n; i++) {
			long p = in.nextLong();
			long q = in.nextLong();
			long b = in.nextLong();
			long g1 = gcd(p, q);
			q /= g1;
			long x = gcd(q, b);
			while (x != 1) {
				q /= x;
				x = gcd(q, x);
			}
			if (q == 1) {
				out.println("Finite");
			} else {
				out.println("Infinite");
			}
		}
    }
 
    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("input.txt"));
                out = new PrintWriter(new File("output.txt"));
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
        new A().run();
    }
}