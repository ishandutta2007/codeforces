import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {

    int n;
    int x, y;

    String a[] = new String[100];

    public void Run() {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();

        if (n == 3) {
            a[0] = ">vv\n";
            a[1] = "^<.\n";
            a[2] = "^.<\n";
            x = 1;
            y = 3;
        }

        if (n == 5) {
            a[0] = ">...v\n";
            a[1] = "v.<..\n";
            a[2] = "..^..\n";
            a[3] = ">....\n";
            a[4] = "..^.<\n";
            x = 1;
            y = 1;
        }

        if (n == 100) {
            a[98] = "";
            for (int i = 0; i < 33; i++) a[98] += ">";
            for (int i = 0; i < 33; i++) a[98] += ".>";
            a[98] += "v\n";

            a[99] = "";
            a[99] += "^";
            for (int i = 0; i < 33; i++) a[99] += "<.";
            for (int i = 0; i < 33; i++) a[99] += "<";
            a[99] += "\n";

            for (int i = 97; i >= 0; i--) a[i] = a[i + 2];

            x = 99; y = 1;
        }

        for (int i = 0; i < n; i++) System.out.print(a[i]);
        System.out.println(x + " " + y);
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}