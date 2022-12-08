import java.util.*;
import java.lang.*;
import java.io.*;

/**
 * Created by   on 21.01.2017.
 */
public class C {
    int g;
    Scanner in;
    public static void main(String[] args) {
        new C().run();
    }
    public void run(){
        in = new Scanner(System.in);
        int n = in.nextInt();
        g = n;
        Set<Integer> snack = new HashSet<Integer>();
        for(int i = 0;i < n; i++){
            snack.add(in.nextInt());
            while(snack.contains(g)){
                System.out.print(g + " ");
                g--;
            }
            System.out.println();
        }
    }

}