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
        int[] ar = new int[n];
        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            ar[i] = in.nextInt();
            if (ar[i] == 0) {
                list.add(i);
            }
        }
        int h = 0;
        for(int i = 0; i< n; i++){
            if(ar[i] == 0){
                System.out.print(0 + " ");
            } else {
                while(h < list.size()-1 && list.get(h) < i){
                    h++;
                }
                if(h>=1){
                    System.out.print(Math.abs(Math.min(Math.abs(i-list.get(h-1)),list.get(h)-i)) + " ");
                } else {
                    System.out.print(Math.abs(list.get(h)-i) + " ");
                }

            }
        }
    }
}