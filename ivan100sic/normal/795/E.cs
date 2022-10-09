using System;
using System.Collections.Generic;

namespace Codeforces
{
    class MainClass
    {
        public static void Main (string[] args)
        {       
           

            string s = Console.ReadLine();
            long m = Convert.ToInt32(Console.ReadLine());

            long n = s.Length;

            long[] a = new long[n+1];
            long[] p = new long[n+1];

            p[0] = 1;
            for (int i=1; i<=n; i++) {
                p[i] = (p[i-1] * 10) % m;
            }

            a[0] = (int)Char.GetNumericValue(s[0]);
            for (int i=1; i<n; i++) {
                a[i] = (a[i-1] * 10 + 
                        (int)Char.GetNumericValue(s[i])
                    ) % m;
            }

            long sol = m-1;

            for (int i=0; i<n; i++) {

                if (s[i] == '0') {
                    continue;
                }

                long val;
                if (i > 0) {
                    val = (a[n-1] + m - (a[i-1] * p[n-i]) % m) % m;
                } else {
                    val = a[n-1];
                }

                if (i > 0) {
                    val = (val * p[i] + a[i-1]) % m;
                }

                if (val < sol) {
                    sol = val;
                }
            }

            Console.Write(sol);

        }
    }
}