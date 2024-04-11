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
        int n = in.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        int free[][] = new int[n][2];
        int x = in.nextInt();
        for (int i=0; i<n; ++i){
            a[i] = in.nextInt();
            b[i] = in.nextInt();
            int cnt = 0;
            for (int j = 1; j <= 6; ++j)
                if (j != a[i] && j!= b[i] && 7 - j != a[i] && 7 - j != b[i])
                    free[i][cnt++] = j;
        }
        int cur = free[0][0];
        if (cur == x){
            cur = free[0][1];
        }
        for (int j = 1; j < n; ++j){
            if (free[j][0] != cur && free[j][1] != cur){
                out.print("NO");
                return;
            }
            if (free[j][0] != cur)
                cur = free[j][0];
            else
                cur = free[j][1];
        }
        out.print("YES");
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