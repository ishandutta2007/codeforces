import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class SolForOlymp1 {
    Scanner in;
    public static void main(String[] args){
        new SolForOlymp1().run();
    }
    public void run() {
        in = new Scanner(System.in);
        char[] aleg = in.next().toCharArray();
        char[] igar = in.next().toCharArray();
        char[] nameCompany = new char[aleg.length];
        int n = aleg.length;
        Arrays.sort(aleg);
        Arrays.sort(igar);
        int l = 0;
        int r = aleg.length-1;
        int leftOleg = 0;
        int rightOleg = (n % 2 == 0 ? n / 2 - 1 : n / 2);
        int leftIgor = (n % 2 == 0 ? n / 2 : n / 2 + 1);
        int rightIgor = n - 1;
        boolean navalniy = true;


        for(int i = 0; i < nameCompany.length; i++){
            if(navalniy){
                if (aleg[leftOleg] >= igar[rightIgor]){
                    nameCompany[r] = aleg[rightOleg];
                    rightOleg--;
                    r--;
                } else {
                    nameCompany[l] = aleg[leftOleg];
                    leftOleg++;
                    l++;
                }
            } else {
                if(igar[rightIgor] <= aleg[leftOleg]){
                    nameCompany[r] = igar[leftIgor];
                    leftIgor++;
                    r--;
                } else {
                    nameCompany[l] = igar[rightIgor];
                    rightIgor--;
                    l++;
                }
            }
            navalniy = !navalniy;
        }
        for(int i = 0; i < nameCompany.length; i++){
            System.out.print(nameCompany[i]);
        }

    }
}