import java.io.*;
import java.util.*;
public class B {
    Scanner in;

    public static void main(String[] args) {
        new B().run();
    }

    public void run() {
        in = new Scanner(System.in);
        in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int[] ar = new int[n];
        for (int i = 0; i < n; i++) {
            ar[i] = in.nextInt();
        }
        for(int i = 0; i < m; i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int c  = in.nextInt();
            int t1 =  c - a;
            int f = ar[c-1];
            int t2 = 0;
            for(int j = a-1; j <= b-1; j++){
                if(ar[j] <= f){
                    t2++;
                }
            }
            t2--;
            if(t2 == t1){
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }

    }
}