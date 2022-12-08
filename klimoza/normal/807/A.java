import java.io.*;
import java.util.*;
import java.lang.*;

public class E {
    static Scanner in;
    public static void main(String[] args){
        in = new Scanner(System.in);
        int n = in.nextInt();
        int tl = 0;
        int t = 0;
        int h1 = 0;
        int h2 = 0;
        boolean r = true;
        boolean m = true;
        for(int i = 0; i < n; i++){
            h1 = in.nextInt();
            h2 = in.nextInt();
            if(h1 != h2){
              r = false;
              break;
            } else if(h1 == h2){
                tl = t;
                t = h1;
            }
            if(t!=0 && tl != 0 && tl < t){
                m = false;
            }

        }
        if(!r){
            System.out.println("rated");
        } else if(r && !m){
            System.out.println("unrated");
        } else if(r && m){
            System.out.println("maybe");
        }

     }
}