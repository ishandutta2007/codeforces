import java.io.*;
import java.util.*;
public class SolForOlymp1 {
    Scanner in;
    public static void main(String[] args){
        new SolForOlymp1().run();
    }
    public void run(){
        in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int i = 1;
        while(a >= 0 && b >= 0){
            a-=i;
            i++;
            b-=i;
            i++;
        }
        if(a < 0 && b < 0){
            System.out.println("Vladik");
        } else if(a< 0 && b > 0){
            System.out.println("Vladik");
        } else {
            System.out.println("Valera");
        }
    }

}