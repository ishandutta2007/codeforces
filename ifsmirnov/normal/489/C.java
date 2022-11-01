import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
	    init();

        int n = nextInt();
        int s = nextInt();

        if (s == 0) {
            if (n == 1) {
                out.println("0 0");
            } else {
                out.println("-1 -1");
            }
            out.flush();
            return;
        }
        if (n * 9 < s) {
            out.println("-1 -1");
            out.flush();
            return;
        }

        int S = s;
        for (int i = 0; i < n; ++i) {
            int min = i == 0 ? 1 : 0;
            min = Math.max(min,s - (n - i - 1) * 9);
            out.print(min);
            s -= min;
        }
        out.print(" ");

        s = S;
        for (int i = 0; i < n; ++i) {
            if (s >= 9) {
                out.print(9);
                s -= 9;
            } else {
                out.print(s);
                s = 0;
            }
        }
        out.println();


        br.close();
        out.close();
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void init() throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
    }

    static boolean hasNext() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return false;
            }
            st = new StringTokenizer(line);
        }
        return true;
    }

    static String next() throws IOException {
        return hasNext() ? st.nextToken() : null;
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}