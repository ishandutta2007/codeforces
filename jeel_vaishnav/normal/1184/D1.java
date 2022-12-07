import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jeel Vaishnav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        D1ParallelUniversesEasy solver = new D1ParallelUniversesEasy();
        solver.solve(1, in, out);
        out.close();
    }

    static class D1ParallelUniversesEasy {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            int n = sc.nextInt();
            int k = sc.nextInt() - 1;
            int m = sc.nextInt();
            int t = sc.nextInt();

            ArrayList<Integer> arr = new ArrayList<>();
            for (int i = 0; i < n; ++i) {
                if (i == k)
                    arr.add(1);
                else
                    arr.add(0);
            }

            for (int i = 0; i < t; ++i) {
                int type = sc.nextInt();
                int idx = sc.nextInt() - 1;

                if (type == 1) {
                    ArrayList<Integer> newArr = new ArrayList<>();
                    for (int j = 0; j < idx; ++j) {
                        newArr.add(arr.get(j));
                    }
                    newArr.add(0);
                    for (int j = idx; j < arr.size(); ++j)
                        newArr.add(arr.get(j));
                    arr = newArr;
                } else {
                    ArrayList<Integer> newArr = new ArrayList<>();
                    int flag = 0;
                    for (int j = 0; j <= idx; ++j) {
                        newArr.add(arr.get(j));
                        if (arr.get(j) == 1)
                            flag = 1;
                    }

                    if (flag == 0) {
                        newArr = new ArrayList<>();
                        for (int j = idx + 1; j < arr.size(); ++j)
                            newArr.add(arr.get(j));
                    }

                    arr = newArr;
                }

                int ans = 0;
                for (int j = 0; j < arr.size(); ++j) {
                    if (arr.get(j) == 1)
                        ans = j + 1;
                }

                out.println(arr.size() + " " + ans);
            }
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();

            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }

                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();

            while (isSpaceChar(c))
                c = read();

            int sgn = 1;

            if (c == '-') {
                sgn = -1;
                c = read();
            }

            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            while (!isSpaceChar(c));

            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }
}