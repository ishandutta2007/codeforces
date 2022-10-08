import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    int gcd(int a, int b) {
        while (a>0 && b>0) if (a>b) a%=b; else b%=a;
        return a+b;
    }
    
    public void doMain() throws Exception {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        sc.close();
        int nom = 0, denom = (A-1) - 2 + 1;
        for (int x=2; x<A; x++) {
            int sum=0;
            int tmp = A;
            while (tmp>0) {
                sum += tmp % x;
                tmp /= x;
            }
            nom += sum;
        }
        int d = gcd(nom, denom);
        System.out.println((nom/d)+"/"+(denom/d));
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}