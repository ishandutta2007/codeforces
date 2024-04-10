import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            int n = in.nextInt();
            int m = in.nextInt();
            System.out.println(n + m - 1);
            for (int i = 1; i <= m; i++) System.out.println("1 " + Integer.toString(i));
            for (int i = 2; i <= n; i++) System.out.println(Integer.toString(i) + " 1");
        }
    }
}