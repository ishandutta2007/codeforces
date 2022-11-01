import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            int n = s.length();
            long w = 0, wo = 0, wow = 0;
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == 'o') {
                    wo += w;
                } else if (i > 0 && s.charAt(i - 1) == 'v') {
                    w++;
                    wow += wo;
                }
            }
            out.println(wow);
        /*int[] right = new int[n + 1];
        int[] left = new int[n + 1];
        int last = 0;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s.charAt(j) == 'v') j++;
            if (j < n && s.charAt(j) == 'o') {
                if (i == j) {
                    right[j] = last;
                } else {
                    right[j] = last + j - i - 1;
                    last = right[j];
                }
            }
            i = j + 1;
        }
        last = 0;
        for (int i = n - 1; i >= 0;) {
            int j = i;
            while (j >= 0 && s.charAt(j) == 'v') j--;
            if (j >= 0 && s.charAt(j) == 'o') {
                if (i == j) {
                    left[j] = last;
                } else {
                    left[j] = last + i - j - 1;
                    last = left[j];
                }
            }
            i = j - 1;
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'o') {
                ans += (long) left[i] * (long) right[i];
            }
        }
        System.out.println(ans);*/
        }

    }

    static class InputReader {
        private InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0;
        private int ptrbuf = 0;

        public InputReader(InputStream is) {
            this.is = is;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }

        public String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

    }
}