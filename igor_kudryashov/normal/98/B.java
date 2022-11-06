import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.math.*;

public class Solution 
{
    public static class Frac
    {
        BigInteger numer, denom;
        Frac () { numer = BigInteger.ZERO; denom = BigInteger.ONE; }
        Frac (BigInteger num, BigInteger den) { numer = num; denom = den; }
    }
    
    static int n, sza;
    static int idx[], a[];
    static Frac k[], b[], d[];
    static long stTime;
    
    public static Frac multFrac (Frac a, Frac b)
    {
        BigInteger g1 = a.numer.gcd(b.denom), g2 = a.denom.gcd(b.numer);
        return new Frac(a.numer.divide(g1).multiply(b.numer.divide(g2)), a.denom.divide(g2).multiply(b.denom.divide(g1)));
    }
    
    public static Frac norm (Frac a)
    {
        BigInteger g = a.numer.gcd(a.denom);
        return new Frac(a.numer.divide(g), a.denom.divide(g));
    }
    
    public static Frac addFrac (Frac a, Frac b)
    {
        BigInteger lcm = a.denom.divide(a.denom.gcd(b.denom)).multiply(b.denom);
        BigInteger num = a.numer.multiply(lcm.divide(a.denom)).add(b.numer.multiply(lcm.divide(b.denom)));
        
        return new Frac(num, lcm);
        
        /*
        BigInteger num = a.numer.multiply(b.denom).add(b.numer.multiply(a.denom));
        BigInteger den1 = a.denom, den2 = b.denom;
        BigInteger g1 = num.gcd(den1);
        num = num.divide(g1);
        den1 = den1.divide(g1);
        BigInteger g2 = num.gcd(den2);
        num = num.divide(g2);
        den2 = den2.divide(g2);
        
        return new Frac(num, den1.multiply(den2));
        */
    }

    static Frac solve ()
    {
        int cnt = 1;
        int fcalc = -1;
        
        while (true)
        {
            a[sza] = cnt;
            idx[cnt] = sza;
            
            int h = 0;
            while ((cnt << h) < n)
                h++;
            
            int rem = (cnt << h) - n;
            
            if (rem == 0)
            {
                d[sza] = new Frac(BigInteger.valueOf(h), BigInteger.ONE);
                fcalc = sza;
                break;
            }
            
            b[sza] = new Frac(BigInteger.valueOf(h), BigInteger.ONE);
            k[sza] = new Frac(BigInteger.valueOf(rem), BigInteger.valueOf(cnt << h));
            
            if (idx[rem] != -1)
            {
                Frac curb = b[sza], curk = k[sza];
                
                for (int i = sza - 1; i >= idx[rem]; i--)
                {
                    Frac nb = addFrac(b[i], multFrac(curb, k[i]));
                    Frac nk = multFrac(curk, k[i]);
                    curb = nb; curk = nk;
                }
                    
                d[idx[rem]] = multFrac(new Frac(curk.denom, curk.denom.subtract(curk.numer)), curb);
                
                fcalc = idx[rem];
                break;
            }
            sza++;
            cnt = rem;
        }
        
        Frac cur = d[fcalc];
        for (int i = fcalc - 1; i >= 0; i--)
            cur = addFrac(b[i], multFrac(k[i], cur));

        cur = norm(cur);
            
        return cur;
    }
    
    public static void main (String[] argv)
    {
        Scanner in = new Scanner (System.in);
        n = in.nextInt();
        stTime = System.currentTimeMillis();
        idx = new int [n + 5];
        for (int i = 0; i <= n; i++)
            idx[i] = -1;
        a = new int [n + 5];
        sza = 0;
        k = new Frac [n + 5];
        b = new Frac [n + 5];
        d = new Frac [n + 5];
        
        Frac ans = solve();
        //System.out.println(System.currentTimeMillis() - stTime);
        
        System.out.println(ans.numer + "/" + ans.denom);        
    }
}