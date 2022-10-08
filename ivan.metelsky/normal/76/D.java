import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        BigInteger A = new BigInteger(sc.next());
        BigInteger B = new BigInteger(sc.next());
        sc.close();
        
        if (A.compareTo(B) < 0) {
            System.out.println(-1);
            System.exit(0);
        }
        
        BigInteger X = A.subtract(B).divide(BigInteger.valueOf(2));
        BigInteger Y = A.subtract(X);
        
        if (X.compareTo(BigInteger.ZERO) >= 0 && Y.compareTo(BigInteger.ZERO) >= 0 &&
            X.add(Y).compareTo(A) == 0 && X.xor(Y).compareTo(B) == 0) {
            System.out.println(X + " " + Y);
        } else System.out.println(-1);
    }
    
    public static void main(String[] args) throws Exception {
        new Solution().go();
    }
}