using System;
using System.Numerics;

public class Test
{
	public static void Main()
	{
		int[] nk = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        BigInteger n = nk[0];
        BigInteger c1 = nk[1];
        BigInteger c2 = nk[2];
        BigInteger ad = 0, ch = 0;
        string s = Console.ReadLine();
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                ch++;
            else
                ad++;
        }
        BigInteger mn = 1000000000000000000;
        mn = mn * mn * mn;
        for (BigInteger i = 1; i <= ad; i++) {
        	BigInteger small = (ch + ad - i) / i;
        	BigInteger big = small + 1;
        	BigInteger cn_big = (ch + ad - i) % i;
        	BigInteger cn_small = i - cn_big;
        	BigInteger x = cn_big * (c1 + c2 * big * big) + cn_small * (c1 + c2 * small * small);
        	if (x < mn)
        		mn = x;
        }
        Console.WriteLine(mn);
	}
}