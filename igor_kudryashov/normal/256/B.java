import java.util.*;
import java.io.*;
import java.math.*;

public class Solution
{
    static long n, x, y, c;

    static boolean can (long len)
    {
        BigInteger blen = BigInteger.valueOf(len);
        
        //BigInteger sum = blen.multiply(blen.add(BigInteger.ONE)).multiply(blen.shiftLeft(1).add(BigInteger.ONE)).divide(BigInteger.valueOf(6));
        BigInteger sum = BigInteger.ONE;
        sum = sum.add(blen.multiply(blen.add(BigInteger.ONE)).shiftLeft(1));
        
        long a1 = Math.max(0, len - x);
        sum = sum.subtract(BigInteger.valueOf(a1).multiply(BigInteger.valueOf(a1)));
        
        long a2 = Math.max(0, len - y);
        sum = sum.subtract(BigInteger.valueOf(a2).multiply(BigInteger.valueOf(a2)));

        long a3 = Math.max(0, len - (n - 1 - x));
        sum = sum.subtract(BigInteger.valueOf(a3).multiply(BigInteger.valueOf(a3)));
        
        long a4 = Math.max(0, len - (n - 1 - y));
        sum = sum.subtract(BigInteger.valueOf(a4).multiply(BigInteger.valueOf(a4)));
        
        if (y - a1 + 1 < 0)
        {
            long b1 = Math.abs(y - a1 + 1);
            sum = sum.add(BigInteger.valueOf(b1).multiply(BigInteger.valueOf(b1 + 1)).shiftRight(1));
        }
        
        if (y - a3 + 1 < 0)
        {
            long b1 = Math.abs(y - a3 + 1);
            sum = sum.add(BigInteger.valueOf(b1).multiply(BigInteger.valueOf(b1 + 1)).shiftRight(1));
        }
        
        if (y + a1 - 1 >= n)
        {
            long b1 = y + a1 - n;
            sum = sum.add(BigInteger.valueOf(b1).multiply(BigInteger.valueOf(b1 + 1)).shiftRight(1));
        }
        
        if (y + a3 - 1 >= n)
        {
            long b1 = y + a3 - n;
            sum = sum.add(BigInteger.valueOf(b1).multiply(BigInteger.valueOf(b1 + 1)).shiftRight(1));
        }
        
        return sum.compareTo(BigInteger.valueOf(c)) >= 0;
    }

    public static void main (String argv[])
    {
        Scanner in = new Scanner(System.in);
        
        n = in.nextLong();
        x = in.nextLong();
        y = in.nextLong();
        c = in.nextLong();
        x--; y--;
        
        long lf = 0, rg = 2 * 1000 * 1000 * 1000 + 3;
        
        while (lf != rg)
        {
            long mid = (lf + rg) >> 1;
            
            if (can(mid))
                rg = mid;
            else
                lf = mid + 1;
        }
        
        System.out.println(lf);
    }
}