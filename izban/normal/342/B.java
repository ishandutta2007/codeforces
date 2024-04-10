import java.awt.image.BufferedImage;
import java.io.*;
import java.util.*;
import java.util.concurrent.ExecutionException;


public class Main {


    public void Run() {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();
        int s = in.nextInt();
        int f = in.nextInt();
        ArrayList<Integer> l = new ArrayList<Integer>(), r = new ArrayList<Integer>(), t = new ArrayList<Integer>();
        for (int i = 0; i < m; i++) {
            int T = in.nextInt(), L = in.nextInt(), R = in.nextInt();
            t.add(T);
            l.add(L);
            r.add(R);
        }
        int cur = s, j = 0;
        ArrayList<Character> ans = new ArrayList<Character>();
        for (int i = 1; i < 1000000; i++) {
            int ncur = cur + (f - s) / Math.abs(f - s);
            if (cur == f) break;
            if (j < m && i == t.get(j)) {
                if (l.get(j) <= cur && r.get(j) >= cur || l.get(j) <= ncur && r.get(j) >= ncur ) {
                    j++;
                    ans.add('X');
                    continue;
                }
                j++;
            }
            if (s < f) ans.add('R');
            else ans.add('L');
            cur = ncur;
        }
        for (int i = 0; i < ans.size(); i++) System.out.print(ans.get(i));
        System.out.println();
    }

    public static void main(String[] args) {
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

}