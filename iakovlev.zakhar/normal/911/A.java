import java.io.*;
import java.util.*;
 
public class A {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() throws IOException {
    	int n = in.nextInt();
    	int[] a = new int[n];
    	for (int i = 0; i < a.length; i++) {
			a[i] = in.nextInt();
		}
    	int min = Integer.MAX_VALUE;
    	int x = Integer.MIN_VALUE / 2;
    	int ans = Integer.MAX_VALUE;
    	for (int i = 0; i < a.length; i++) {
			min = Math.min(a[i], min);
		}
    	for (int i = 0; i < a.length; i++) {
			if (a[i] == min) {
				ans = Math.min(ans, i - x);
				x = i;
			}
		}
    	out.println(ans);
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
        new A().run();
    }
}