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
    	long t = in.nextLong();
    	long[] a = new long[n];
    	for (int i = 0; i < a.length; i++) {
			a[i] = in.nextLong() + t;
		}
    	long[] min = new long[n];
    	long[] max = new long[n];
    	for (int i = 0; i < max.length; i++) {
			min[i] = a[i];
			max[i] = Long.MAX_VALUE / 2;
		}
    	int[] x = new int[n];
    	for (int i = 0; i < x.length; i++) {
			x[i] = in.nextInt() - 1;
		}
    	TreeSet<Integer> set = new TreeSet<>();
    	for (int i = 0; i < x.length; i++) {
			set.add(i);
		}
    	for (int i = 0; i < x.length; i++) {
    		Integer j = set.higher(i - 1);
    		while (j != null && j < x[i]) {
				set.remove(j);
				j = set.higher(j);
			}
			if (x[i] > i) {
				if (x[i] < n - 1) {
					max[x[i]] = Math.min(max[x[i]], a[x[i] + 1] - 1);
				}
//				if (x[i] > 0) {
//					min[x[i] - 1] = Math.max(min[x[i] - 1], a[x[i]]);
//				}
			} else if (x[i] == i) {
				if (x[i] < n - 1) {
					max[x[i]] = Math.min(max[x[i]], a[x[i] + 1] - 1);
				}
			} else {
//				min[x[i]] = Math.min(min[x[i]], a[x[i]]);
				out.println("No");
				return;
			}
		}
    	long[] ans = new long[n];
    	for (int i = 0; i < min.length; i++) {
    		if (!set.contains(i)) {
    			min[i] = Math.max(min[i], a[i + 1]);
    		}
//			System.out.println(min[i] + " " + max[i]);
		}
    	for (int i = 0; i < ans.length; i++) {
			if (min[i] > max[i]) {
				out.println("No");
				return;
			}
			ans[i] = min[i];
			if (i < n - 1) {
				min[i + 1] = Math.max(min[i + 1], ans[i] + 1);
			}
		}
    	out.println("Yes");
    	for (int i = 0; i < ans.length; i++) {
			out.print(ans[i] + " ");
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