import java.io.*;
import java.util.*;
 
public class A {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    
    public TreeSet<Integer> dfs(int v) {
		TreeSet<Integer> ans = new TreeSet<>();
		ans.add(0);
		for (int i : to[v]) {
			TreeSet<Integer> set = dfs(i);
			if (set.size() > ans.size()) {
				int min = set.first() - 1 - ans.first();
				for (int j : ans) {
					if (set.contains(j + min)) {
						set.remove(j + min);
					} else {
						set.add(j + min);
					}
				}
				ans = set;
			} else {
				int min = ans.first() + 1 - set.first();
				for (int j : set) {
					if (ans.contains(j + min)) {
						ans.remove(j + min);
					} else {
						ans.add(j + min);
					}
				}
			}
		}
		return ans;
	}
 
    ArrayList<Integer>[] to;
    
    public void solve() throws IOException {
    	int n = in.nextInt();
    	to = new ArrayList[n];
    	for (int i = 0; i < to.length; i++) {
			to[i] = new ArrayList<>();
		}
    	for (int i = 1; i < to.length; i++) {
			to[in.nextInt() - 1].add(i);
		}
    	out.print(dfs(0).size());
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