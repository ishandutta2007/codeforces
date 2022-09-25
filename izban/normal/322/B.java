import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            int a = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            int ans = 0;
            for (int k = 0; k < 3 && a >= 0 && b >= 0 && c >= 0; k++) {
                ans = Math.max(ans, k + a / 3 + b / 3 + c /3);
                a--; b--; c--;
            }
            System.out.println(ans);
        }
    }
}