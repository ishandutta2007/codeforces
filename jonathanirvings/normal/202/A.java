import java.util.Scanner;
import java.util.Arrays;
public class Main
{
    public static void main (String[] args)
    {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        char[] tmp = s.toCharArray();
        Arrays.sort(tmp);
        s = new String(tmp);
        int k = s.length();
        System.out.printf("%c",s.charAt(k-1));
        for (int i = k - 2; i >= 0; --i)
        {
            if (s.charAt(i) == s.charAt(i+1)) System.out.printf("%c",s.charAt(i));
            else break;
        }
        System.out.println("");
    }
}