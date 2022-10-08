import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        sc.close();
        int cur = 0;
        int add = 1;
        for (int i=0; i < n-1; i++) {
            cur += add;
            while (cur >= n) cur -= n;
            System.out.print(cur + 1);
            if (i + 1 < n - 1)
                System.out.print(" ");
            else
                System.out.println();
            add++;
        }
    }
}