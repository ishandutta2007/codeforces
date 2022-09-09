import java.io.InputStreamReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Reader in = new Reader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		solver.solve(1, in, out);
		out.close();
	}
}

class A {
	public void solve(int testNumber, Reader in, PrintWriter out) {
        int n = in.nextInt(), m = in.nextInt(), x = in.nextInt(), y = in.nextInt();
        if (y > m)
            y = m;
        String s[] = new String[n];
        for (int i=0; i<n; ++i)
            s[i] = in.nextString();
        int now[] = new int[m];
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j){
                if (s[i].charAt(j) == '.')
                    now[j]++;
            }
        /*for (int i=0; i<m; ++i)
            out.print(now[i] + " ");
        out.println();*/
        int dp[][][] = new int[m][2][m + 1];
        for (int i=0; i<m; ++i)
            for (int w = 0; w < 2; ++w)
                for (int j=0; j<=m; ++j)
                    dp[i][w][j] = 1000000000;
        dp[0][0][1] = n - now[0];
        dp[0][1][1] = now[0];
        //out.println(dp[0][0][1] + " " + dp[0][1][1]);
        for (int i = 0; i < m - 1; ++i)
            for (int w = 0; w < 2; ++w)
                for (int last = 1; last <= y; ++last){
                    //out.println(i + " " + w + " " + last + "  " + dp[i][w][last]);
                    if (last < y)
                        dp[i + 1][w][last + 1] = Math.min(dp[i + 1][w][last + 1], dp[i][w][last] + ((w==0)?(n - now[i + 1]):now[i + 1]));
                    if (last >= x){
                        //out.println(i + " " + w + " " + last + " " + dp[i][w][last]);
                        dp[i + 1][(w==0)?1:0][1] = Math.min(dp[i + 1][(w==0)?1:0][1], dp[i][w][last] + ((w==0)?now[i + 1]:(n - now[i + 1])));
                        //out.println(dp[i + 1][(w==0)?1:0][1]);
                        //out.println(i + 1 + " " + w + " " + last + " " + dp[i][w][last]);
                    }
            }
        int ans = 1000000000;
        for (int w = 0; w < 2; ++w)
            for (int i = x; i <= y; ++i)
                ans = Math.min(ans, dp[m-1][w][i]);
        out.print(ans);
	}
}

class Reader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Reader(BufferedReader reader) {
        this.reader = reader;
    }

    public Reader(InputStream stream) {
        this(new BufferedReader(new InputStreamReader(stream)));
    }

    public String nextString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}