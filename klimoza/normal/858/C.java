import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args){
        new A().run();
    }
    public void run(){
        Scanner in = new Scanner(System.in);
        String s = in.next();
        char[] ar = s.toCharArray();
        char[] bukv = {'a', 'e', 'i', 'o', 'u'};
        ArrayList<Integer> list = new ArrayList<>();
        int t = 0;
        for(int i = 0; i < ar.length; i++){
            if(check(bukv, ar[i])){
                t++;
                if(t >= 3 && (ar[i - 2] != ar[i - 1] || ar[i - 1] != ar[i])){
                    list.add(i);
                    t = 1;
                }
            } else{
                t = 0;
            }
        }
        int j = 0;
        String h = "";
        for(int i = 0; i < ar.length; i++){
            if(j < list.size() && list.get(j) == i){
                h += " ";
                j += 1;
            }
            h+=ar[i];
        }
        System.out.println(h);
    }
    public boolean check(char[] ar, char i){
        boolean bl = true;
        for(int j = 0; j < ar.length; j++){
            if(ar[j] == i){
                bl = false;
                break;
            }
        }
        return bl;
    }
}