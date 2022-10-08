import java.util.*;
import java.io.*;

public class Solution {
    public static void doMain() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int x = sc.nextInt(), y = sc.nextInt();
        sc.close();
        
        int who = 0;
        while (true) {
            if (who == 0) {
                if (x >= 2 && y >= 2) {
                    x -= 2; y -= 2;
                } else if (x >= 1 && y >= 12) {
                    x -= 1; y -= 12;
                } else if (x >= 0 && y >= 22) {
                    x -= 0; y -= 22;
                } else {
                    System.out.println("Hanako");
                    System.exit(0);
                }
            } else {
                if (x >= 0 && y >= 22) {
                    x -= 0; y -= 22;
                } else if (x >= 1 && y >= 12) {
                    x -= 1; y -= 12;
                } else if (x >= 2 && y >= 2) {
                    x -= 2; y -= 2;
                } else {
                    System.out.println("Ciel");
                    System.exit(0);
                }
            }
            who = 1 - who;
        }
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}