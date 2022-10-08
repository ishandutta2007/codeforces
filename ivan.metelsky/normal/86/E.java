import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    final int[][] data = new int[][] {
            {},
            {0},
            {1,0},
            {1,0},
            {1,0},
            {2,0},
            {1,0},
            {1,0},
            {4,3,2,0},
            {4,0},
            {3,0},
            {2,0},
            {6,4,1,0},
            {4,3,1,0},
            {5,3,1,0},
            {1,0},
            {5,3,2,0},
            {3,0},
            {5,2,1,0},
            {5,2,1,0},
            {3,0},
            {2,0},
            {1,0},
            {5,0},
            {4,3,1,0},
            {3,0},
            {6,2,1,0},
            {5,2,1,0},
            {3,0},
            {2,0},
            {6,4,1,0},
            {3,0},
            {7,5,3,2,1,0},
            {6,4,1,0},
            {7,6,5,2,1,0},
            {2,0},
            {6,5,4,2,1,0},
            {5,4,3,2,1,0},
            {6,5,1,0},
            {4,0},
            {5,4,3,0},
            {3,0},
            {5,4,3,2,1,0},
            {6,4,3,0},
            {6,5,2,0},
            {4,3,1,0},
            {8,5,3,2,1,0},
            {5,0},
            {7,5,4,2,1,0},
            {6,5,4,0},
            {4,3,2,0}
    };
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        sc.close();
        
        int[] c = new int[n];
        for (int x : data[n])
            c[n-x-1] = 1;
        
        for (int i=0; i < n; i++) {
            System.out.print(c[i]);
            if (i+1<n) System.out.print(" ");
            else System.out.println();
        }
        
        for (int i=0; i < n-1; i++)
            System.out.print(0 + " ");
        System.out.println(1);
        
//      int cnt = 0;
//
//      for (int mask=0; mask<(1<<n); mask++) {
//          int[] c = new int[n];
//          int tmp = mask;
//          for (int i=0; i<n; i++) {
//              c[i] = tmp%2;
//              tmp /= 2;
//          }
//          int[] a = new int[n];
//          a[n-1] = 1;
//          int[] b = a.clone();
//          int steps = 0;
//          while (steps == 0 || !Arrays.equals(a, b)) {
//              int next = 0;
//              for (int i=0; i < n; i++)
//                  next += c[i] * a[n-i-1];
//              for (int i=0; i + 1 < n; i++)
//                  a[i] = a[i+1];
//              a[n-1] = next % 2;
//              steps++;
//              if (steps > (1<<n)) break;
//          }
//          if (steps == ((1<<n)-1)) {
//              for (int i=0; i < n; i++) {
//                  System.out.print(c[i]+" ");
//              }
//              System.out.println();
//              cnt++;
////                System.exit(0);
//          }
//      }
//      
//      System.out.println(cnt+" "+(1<<n));
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}