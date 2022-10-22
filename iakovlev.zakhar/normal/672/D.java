import java.util.*;
import java.io.*;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    

    public void solve() {
    	int n = in.nextInt();
    	int k = in.nextInt();
    	int[] a = new int[n];
    	long sum = 0;
    	int x = 0;
    	for (int i = 0; i < n; i++) {
    		x = in.nextInt();
			a[i] = x;
			sum += x;
			
		}
    	Arrays.sort(a);
    	long l = 0;
    	long r = a[n - 1];
    	long m = 0;
    	while (l + 1 < r) {
    		m = (int) ((l + r) / 2);
			int i = n - 1;
			long f = 0;
			while (i >= 0 && a[i] > m) {
				f += a[i] - m;
				i--;
			}
			if (f > k) {
				l = m;
			} else {
				r = m;
			}
		}
    	int minus = (int) r;
    	l = a[0];
    	r = Integer.MAX_VALUE * 2L;
    	while (l + 1 < r) {
			m = (l + r) / 2;
			int i = 0;
			long f = 0;
			while (i < n && a[i] < m) {
				f += m - a[i];
				i++;
			}
			if (f > k) {
				r = m;
			} else {
				l = m;
			}
		}
    	int plus = (int) l;
    	if (plus >= minus) {
			if (sum % n == 0) {
				System.out.println(0);
			} else {
				System.out.println(1);
			}
		} else {
			System.out.println(minus - plus);
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