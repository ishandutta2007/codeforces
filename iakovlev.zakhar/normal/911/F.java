import java.io.*;
import java.util.*;
 
public class F1 {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    
    public static class Pair {
		int x;
		int y;
		int z;
		public Pair(int x, int y, int z) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
		
	}
 
    public boolean dfsGo(int v, int la) {
		lena[v] = la;
		used[v] = true;
		boolean bool = false;
		for (int i : to[v]) {
			if (!used[i]) {
				bool |= dfsGo(i, la + 1);
			}
		}
		if (v == b) {
			bool = true;
		}
		if (bool) {
			ab[v] = true;
			ba.add(v);
		}
		return bool;
	}
    
    public void dfs(int v, int lb) {
		used[v] = true;
		for (int i : to[v]) {
			if (!used[i]) {
				dfs(i, lb + 1);
			}
		}
		if (!ab[v]) {
			if (lena[v] > lb) {
				ans[th] = new Pair(a, v, v);
				sum += lena[v];
			} else {
				ans[th] = new Pair(b, v, v);
				sum += lb;
			}
			th++;
		}
	}
    
    ArrayList<Integer>[] to;
    int a = 0;
    int b = 0;
    boolean[] used;
    boolean[] ab;
    int[] lena;
    ArrayList<Integer> ba = new ArrayList();
    long sum = 0;
    int th = 0;
    Pair[] ans;
    
    public void solve() throws IOException {
    	int n = in.nextInt();
    	to = new ArrayList[n];
    	ans = new Pair[n - 1];
    	for (int i = 0; i < to.length; i++) {
			to[i] = new ArrayList();
		}
    	for (int i = 0; i < n - 1; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			to[x].add(y);
			to[y].add(x);
		}
    	int[] d = new int[n];
    	used = new boolean[n];
    	Queue<Integer> q = new ArrayDeque();
    	q.add(0);
    	used[0] = true;
    	while (!q.isEmpty()) {
    		int x = q.poll();
			for (int i : to[x]) {
				if (!used[i]) {
					d[i] = d[x] + 1;
					q.add(i);
					used[i] = true;
				}
			}
		}
    	int len = 0;
    	for (int i = 0; i < used.length; i++) {
			if (d[i] > len) {
				len = d[i];
				a = i;
			}
		}
    	for (int i = 0; i < d.length; i++) {
			d[i] = 0;
			used[i] = false;
		}
    	q.add(a);
    	used[a] = true;
    	while (!q.isEmpty()) {
    		int x = q.poll();
			for (int i : to[x]) {
				if (!used[i]) {
					d[i] = d[x] + 1;
					q.add(i);
					used[i] = true;
				}
			}
		}
    	len = 0;
    	for (int i = 0; i < used.length; i++) {
			if (d[i] > len) {
				len = d[i];
				b = i;
			}
		}
    	used = new boolean[n];
    	ab = new boolean[n];
    	lena = new int[n];
    	dfsGo(a, 0);
    	used = new boolean[n];
    	dfs(b, 0);
    	for (int i = 0; i < ba.size() - 1; i++) {
			ans[th] = new Pair(a, ba.get(i), ba.get(i));
			sum += lena[ba.get(i)];
			th++;
		}
    	out.println(sum);
    	for (Pair p : ans) {
			out.println((p.x + 1) + " " + (p.y + 1) + " " + (p.z + 1));
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
        new F1().run();
    }
}