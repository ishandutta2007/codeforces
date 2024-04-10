import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.util.Random;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ilyakor
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    int[] a;
    long[] sum;
    int n;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        n = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }

        Random random = new Random();


        for (int i = 0; i < n; ++i) {
            int j = random.nextInt(n);
            if (i != j) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
        Arrays.sort(a);

        sum = new long[a.length + 1];
        for (int i = 0; i < a.length; ++i)
            sum[i + 1] = sum[i] + a[i];


        BigRational ans = new BigRational(Long.MIN_VALUE);
        int ai = -1, ak = -1;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l0 = i / 2, r0 = (i + 1) / 2;
            int num0 = l0 == r0 ? a[l0] : (a[l0] + a[r0]);
            int den0 = i % 2 == 0 ? 1 : 2;

            int down = 0, up = n + 2;
            while (up - down > 1) {
                int t = (up + down) / 2;
                int l1 = l0 - t;
                int l2 = n - t;
                if (l2 <= r0 || l1 < 0) {
                    up = t;
                    continue;
                }

                long num = getSum(l1, l0 - 1) + getSum(l2, n - 1);
                long den = 2 * t;
                num += num0;
                den += den0;

                long prevNum = getSum(l1 + 1, l0 - 1) + getSum(l2 + 1, n - 1);
                long prevDen = 2 * t - 2;
                prevNum += num0;
                prevDen += den0;

                if (BigInteger.valueOf(num).multiply(BigInteger.valueOf(prevDen)).subtract(BigInteger.valueOf(den).multiply(BigInteger.valueOf(prevNum))).compareTo(BigInteger.ZERO) >= 0) {
                    down = t;
                } else {
                    up = t;
                }
            }

            int l1 = l0 - down;
            int l2 = n - down;
            long num = getSum(l1, l0 - 1) + getSum(l2, n - 1);
            long den = 2 * down;
            num += num0;
            den += den0;

            BigRational cur = new BigRational(BigInteger.valueOf(num), BigInteger.valueOf(den));
            cur = cur.subtract(new BigRational(BigInteger.valueOf(num0), BigInteger.valueOf(den0)));
            if (cur.compareTo(ans) > 0) {
                ans = cur;
                ai = i;
                ak = down;
            }
        }

        int l0 = ai / 2, r0 = (ai + 1) / 2;
        int l1 = l0 - ak;
        int l2 = n - ak;
        int den0 = ai % 2 == 0 ? 1 : 2;
        den0 += 2 * ak;
        out.printLine(den0);
        for (int i = l1; i < l0; ++i)
            out.print(a[i] + " ");
        for (int i = l0; i <= r0; ++i)
            out.print(a[i] + " ");
        for (int i = l2; i < n; ++i)
            out.print(a[i] + " ");
        out.printLine();
    }

    long getSum(int l, int r) {
        if (l > r)
            return 0;
        return sum[r + 1] - sum[l];
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buffer = new byte[10000];
    private int cur;
    private int count;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public static boolean isSpace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public int read() {
        if (count == -1) {
            throw new InputMismatchException();
        }
        try {
            if (cur >= count) {
                cur = 0;
                count = stream.read(buffer);
                if (count <= 0)
                    return -1;
            }
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return buffer[cur++];
    }

    public int readSkipSpace() {
        int c;
        do {
            c = read();
        } while (isSpace(c));
        return c;
    }

    public int nextInt() {
        int sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10 + c - '0';
            c = read();
        } while (!isSpace(c));
        res *= sgn;
        return res;
    }

}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

class BigRational implements Comparable<BigRational> {
    BigInteger num, den;

    public BigRational(BigInteger num, BigInteger den) {
        this.num = num;
        this.den = den;
        if (den.compareTo(BigInteger.ZERO) < 0) {
            this.num = this.num.negate();
            this.den = this.den.negate();
        }
    }

    public BigRational(long x) {
        this.num = BigInteger.valueOf(x);
        this.den = BigInteger.ONE;
    }

    public int compareTo(BigRational other) {
        return num.multiply(other.den).subtract(den.multiply(other.num)).compareTo(BigInteger.ZERO);
    }

    public BigRational subtract(BigRational other) {
        return new BigRational(num.multiply(other.den).subtract(den.multiply(other.num)), den.multiply(other.den));
    }
}