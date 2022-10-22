import java.io.*;
import java.util.*;
 
public class A {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;
 
    public boolean equals(char c1, char c2) {
		if (c1 == c2) {
			return true;
		}
		if (Character.isLetter(c1) && Character.isLetter(c2)) {
			if (Character.toUpperCase(c1) == Character.toUpperCase(c2)) {
				return true;
			}
		}
		HashSet<Character> h = new HashSet<>();
		h.add('O');
		h.add('0');
		h.add('o');
		if (h.contains(c1) && h.contains(c2)) {
			return true;
		}
		h.clear();
		h.add('l');
		h.add('L');
		h.add('1');
		h.add('I');
		h.add('i');
		if (h.contains(c1) && h.contains(c2)) {
			return true;
		}
		return false;
	}
    
    public void solve() throws IOException {
    	String s = in.next();
    	int n = in.nextInt();
    	String[] a = new String[n];
    	for (int i = 0; i < a.length; i++) {
			a[i] = in.next();
		}
    	f :
    	for (int i = 0; i < a.length; i++) {
			if (s.length() != a[i].length()) {
				continue;
			}
			for (int j = 0; j < a[i].length(); j++) {
				char c1 = s.charAt(j);
				char c2 = a[i].charAt(j);
				if (!equals(c1, c2)) {
					continue f;
				}
			}
			out.println("No");
			return;
		}
    	out.println("Yes");
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