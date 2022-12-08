
import java.io.*;
import java.util.*;
import java.lang.*;
public class D {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String s1 = in.next();
        String s2 = in.next();
        char[] ar1 = s1.toCharArray();
        char[] ar2 = s2.toCharArray();
        String f = "";
        for(int i = 0; i < s1.length(); i++){
            if(ar2[i] > ar1[i]){
                f="-1";
                break;
            } else
                f+=ar2[i];
        }
        System.out.println(f);
    }
}