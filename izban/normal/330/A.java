import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {

    public static void main(String[] args) {
        String a[] = new String[10];
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        in.nextLine();
        for (int i = 0; i < n; i++)
            a[i] = in.nextLine();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Boolean f1 = false, f2 = false;
                for (int k = 0; k < n; k++) f1 |= a[k].charAt(j) == 'S';
                for (int k = 0; k < m; k++) f2 |= a[i].charAt(k) == 'S';
                if (!f1 || !f2) res++;
            }
        }
        System.out.print(res);
    }
}