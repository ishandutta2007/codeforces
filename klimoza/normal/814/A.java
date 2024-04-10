import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class B {
    Scanner in;

    public static void main(String[] args) {
        new B().run();
    }

    public void run() {
        in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        if(k > 1){
            System.out.println("Yes");
        } else {
            int[] ar = new int[n];
            int index = 0;
            for(int i = 0; i < n; i++){
                ar[i] = in.nextInt();
                if(ar[i] == 0){
                    index = i;
                }
            }
            ar[index] = in.nextInt();
            boolean bl = false;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n-1; j++){
                    if(ar[j] > ar[j+1]){
                        bl = true;
                        j = n-2;
                    }
                    if(bl){
                        i = n-1;
                    }
                }
            }
            if(bl){
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }

        }
    }
}