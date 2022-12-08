import java.io.*;
import java.util.*;
public class B {
    Scanner in;

    public static void main(String[] args) {
        new B().run();
    }

    public void run() {
        in = new Scanner(System.in);
        double n = in.nextInt();
        double h = in.nextInt();
        double S = h/(n*2);
        double x = 0;
        double y = 0;
        for(int i = 1; i<=n-1; i++){
            x = Math.sqrt(i*S*2/h);
            y = h * x;
            System.out.print(y + " ");
        }
    }
}