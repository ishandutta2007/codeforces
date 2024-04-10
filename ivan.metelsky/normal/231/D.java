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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int x = in.nextInt(), y = in.nextInt(), z = in.nextInt();
        int x1 = in.nextInt(), y1 = in.nextInt(), z1 = in.nextInt();
        int[] a = new int[6];
        for (int i=0; i<6; i++) a[i] = in.nextInt();
        int res = 0;
        if (y<0) res += a[0];
        if (y>y1) res += a[1];
        if (z<0) res += a[2];
        if (z>z1) res += a[3];
        if (x<0) res += a[4];
        if (x>x1) res += a[5];
        out.println(res);
    }
}