
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

        int n = in.nextInt();
        short a[] = new short[n];
        for (int i = 0; i < n; i++) a[i] = (short)(in.nextInt());

        short cnt[][] = new short[n][n];
        short cnt2[][] = new short[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                cnt[i][j] = cnt[i][j - 1];
                if (a[j - 1] > i) cnt[i][j]++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = n - 2; j >= 0; j--) {
                cnt2[i][j] = cnt2[i][j + 1];
                if (a[j + 1] < i) cnt2[i][j]++;
            }
        }

        int o = 0;
        for (int i = 0; i < n; i++) o += cnt[a[i]][i];

        int ans = -1000000000;
        int cans = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                short res = 0;
                if (a[i] > a[j]) res = 1;
                else res = -1;

                res += cnt[a[j]][j] - cnt[a[j]][i+1];
                res += cnt[a[i]][i+1] - cnt[a[i]][j];

                res += cnt2[a[i]][i] - cnt2[a[i]][j-1];
                res += cnt2[a[j]][j-1] - cnt2[a[j]][i];
                //res += cnt2[a[i]][i] - cnt2[a[i]][j];
                //res -= cnt2[a[j]][i] - cnt2[a[i]][j];
                if (ans < res) {
                    ans = res;
                    cans = 0;
                }
                if (ans == res) cans++;
            }
        }
        out.println((o - ans) + " " + cans);

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