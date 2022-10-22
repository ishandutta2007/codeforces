import java.util.*;
import java.io.*;
import java.math.BigInteger;
import java.nio.file.WatchEvent.Kind;

public class D {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    public static class Pair {
		int z;
		int number;
		
		public Pair(int z, int number) {
			this.number = number;
			this.z = z;
		}
	}
    
    public static class Cube {
		int x;
		int y;
		int z;

		public Cube(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}
    
    public static class Ans {
		int n1;
		int n2;
		
		public Ans(int n1, int n2) {
			this.n1 = n1;
			this.n2 = n2;
		}
	}
    
    public void solve() {
		int n = in.nextInt();
		HashMap<Integer, HashMap<Integer, Pair>> h = new HashMap<>();
		Cube[] a = new Cube[n];
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			int z = in.nextInt();
			int x1 = x;
			int y1 = y;
			int z1 = z;
			a[i] = new Cube(x, y, z);
			if (h.containsKey(x)) {
				HashMap<Integer, Pair> h1 = h.get(x);
				if (h1.containsKey(y)) {
					if (h1.get(y).z < z) {
						h1.put(y, new Pair(z, i));
					}
				} else {
					h1.put(y, new Pair(z, i));
				}
			} else {
				HashMap<Integer, Pair> h1 = new HashMap<>();
				h1.put(y, new Pair(z, i));
				h.put(x, h1);
			}
			x = y1;
			y = x1;
			if (h.containsKey(x)) {
				HashMap<Integer, Pair> h1 = h.get(x);
				if (h1.containsKey(y)) {
					if (h1.get(y).z < z) {
						h1.put(y, new Pair(z, i));
					}
				} else {
					h1.put(y, new Pair(z, i));
				}
			} else {
				HashMap<Integer, Pair> h1 = new HashMap<>();
				h1.put(y, new Pair(z, i));
				h.put(x, h1);
			}
			x = z1;
			y = y1;
			z = x1;
			if (h.containsKey(x)) {
				HashMap<Integer, Pair> h1 = h.get(x);
				if (h1.containsKey(y)) {
					if (h1.get(y).z < z) {
						h1.put(y, new Pair(z, i));
					}
				} else {
					h1.put(y, new Pair(z, i));
				}
			} else {
				HashMap<Integer, Pair> h1 = new HashMap<>();
				h1.put(y, new Pair(z, i));
				h.put(x, h1);
			}
			x = y1;
			y = z1;
			z = x1;
			if (h.containsKey(x)) {
				HashMap<Integer, Pair> h1 = h.get(x);
				if (h1.containsKey(y)) {
					if (h1.get(y).z < z) {
						h1.put(y, new Pair(z, i));
					}
				} else {
					h1.put(y, new Pair(z, i));
				}
			} else {
				HashMap<Integer, Pair> h1 = new HashMap<>();
				h1.put(y, new Pair(z, i));
				h.put(x, h1);
			}
			x = x1;
			y = z1;
			z = y1;
			if (h.containsKey(x)) {
				HashMap<Integer, Pair> h1 = h.get(x);
				if (h1.containsKey(y)) {
					if (h1.get(y).z < z) {
						h1.put(y, new Pair(z, i));
					}
				} else {
					h1.put(y, new Pair(z, i));
				}
			} else {
				HashMap<Integer, Pair> h1 = new HashMap<>();
				h1.put(y, new Pair(z, i));
				h.put(x, h1);
			}
			x = z1;
			y = x1;
			z = y1;
			if (h.containsKey(x)) {
				HashMap<Integer, Pair> h1 = h.get(x);
				if (h1.containsKey(y)) {
					if (h1.get(y).z < z) {
						h1.put(y, new Pair(z, i));
					}
				} else {
					h1.put(y, new Pair(z, i));
				}
			} else {
				HashMap<Integer, Pair> h1 = new HashMap<>();
				h1.put(y, new Pair(z, i));
				h.put(x, h1);
			}
		}
		int min = -1;
		int one = 0;
		for (int j = 0; j < a.length; j++) {
			int d = Math.min(a[j].x, Math.min(a[j].y, a[j].z));
			if (d > min) {
				one = j + 1;
				min = d;
			}
		}
		Ans ans = null;
		for (int i = 0; i < a.length; i++) {
			int x = a[i].x;
			int y = a[i].y;
			int z = a[i].z;
			int x1 = x;
			int y1 = y;
			int z1 = z;
			Pair p = (h.get(x).get(y));
			if (p.number != i) {
				int z2 = p.z + z;
				int d = Math.min(x, Math.min(y, z2));
				if (d > min) {
					min = d;
					ans = new Ans(p.number + 1, i + 1);
				}
			}
			x = x1;
			y = z1;
			z = y1;
			p = (h.get(x).get(y));
			if (p.number != i) {
				int z2 = p.z + z;
				int d = Math.min(x, Math.min(y, z2));
				if (d > min) {
					min = d;
					ans = new Ans(p.number + 1, i + 1);
				}
			}
			x = y1;
			y = z1;
			z = x1;
			p = (h.get(x).get(y));
			if (p.number != i) {
				int z2 = p.z + z;
				int d = Math.min(x, Math.min(y, z2));
				if (d > min) {
					min = d;
					ans = new Ans(p.number + 1, i + 1);
				}
			}
		}
		if (ans != null) {
			out.println(2);
			out.print(ans.n1 + " " + ans.n2);
		} else {
			out.println(1);
			out.println(one);
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