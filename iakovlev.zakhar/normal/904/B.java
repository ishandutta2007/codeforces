import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
 
public class B {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public void solve() {
    	boolean[][] field = new boolean[9][9];
    	char[][] ans = new char[9][9];
    	for (int x = 0; x < 9; x++) {
			for (int i = 0; i < 3; i++) {
				String s = in.next();
				for (int y = 0; y < 3; y++) {
					ans[x][3 * i + y] = s.charAt(y);
					if (s.charAt(y) != '.') {
						field[x][3 * i + y] = true;
					}
				}
			}
		}
    	int x = (in.nextInt() - 1) % 3;
    	int y = (in.nextInt() - 1) % 3;
    	boolean flag = false;
    	for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!field[3 * x + i][3 * y + j]) {
					flag = true;
				}
			}
		}
    	if (flag) {
    		for (int i = 0; i < 3; i++) {
    			for (int j = 0; j < 3; j++) {
    				if (!field[3 * x + i][3 * y + j]) {
    					ans[3 * x + i][3 * y + j] = '!';
    				}
    			}
    		}
		} else {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans.length; j++) {
					if (!field[i][j]) {
						ans[i][j] = '!';
					}
				}
			}
		}
    	for (int i = 0; i < ans.length; i++) {
    		if (i % 3 == 0 & i > 0) {
    			out.println();
    		}
			for (int j = 0; j < ans.length; j++) {
				if (j % 3 == 0 && j > 0) {
					out.print(" ");
				}
				out.print(ans[i][j]);
			}
			out.println();
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
 
    // AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    public static void main(String[] arg) {
        new B().run();
    }
}