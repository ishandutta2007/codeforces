
import java.io.*;
import java.util.*;
import java.lang.*;
public class D {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String s = in.next();
        char[] ar = s.toCharArray();
        int t = 0;
        if(s.length() != 1){
            for(int i = 0; i < ar.length-1; i++){
                if((ar[i]  + "" + ar[i+1]).equals("VK")){
                    ar[i] = ' ';
                    ar[i+1] = ' ';
                    i++;
                    t++;
                }
            }
            String f = "";
            for(int i = 0; i < ar.length; i++){
                f+=ar[i] + "";
            }
            String[] array = f.split("[ ]");
            for(int i = 0; i < array.length; i++){
                if(!array[i].equals("KV") && array[i].length()>1){
                    t++;
                    break;
                }
            }
        }
        System.out.println(t);
    }
}