import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {

    int n;
    String a[] = new String[100];

    public void Run() {
        Scanner in = new Scanner(System.in);
        n = in.nextInt(); in.nextLine();
        for (int i = 0; i < n; i++) a[i] = in.nextLine();

        int row[] = new int[100], col[] = new int[100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i].charAt(j) == 'E') {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (row[i] == n && col[j] == n) {
            System.out.print(-1 + "\n");
            return;
        }

        Boolean f = false;
        for (int i = 0; i < n; i++) f |= row[i] == n;

        if (!f) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i].charAt(j) != 'E') {
                        System.out.print((i + 1) + " " + (j + 1) + "\n");
                        break;
                    }
                }
            }
        } else {
            for (int j = 0; j < n; j++) {
                for (int i = 0; i < n; i++) {
                    if (a[i].charAt(j) != 'E') {
                        System.out.print((i + 1) + " " + (j + 1) + "\n");
                        break;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}