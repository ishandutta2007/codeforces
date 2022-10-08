import java.util.*;
import java.io.*;

public class Solution {
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        String bestName = null;
        int maxPoints = -1000000000;
        for (int i=0; i < n; i++) {
            String name = sc.next();
            int points = 100 * sc.nextInt() - 50 * sc.nextInt() + sc.nextInt() + sc.nextInt() + sc.nextInt() + sc.nextInt() + sc.nextInt();
            if (points > maxPoints) {
                maxPoints = points;
                bestName = name;
            }
        }
        sc.close();
        System.out.println(bestName);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}