import java.util.Scanner;

public class Main 
{
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) throws Exception 
    {
        int tc = scanner.nextInt();
        while (tc > 0)
        {
            int n = scanner.nextInt();
            int limit = scanner.nextInt();
            int toAdd = scanner.nextInt();
            int toSub = scanner.nextInt();
            System.out.println(solve(n, limit, toAdd, toSub));
            tc --;
        }
    }
    static long solve(int n,int limit,int toAdd,int toSub)
    {
        long sum = 0;
        int lastElement = 0;
        for (int i=1; i<=n; i++)
        {
            if (lastElement + toAdd <= limit)
                lastElement += toAdd;
            else
                lastElement -= toSub;
            sum += lastElement;
        }
        return sum;
    }
}