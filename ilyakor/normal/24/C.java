import java.util.Scanner;
import java.io.*;
import java.util.*;
import java.math.*;

public class Blank {

    public static void main(String args[]) throws IOException
    {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = in.nextInt();
        long ind = in.nextLong();
        int x = in.nextInt(), y = in.nextInt();
        Boolean flag = false;
        if (n % 2 == 1)
            flag = true;
        int[] ax = new int[flag ? 2 * n : n];
        int[] ay = new int[flag ? 2 * n : n];
        int sumX = 0, sumY = 0;
        for (int i = 0; i < n; i++)
        {
            ax[i] = in.nextInt();
            ay[i] = in.nextInt();
            sumX += (n - i) % 2 == 1 ? ax[i] : -ax[i];
            sumY += (n - i) % 2 == 1 ? ay[i] : -ay[i];
            if (flag)
            {
                ax[n + i] = ax[i];
                ay[n + i] = ay[i];
            }
        }
        sumX *= 2;
        sumY *= 2;
        if (flag)
        {
            sumX = 0;
            sumY = 0;
            n *= 2;
        }
        long i1 = ind / (long) n;
        BigInteger resx = BigInteger.valueOf(sumX).multiply(BigInteger.valueOf(i1));
        if ((i1 * n) % 2 == 0)
            resx = resx.add(BigInteger.valueOf(x));
        else
            resx = resx.subtract(BigInteger.valueOf(x));
        BigInteger resy = BigInteger.valueOf(sumY).multiply(BigInteger.valueOf(i1));
        if ((i1 * n) % 2 == 0)
            resy = resy.add(BigInteger.valueOf(y));
        else
            resy = resy.subtract(BigInteger.valueOf(y));
        for (int i = 0; i < ind % n; i++)
        {
            resx = BigInteger.valueOf(2 * ax[i]).subtract(resx);
            resy = BigInteger.valueOf(2 * ay[i]).subtract(resy);
        }
        System.out.println(resx + " " + resy);
    }
}