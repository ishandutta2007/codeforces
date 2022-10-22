import java.util.*;
import java.io.*;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    

    public void solve() {
    	int n = in.nextInt();
		int x = in.nextInt();
		int y = in.nextInt();
		int v = 1;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int x1 = in.nextInt();
			int y1 = in.nextInt();
			if (x1 > x) {
				x = x1;
				if (v == -1) {
					ans++;
				}
				v = 2;
			} else if (x1 < x) {
				x = x1;
				if (v == 1) {
					ans++;
				}
				v = -2;
			} else if (y1 > y) {
				y = y1;
				if (v == 2) {
					ans++;
				}
				v = 1;
			} else {
				y = y1;
				if (v == -2) {
					ans++;
				}
				v = -1;
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
        new D().run();
    }
}