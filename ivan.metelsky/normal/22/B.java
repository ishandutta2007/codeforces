import java.util.Arrays;
import java.util.Scanner;

public class CDF22_B {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), M = sc.nextInt();
        String[] A = new String[N];
        for (int i=0; i<N; i++) A[i] = sc.next();
        sc.close();
        
        int max = 0;
        for (int i1=0; i1<N; i1++)
            for (int i2=i1; i2<N; i2++)
                for (int j1=0; j1<M; j1++)
                    for (int j2=j1; j2<M; j2++) {
                        boolean ok = true;
                        for (int i=i1; i<=i2; i++)
                            for (int j=j1; j<=j2; j++)
                                if (A[i].charAt(j) == '1')
                                    ok = false;
                        if (ok) max = Math.max(max, (i2 - i1 + j2 - j1 + 2) * 2);
                    }
        
        System.out.println(max);
    }
}