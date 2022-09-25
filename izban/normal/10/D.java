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
        int a[] = new int[n];
        for (int i = 0; i < n; i++) a[i] = in.nextInt();
        int m = in.nextInt();
        final int b[] = new int[m];
        for (int i = 0; i < m; i++) b[i] = in.nextInt();

        Integer p[] = new Integer[m];
        for (int i = 0; i < m; i++) p[i] = i;
        Comparator<Integer> cmp = new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (b[o1] != b[o2]) return b[o1] - b[o2];
                return Integer.compare(o1, o2);
            }
        };

        Arrays.sort(p, cmp);

        int d[][] = new int[n + 1][m];
        for (int i = 0; i < n; i++) {
            int d2[] = new int[m], d3[] = new int[m];
            for (int J = 0; J < m; J++) {
                int j = p[J];
                d2[j] = d[i][j];
                if (a[i] != b[j]) {
                    d3[j] = 0;
                    continue;
                }
                int best = 0;
                int start = 0;
                if (J > 0 && b[p[J]] == b[p[J - 1]]) {
                    start = p[J - 1] + 1;
                    best = d3[p[J - 1]] - 1;
                }
                for (int k = start; k < j; k++) best = Math.max(best, d2[k]);
                d3[j] = best + 1;
            }
            for (int j = 0; j < m; j++) {
                if (d3[j] > d[i][j]) {
                    d[i + 1][j] = d3[j];
                } else {
                    d[i + 1][j] = d[i][j];
                }
            }
        }

        int cr = 0;
        for (int i = 1; i < m; i++) {
            if (d[n][i] > d[n][cr]) {
                cr = i;
            }
        }

        ArrayList<Integer> ans = new ArrayList<Integer>();
        int i = n, j = cr;
        while (i >= 1) {
            if (d[i][j] == d[i - 1][j]) {
                i--;
            } else {
                boolean o = false;
                for (int nj = 0; nj < j; nj++) {
                    if (d[i - 1][nj] + 1 == d[i][j] && b[nj] < b[j]) {
                        ans.add(b[j]);
                        j = nj;
                        i--;
                        o = true;
                        break;
                    }
                }
                if (!o) {
                    ans.add(a[i - 1]);
                    break;
                }
            }
        }
        out.println(ans.size());
        for (int o = ans.size() - 1; o >= 0; o--) out.print(ans.get(o) + " ");
        out.println();

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