import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.math.BigDecimal;
import java.io.InputStream;
import java.util.HashMap;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.math.MathContext;
import java.util.Set;

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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    static final int mod = 998244353;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; ++i) {
            long x = in.nextLong();
            a[i] = x;
        }
        HashMap<Long, Integer> powers = new HashMap<>();
        HashMap<Long, Integer> couples = new HashMap<>();
        ArrayList<Long> primes = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            long x = a[i];
            long t = p4(x);
            if (t != -1) {
                primes.add(t);
                primes.add(t);
                primes.add(t);
                primes.add(t);
                continue;
            }
            t = p3(x);
            if (t != -1) {
                primes.add(t);
                primes.add(t);
                primes.add(t);
                continue;
            }
            t = p2(x);
            if (t != -1) {
                primes.add(t);
                primes.add(t);
                continue;
            }


            long p = -1, q = -1;
            for (int j = 0; j < n; ++j) if (i != j) {
                long g = IntegerUtils.gcd(a[i], a[j]);
                if (g == a[i] || g == 1) continue;
                p = g;
                q = a[i] / p;
                break;
            }
            if (p != -1) {
                primes.add(p);
                primes.add(q);
                continue;
            }
            if (!couples.containsKey(x))
                couples.put(x, 1);
            else
                couples.put(x, couples.get(x) + 1);
        }
        for (long p : primes) {
            if (!powers.containsKey(p))
                powers.put(p, 1);
            else
                powers.put(p, powers.get(p) + 1);
        }
        long res = 1;
        for (long p : powers.keySet()) {
            res = (res * (1L + powers.get(p))) % mod;
        }
        for (long x : couples.keySet()) {
            int cnt = couples.get(x);
            res = (res * (1L + cnt)) % mod;
            res = (res * (1L + cnt)) % mod;
        }
        out.printLine(res);
    }

    private long p2(long x) {
        long l = 0, r = (long) Math.pow(3e18, 0.5);
        while (r - l > 1) {
            long t = (l + r) / 2;
            if (t * t <= x)
                l = t;
            else
                r = t;
        }
        if (l * l == x)
            return l;
        return -1;
    }

    private long p3(long x) {
        long l = 0, r = (long) Math.pow(3e18, 1. / 3.);
        while (r - l > 1) {
            long t = (l + r) / 2;
            if (t * t * t <= x)
                l = t;
            else
                r = t;
        }
        if (l * l * l == x)
            return l;
        return -1;
    }

    private long p4(long x) {
        long l = 0, r = (long) Math.pow(3e18, 1. / 4.);
        while (r - l > 1) {
            long t = (l + r) / 2;
            if (t * t * t * t <= x)
                l = t;
            else
                r = t;
        }
        if (l * l * l * l == x)
            return l;
        return -1;
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

    public long nextLong() {
        long sgn = 1;
        int c = readSkipSpace();
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res = res * 10L + (long)(c - '0');
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

class IntegerUtils {

    public static long gcd(long x, long y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }

}