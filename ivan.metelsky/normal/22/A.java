import java.util.*;

public class CDF22_A {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i=0; i<N; i++)
            A[i] = sc.nextInt();
        Arrays.sort(A);
        int i = 0;
        while (i < A.length && A[i] == A[0]) i++;
        System.out.println(i == A.length ? "NO" : A[i]);
        sc.close();
    }
}