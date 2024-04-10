import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author unknown
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = Integer.parseInt(in.next());
            for (int i = n; ; i++) {
                if (sumDiv(i)) {
                    out.println(i);
                    return;
                }
            }
        }

        public boolean sumDiv(int i) {
            int total = 0;
            while (i > 0) {
                total += i % 10;
                i /= 10;
            }
            return total % 4 == 0;
        }

    }
}