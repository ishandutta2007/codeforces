import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args){
        new A().run();
    }
    public static void run(){
        Scanner in = new Scanner(System.in);
        long l = in.nextLong();
        long r = in.nextLong();
        long x = in.nextLong();
        long y = in.nextLong();
        double k = in.nextDouble();
        boolean bl = false;
        long i = x;
        while(i <= y){
            double t = i * k;
            if(l <= t && t <= r && (int)t == t){
                bl = true;
                break;
            }
            i++;
        }
        if(bl){
            System.out.println("YES");
        } else{
            System.out.println("NO");
        }

    }
}