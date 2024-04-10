import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        // Start writing your solution here. -------------------------------------
        int t = sc.nextInt();
        while  (t-- > 0) {
            solve(sc);
        }
        /*
         * int n = sc.nextInt(); // read input as integer long k = sc.nextLong(); //
         * read input as long double d = sc.nextDouble(); // read input as double String
         * str = sc.next(); // read input as String String s = sc.nextLine(); // read
         * whole line as String
         * 
         * int result = 3*n; out.println(result); // print via PrintWriter
         */

        // Stop writing your solution here. -------------------------------------
        out.close();
    }

    public static void solve(MyScanner sc) {
        int n = sc.nextInt();
        char[][] A = new char[n][n];

        for (int i = 0; i < n; i++) {
            A[i] = sc.nextLine().toCharArray();
        }

        int x1 = -1, y1 = -1, x2 = -1, y2 = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == '*') {
                    if (x1 == -1) {
                        x1 = i;
                        y1 = j;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
                } 
            }
        }

        int topx = Math.min(x1, x2), bottomx = Math.max(x1, x2);
        int lefty = Math.min(y1, y2), righty = Math.max(y1, y2);

        if (topx == bottomx) {
            bottomx = (bottomx + 1) % n;
        }

        if (lefty == righty) {
            righty = (righty + 1) % n;
        }

        A[topx][lefty] = '*';
        A[topx][righty] = '*';
        A[bottomx][lefty] = '*';
        A[bottomx][righty] = '*';

        for (int i = 0; i < A.length; i++) {
            out.println(new String(A[i]));
        }

    }

    // -----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;

    // -----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
    // --------------------------------------------------------
}