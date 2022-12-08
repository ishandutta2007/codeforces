import java.io.*;
import java.util.*;
import java.lang.*;

public class A {
    Scanner in;

    public static void main(String[] args) throws FileNotFoundException {
        new A().run();
    }

    public void run() throws FileNotFoundException {
        in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int[] ar1 = new int[n];
        ar1[0] = in.nextInt();
        int min = ar1[0];
        int m = min%k;
        boolean nep = true;
        for(int i = 1; i < n; i++){
            ar1[i] = in.nextInt();
            if(ar1[i] < min){
                min = ar1[i];
            }
            if(ar1[i]%k != m){
                nep = false;
            }
        }
        if(!nep){
            System.out.println(-1);
        } else {
            int f = 0;
            long h = 0;
            for(int i = 0; i < n; i++){
                f = (ar1[i] - min)/k;
                h+=f;
            }
            System.out.println(h);
        }

    }
}