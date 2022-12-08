import java.io.*;
import java.util.*;
public class B {
    Scanner in;

    public static void main(String[] args) {
        new B().run();
    }

    public void run() {
        in = new Scanner(System.in);
        int n = in.nextInt();
        int f = in.nextInt();
        int[] ar1 = new int[n];
        int[] ar2 = new int[n];
        long sumik = 0;
        for(int i = 0 ; i < n; i++){
            ar1[i] = in.nextInt();
            ar2[i] = in.nextInt();
        }
        int[] a = new int[n];
        int t1 = 0;
        int t2 = 0;
        for(int i = 0 ; i < n; i++) {
            t1 = Math.min(ar1[i], ar2[i]);
            t2 = Math.min(2 * ar1[i], ar2[i]);
            a[i] = t2 - t1;
            sumik+=t1;
        }
        Arrays.sort(a);
        long sum = 0;
        for(int i = n-1; i >=n-f; i--){
            sum+=a[i];
        }
        System.out.println(sumik + sum);

    }
}