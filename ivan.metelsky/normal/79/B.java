import java.util.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        int t = sc.nextInt();
        
        int[] x = new int[k];
        int[] y = new int[k];
        
        for (int i=0; i < k; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        
        for (int i=0; i < t; i++) {
            int xx = sc.nextInt();
            int yy = sc.nextInt();
            
            boolean find = false;
            for (int j=0; j < k; j++)
                if (x[j] == xx && y[j] == yy)
                    find = true;
            
            if (find) {
                System.out.println("Waste");
                continue;
            }
            
            int id = (xx - 1) * m + (yy - 1);
            for (int j=0; j < k; j++)
                if (x[j] < xx || x[j] == xx && y[j] < yy)
                    id--;
            
            if (id % 3 == 0) {
                System.out.println("Carrots");
            } else if (id % 3 == 1) {
                System.out.println("Kiwis");
            } else {
                System.out.println("Grapes");
            }
        }
        
        sc.close();
        
    }
}