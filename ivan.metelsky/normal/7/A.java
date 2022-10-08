import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    int bc(int x) {
        return (x==0?0:bc(x&(x-1))+1);
    }
    void doMain() {
        Scanner sc = new Scanner(System.in);
        char[][] c = new char[8][8];
        for (int i=0; i<8; i++) {
            String s = sc.next();
            c[i] = s.toCharArray();
        }
        sc.close();
        
        int res=100;
        
        for (int m1=0; m1<256; m1++)
            for (int m2=0; m2<256; m2++) {
                boolean ok = true;
                for (int i=0; i<8; i++) for (int j=0; j<8; j++)
                    if ((c[i][j] == 'B') != ((m1 & (1<<i)) != 0 || (m2 & (1<<j)) != 0))
                        ok = false;
                if (ok) res = Math.min(res, bc(m1)+bc(m2));
            }
        
        System.out.println(res);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}