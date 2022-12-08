import java.io.*;
import java.util.*;
public class B {
    Scanner in;

    public static void main(String[] args) {
        new B().run();
    }

    public void run() {
        in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = in.nextInt();
        int n = in.nextInt();
        int h = 0;
        int t = 0;
        for(int i = 0; i < n; i++){
            t = in.nextInt();
            if(t > b && t < c){
                h++;
            }
        }
        System.out.println(h);
    }
}