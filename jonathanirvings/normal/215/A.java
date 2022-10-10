import java.util.Scanner;
import java.lang.Math;
public class Main
{
    public static void main (String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n,m,data1[], data2[];
        data1 = new int[55];
        data2 = new int[55];
        int risan = 0, M = 0;
        m = in.nextInt();
        for (int i = 0; i < m; ++i) data1[i] = in.nextInt();
        n = in.nextInt();
        for (int i = 0; i < n; ++i) data2[i] = in.nextInt();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (data2[j] % data1[i] == 0) M = Math.max(M,data2[j] / data1[i]);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (data2[j] % data1[i] == 0 && data2[j] / data1[i] == M) ++risan;
        System.out.println(risan);
    }
}