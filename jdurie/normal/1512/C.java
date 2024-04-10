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
        // 01????00
        // 011??110 
        int a = sc.nextInt(), b = sc.nextInt(), n = a+b;
        char[] A = sc.nextLine().toCharArray();

        for (int i = 0; i < n/2; i++) {
            int j = n-i-1;
            if (A[i] != '?' && A[j] == '?') {
                A[j] = A[i];
                if (A[i] == '0') {
                    a-=2;
                } else {
                    b-=2;
                }
            } else if (A[i] == '?' && A[j] != '?') {
                A[i] = A[j];
                if (A[i] == '0') {
                    a-=2;
                } else {
                    b-=2;
                }
            } else if (A[i] != '?' && A[j] != '?' && A[i] != A[j]) {
                out.println(-1);
                return;
            } else if (A[i] == A[j] && A[i] != '?') {
                if (A[i] == '0') {
                    a-=2;
                } else {
                    b-=2;
                }
            }
        }

        if (n % 2 != 0 && A[n/2] != '?') {
            if (A[n/2] == '0') {
                a--;
            } else {
                b--;
            }
        }

        for (int i = 0; i < n/2; i++) {
            int j = n-i-1;
            if (A[i] != '?') continue;
            if (a > b) {
                a-=2;
                A[i] = '0';
                A[j] = '0';
            } else {
                b-=2;
                A[i] = '1';
                A[j] = '1';
            }
        }

        if (n % 2 != 0 && A[n/2] == '?') {
            if (a > b) {
                a--;
                A[n/2] = '0';
            } else {
                b--;
                A[n/2] = '1';
            }
        }

        if (a != 0 || b != 0) {
            out.println(-1);
        } else {
            out.println(new String(A));
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