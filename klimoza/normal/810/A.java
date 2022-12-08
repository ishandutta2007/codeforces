import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class A {
    Scanner in;
    public static void main(String[] args){
        new A().run();
    }
    public void run(){
        in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum+=in.nextInt();
        }
        System.out.println((2*n*k - 2*sum - n < 0) ? 0 : 2*n*k - 2*sum - n);
    }

}