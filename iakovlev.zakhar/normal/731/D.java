import java.util.*;
import java.io.*;
import java.math.BigInteger;
import java.nio.file.WatchEvent.Kind;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    public static class Point implements Comparable<Point> {
		int x;
		int type;
		
		public Point(int x, int type) {
			this.x = x;
			this.type = type;
		}

		@Override
		public int compareTo(Point that) {
			// TODO Auto-generated method stub
			if (this.x != that.x) {
				return this.x - that.x;
			} else {
				return this.type - that.type;
			}
		}
	}
    
    public void solve() {
		int n = in.nextInt();
		int c = in.nextInt();
		ArrayList<Point> list = new ArrayList<>();
		int[][] a = new int[n][];
		for (int i = 0; i < a.length; i++) {
			a[i] = new int[in.nextInt()];
			for (int j = 0; j < a[i].length; j++) {
				a[i][j] = in.nextInt();
			}
		}
		for (int i = 0; i < a.length - 1; i++) {
			int j = 0;
			while (j < a[i].length && j < a[i + 1].length) {
				if (a[i][j] == a[i + 1][j]) {
					j++;
				} else {
					if (a[i][j] < a[i + 1][j]) {
						list.add(new Point(0, 0));
						list.add(new Point(c - a[i + 1][j], 1));
						if (a[i][j] > 1) {
							list.add(new Point(c + 1 - a[i][j], 0));
							list.add(new Point(c - 1, 1));
						}
					} else {
						list.add(new Point(c + 1 - a[i][j], 0));
						list.add(new Point(c - a[i + 1][j], 1));
					}
					break;
				}
			}
			if (j == a[i].length || j == a[i + 1].length) {
				if (a[i].length <= a[i + 1].length) {
					list.add(new Point(0, 0));
					list.add(new Point(c - 1, 1));
				} else {
					out.println(-1);
					return;
				}
			}
		}
		Collections.sort(list);
//		for (int i = 0; i < list.size(); i++) {
//			System.out.println(list.get(i).x + " " + list.get(i).type);
//		}
		int th = 0;
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i).type == 0) {
				th++;
			} else {
				th--;
			}
			if (th == n - 1) {
				out.println(list.get(i).x);
				return;
			}
		}
		out.print(-1);
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