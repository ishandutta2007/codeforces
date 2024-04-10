import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args){
        new A().run();
    }
    public static void run(){
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        int k = in.nextInt();
        int f = 1;
        while(n % Math.pow(10, k) != 0){
            long t = (long)n / f;
            t = t % 10;
            if(t == 5){
                n *= 2;
            } else if(t == 0){
                f *= 10;
            } else if(t % 2 == 0){
                n *= 5;
            } else {
                n *= 10;
            }
        }
        System.out.println(n);
    }
}