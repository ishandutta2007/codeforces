import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author jtnydv25
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
        static boolean is_pal(int hh, int mm) {
            return (((hh / 10) % 10 == (mm % 10)) && ((hh % 10) == (mm / 10) % 10));
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            String s = in.next();
            int hh = Integer.parseInt(s.substring(0, 2));
            int mm = Integer.parseInt(s.substring(3, 5));
            int ans = 0;
            while (!is_pal(hh, mm)) {
                mm++;
                if (mm == 60) {
                    hh++;
                    mm = 0;
                    if (hh == 24) hh = 0;
                }
                ans++;
            }
            out.print(ans);
        }

    }
}