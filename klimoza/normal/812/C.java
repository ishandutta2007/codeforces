import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by  on 07.06.2017.
 */
public class Market {
    Scanner in;
    public static void main(String[] args) {
        new Market().run();
    }

    private void run() {
        in = new Scanner(System.in);
        int n = in.nextInt();
        int s = in.nextInt();
        long[] gods = new long[n];
        for (int i = 0; i < n; i++) {
            gods[i] = in.nextInt();
        }
        long l = 1;
        long r = n;
        while(r-l>1){
            long m = (r+l)/2;
            if(totalCost(gods, m, n) > s){
                r = m;
            } else {
                l = m;
            }
        }
        long sumr = totalCost(gods,r,n);
        long suml = totalCost(gods,l,n);
        if (s >= sumr){
           System.out.println(r + " " + sumr);
        } else if(s >= suml){
            System.out.println(l + " " + suml);
        } else {
            System.out.println("0 0");
        }

    }
    
    private long totalCost(long[] gods, long k, int n ) {
        long[] rar = new long[n];
        for(int i = 0; i < n; i++){
            rar[i] = gods[i] + (i+1)*k;
        }
        Arrays.sort(rar);
        long sum = 0;
        for(int i = 0; i < k; i++){
            sum+=rar[i];
        }
        return sum;
    }
}