import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Ivan Miatselski
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Dragons solver = new Dragons();
        solver.solve(1, in, out);
        out.close();
    }
}

class Dragons {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int s = in.nextInt();
        int n = in.nextInt();

        int[] x = new int[n];
        int[] y = new int[n];
        boolean[] won = new boolean[n];

        for (int i=0; i<n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (s>x[j] && !won[j]) {
                    won[j] = true;
                    s += y[j];
                    s = s - 1 + 1;
                }

        for (int j=0; j<n; j++)
            if (!won[j]) {
                out.println("NO");
                return;
            }

        out.println("YES");
    }
}