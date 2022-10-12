import java.io.*;
import java.util.*;

public class Pro
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        int x = cin.nextInt();
        int y = cin.nextInt();
        
        if (y == 0)
        {
            out.print("No");
        }
        else
        if (y == 1)
        {
            if (x == 0)
            {
                out.print("Yes");
            }
            else
            {
                out.print("No");
            }
        }
        else
        if (x > y - 2 && (x - y) % 2 != 0)
        {
            out.print("Yes");
        }
        else
        {
            out.print("No");
        }
        out.flush();
    }
}