import java.io.*;
import java.util.*;

public class Pro
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int a = cin.nextInt();
        int b = cin.nextInt();
        int q = 0;
        for(int i = 0; i < 40; i++)
        {
            for(int j = 0; j < 40; j++)
            {
                long kk = 1;
                for (int x = 0; x < i; x++)
                {
                    kk = kk * 2;
                }
                for (int y = 0; y < j; y++)
                {
                    kk = kk * 3;
                    if (kk > 2000000000)
                        break;
                }
                //out.println(kk);
                if (a <= kk && kk <= b)
                    q++;
            }
        }
        out.println(q);
        out.flush();
    }
}