import java.math.*;
import java.util.*;
import java.io.*;


public class Main {
    final int maxn = 1 << 17;
    int n;


    public void Run() {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(((i + j) % n + j * n + 1) + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}