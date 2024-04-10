import java.util.Scanner;
public class Main
{
    public static void main (String[] args)
    {
        Scanner in = new Scanner(System.in);
        int a,b,c;
        a = in.nextInt(); b = in.nextInt(); c = in.nextInt();
        if (a >= 2 * c && b >= 2 * c) System.out.println("First");
        else System.out.println("Second");
    }
}