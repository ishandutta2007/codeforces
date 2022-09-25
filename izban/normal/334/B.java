import java.math.*;
import java.util.*;
import java.io.*;


public class Main {
    final int maxn = 1 << 17;
    int n;
    int x[] = new int[8], y[] = new int[8];


    public void Run() {
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < 8; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        boolean ok = true;
        for (int i = 0; i < 8; i++) {
            for (int j = i + 1; j < 8; j++) {
                if (x[i] == x[j] && y[i] == y[j]) ok = false;
            }
        }
        Arrays.sort(x);
        Arrays.sort(y);
        if (!(x[0] == x[1] && x[1] == x[2] && x[2] != x[3] && x[3] == x[4] && x[4] != x[5] && x[5] == x[6] && x[6] == x[7])) ok = false;
        if (!(y[0] == y[1] && y[1] == y[2] && y[2] != y[3] && y[3] == y[4] && y[4] != y[5] && y[5] == y[6] && y[6] == y[7])) ok = false;
        if (ok) System.out.println("respectable");
        else System.out.println("ugly");

    }

    public static void main(String[] args) {
        new Main().Run();
    }
}