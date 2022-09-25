import java.util.*;
import java.math.*;
import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: dns
 * Date: 11.06.12
 * Time: 12:28
 * To change this template use File | Settings | File Templates.
 */


public class a{

    public static void main(String [] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        in.nextLine();
        Long a=1L, b=1L;
        for (int i=0; i<n; i++) {
            String s=in.nextLine();
            if (s.equals("UR") || s.equals("DL")) a++;
            if (s.equals("UL") || s.equals("DR")) b++;
            if (s.equals("ULDR")) {
                a++;
                b++;
            }
        }
        System.out.println(a*b);
    }
}