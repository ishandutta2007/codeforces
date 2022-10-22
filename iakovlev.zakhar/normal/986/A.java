import java.io.*;
import java.util.*;
 
public class A {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
    
    public static void quickSort(int[] a, int from, int to) {
		if (to - from <= 1) {
			return;
		}
		int i = from;
		int j = to - 1;
		int x = a[from + (new Random()).nextInt(to - from)];
		while (i <= j) {
			while (a[i] < x) {
				i++;
			}
			while (a[j] > x) {
				j--;
			}
			if (i <= j) {
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
				i++;
				j--;
			}
		}
		quickSort(a, from, j + 1);
		quickSort(a, j + 1, to);
	}
    
    
    
    public void solve() {
    	int n = in.nextInt();
    	int m = in.nextInt();
    	int k = in.nextInt();
    	int s = in.nextInt();
    	ArrayList<Integer>[] cities = new ArrayList[k];
    	for (int i = 0; i < cities.length; i++) {
			cities[i] = new ArrayList<>();
		}
    	for (int i = 0; i < n; i++) {
			cities[in.nextInt() - 1].add(i);
		}
    	int[][] edge = new int[n][];
    	int[] x = new int[m];
    	int[] y = new int[m];
    	int[] size = new int[n];
    	for (int i = 0; i < m; i++) {
			x[i] = in.nextInt() - 1;
			y[i] = in.nextInt() - 1;
			size[x[i]]++;;
			size[y[i]]++;
		}
    	for (int i = 0; i < size.length; i++) {
			edge[i] = new int[size[i]];
		}
    	size = new int[n];
    	for (int i = 0; i < x.length; i++) {
			edge[x[i]][size[x[i]]] = y[i];
			edge[y[i]][size[y[i]]] = x[i];
			size[x[i]]++;
			size[y[i]]++;
		}
    	int[][] len = new int[n][k];
    	for (int i = 0; i < cities.length; i++) {
			boolean[] used = new boolean[n];
			int[] v = new int[n];
			int l = 0;
			int r = 0;
			for (int j : cities[i]) {
				used[j] = true;
				v[r] = j;
				r++;
				len[j][i] = 0;
			}
			while (l != r) {
				int z = v[l];
				l++;
				for (int j : edge[z]) {
					if (!used[j]) {
						used[j] = true;
						v[r] = j;
						r++;
						len[j][i] = len[z][i] + 1;
					}
				}
			}
		}
    	for (int i = 0; i < len.length; i++) {
			Arrays.sort(len[i]);
		}
    	for (int i = 0; i < len.length; i++) {
    		int sum = 0;
    		for (int j = 0; j < s; j++) {
				sum += len[i][j];
			}
			out.print(sum + " ");
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