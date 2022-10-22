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
    	String s = in.next();
    	long ans = 0;
    	ArrayList<Long> pow = new ArrayList<>();
    	pow.add(1L);
    	while (pow.get(pow.size() - 1) <= Long.MAX_VALUE / n) {
			pow.add(pow.get(pow.size() - 1) * n);
		}
    	long th = 0;
    	int[] a = new int[s.length()];
    	for (int i = 0; i < s.length(); i++) {
			a[s.length() - 1 - i] = s.charAt(i) - '0';
		}
    	long ten = 1;
    	int p = 0;
    	boolean flag = false;
    	int used = -1;
    	for (int i = 0; i < a.length + 1; i++) {
    		if (i == a.length) {
				if (th != 0 && th < n) {
					ans += th * pow.get(p);
					break;
				} else if (th >= n) {
					flag = true;
					th %= (ten / 10);
					i -= 3;
				} else {
					break;
				}
			} else if (flag) {
				if (i == used) {
					i++;
					used = i;
					p++;
					flag = false;
					th = 0;
					ten = 1;
				} else if (a[i] == 0) {
					i-= 2;
				} else {
					flag = false;
					ans += pow.get(p) * th;
					p++;
					used = i;
					th = 0;
					ten = 1;
				}
			} else if (ten < 10000000000000000L && th < n) {
				th += ten * a[i];
				ten *= 10;
			} else if (ten == 10000000000000000L) {
				if (th >= n) {
					flag = true;
					th %= (ten / 10);
					i -= 3;
				} else {
					flag = true;
					i-= 2;
				}
			} else {
				flag = true;
				th %= (ten / 10);
				i -= 3;
			}
		}
    	System.out.println(ans);
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