
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Queue;

public class Main {
    final int maxn = 1 << 11;
    Scanner in;
    PrintWriter out;

    public void Run() throws IOException {
        if (new File("input.txt").exists()) {
            in = new Scanner(new FileInputStream(new File("input.txt")));
            out = new PrintWriter(new FileOutputStream(new File("output.txt")));
        } else {
            in = new Scanner(System.in);
            out = new PrintWriter(System.out);
        }

        int n = in.nextInt(), m = in.nextInt();
        int a[] = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);

        boolean ok = true;
        if (m >= 1) {
            ok &= a[0] != 1;
            ok &= a[m - 1] != n;
        }
        int cur = 1;
        for (int i = 0; i < m; i++) {
            if (a[i] < cur) continue;
            if (a[i] > cur) cur = a[i] - 1;
            if (i + 1 >= m || a[i + 1] != a[i] + 1) {
                cur = a[i] + 1;
                continue;
            }
            if (i + 2 >= m || a[i + 2] != a[i] + 2) {
                cur = a[i] + 2;
                continue;
            }
            ok = false;
        }
        if (!ok) out.println("NO");
        else out.println("YES");

        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().Run();
    }
}

class Scanner {
    BufferedReader in;
    StringTokenizer tok;

    public Scanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }

    public String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }
}