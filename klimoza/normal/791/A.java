import java.math.BigInteger;
import java.util.*;
import java.lang.*;
        import java.io.*;
public class C {
    Scanner in;
    public static void main(String[] args) throws IOException {
        new C().run();
    }
    public void run() throws IOException {
        in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int j = 0;
        while(n <= m){
            j++;
            n = n * 3;
            m = m * 2;
        }
        System.out.println(j);
    }
}