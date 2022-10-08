import java.util.*;

public class CDF22_C {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), v = sc.nextInt();
        sc.close();
        
        int minEdges = n - 1;
        int maxEdges = (n > 1000 ? 1000000 : ((n - 1) * (n - 2)) / 2 + 1);
        
        if (m < minEdges || m > maxEdges) {
            System.out.println(-1);
            System.exit(0);
        }
        
        boolean[] taken = new boolean[n+1];
        
        int i = 1;
        while (i == v) i++;
        
        System.out.println(v + " " + i);
        taken[i] = true;
        m--;
        
        for (i=1; i <= n; i++)
            if (!taken[i] && i != v) {
                System.out.println(v + " " + i);
                m--;
            }
        
        for (i=1; i <= n; i++)
            for (int j=i+1; j <= n; j++) {
                if (!taken[i] && !taken[j] && i != v && j != v) {
                    System.out.println(i + " " + j);
                    m--;
                }
                if (m == 0)
                    System.exit(0);
            }
    }
}