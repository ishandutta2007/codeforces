import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s = in.nextToken();
        int[] a = new int[26];
        for (int i = 0; i < s.length(); ++i)
            a[s.charAt(i) - 'a'] += 1;
        s = in.nextToken();
        int[] b = new int[26];
        for (int i = 0; i < s.length(); ++i)
            b[s.charAt(i) - 'a'] += 1;

        int ma = 0, mb = 25;
        int Ma = 25, Mb = 0;
        int n = s.length();

        int cnt1 = (n + 1) / 2;
        int cnt2 = n / 2;
        for (int i = 0; i < n - cnt1; ++i) {
            while (Ma >= 0 && a[Ma] == 0) --Ma;
            --a[Ma];
        }
        for (int i = 0; i < n - cnt2; ++i) {
            while (Mb < 26 && b[Mb] == 0) ++Mb;
            --b[Mb];
        }

        char[] res = new char[n];
        Arrays.fill(res, '?');
        int l = 0, r = n - 1;
        for (int cur = 0; cur < n; ++cur) {
            while (ma < 26 && a[ma] == 0) ++ma;
            while (mb >= 0 && b[mb] == 0) --mb;
            while (Mb < 26 && b[Mb] == 0) ++Mb;
            while (Ma >= 0 && a[Ma] == 0) --Ma;
if (ma < mb) {
                if (cur % 2 == 0) {
                    res[l++] = (char)('a' + ma);
                    --a[ma];
                } else {
                    res[l++] = (char)('a' + mb);
                    --b[mb];
                }
            } else {
                if (cur % 2 == 0) {
                    res[r--] = (char) ('a' + Ma);
                    --a[Ma];
                } else {
                    res[r--] = (char) ('a' + Mb);
                    --b[Mb];
                }
            }
        }
        for (int x : a) if (x != 0) throw new RuntimeException();
        for (int x : b) if (x != 0) throw new RuntimeException();
        for (char c : res) if (c == '?') throw new RuntimeException();
        out.printLine(new String(res));
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

    public String nextToken() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (!isSpace(c)) {
            sb.append((char) c);
            c = read();
        }
        return sb.toString();
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