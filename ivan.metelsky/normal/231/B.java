import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.util.Arrays;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int d = in.nextInt();
        int max = in.nextInt();

        int plus = 0, minus = 0;
        for (int i=0; i<n; i++)
            if (i%2==0) plus++; else minus++;

        int[] res = new int[n];
        for (int plusSum = plus; plusSum <= max * plus; plusSum++) {
            // plusSum - minusSum = d
            int minusSum = plusSum - d;
            if (minusSum < minus || minusSum > max * minus) {
                continue;
            }
            Arrays.fill(res, 1);
            plusSum -= plus;
            minusSum -= minus;
            for (int i=0; i<n; i+=2)
                while (res[i] < max && plusSum > 0) {
                    res[i]++;
                    plusSum--;
                }
            for (int i=1; i<n; i+=2)
                while (res[i] < max && minusSum > 0) {
                    res[i]++;
                    minusSum--;
                }
            for (int i=0; i<n; i++) {
                out.print(res[i]+ " ");
            }
            out.println();
            return;
        }
        out.println(-1);
    }
}