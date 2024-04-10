
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Queue;

public class Main {
    final int maxn = 1 << 11;
    Scanner in;
    PrintWriter out;

    String a[] = new String[8];
    int sum;
    boolean vis[][] = new boolean[8][8];
    int dist[][] = new int[8][8];
    int l = 0, r = 0;
    int X[] = new int[64], Y[] = new int[64];

    void go(int i, int j, int d) {
        if (i < 0 || j < 0 || i >= 8 || j >= 8) return;
        if (dist[i][j] > d) {
            dist[i][j] = d;
            r++;
            X[r] = i;
            Y[r] = j;
        }
    }

    public void Run() throws IOException {
        if (new File("input.txt").exists()) {
            in = new Scanner(new FileInputStream(new File("input.txt")));
            out = new PrintWriter(new FileOutputStream(new File("output.txt")));
        } else {
            in = new Scanner(System.in);
            out = new PrintWriter(System.out);
        }

        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            for (int i = 0; i < 8; i++) a[i] = in.nextToken();

            int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (a[i].charAt(j) == 'K') {
                        if (x1 == -1 && y1 == -1) {
                            x1 = i;
                            y1 = j;
                        } else {
                            x2 = i;
                            y2 = j;
                        }
                    }
                }
            }

            if ((x1 + y1) % 4 != (x2 + y2) % 4) {
                out.println("NO");
                continue;
            }

            for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) dist[i][j] = 1001;

            X[0] = x1;
            Y[0] = y1;
            dist[x1][y1] = 0;

            l = 0;
            r = 0;
            while (l <= r) {
                int cx = X[l], cy = Y[l];
                l++;

                go(cx + 2, cy + 2, dist[cx][cy] + 1);
                go(cx + 2, cy - 2, dist[cx][cy] + 1);
                go(cx - 2, cy + 2, dist[cx][cy] + 1);
                go(cx - 2, cy - 2, dist[cx][cy] + 1);
            }

            if (dist[x2][y2] % 2 == 0) {
                out.println("YES");
            } else out.println("NO");

        }

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