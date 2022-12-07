import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int a[] = new int[n];
        for(int i = 0; i < n; ++i)
            a[i] = sc.nextInt();
 
        int divCnt[] = new int[1000001];
        for(int i = 1000000; i >= 1; --i) {
            for(int j = i; j <= 1000000; j += i)
                divCnt[j]++;
        }

        int div[][] = new int[1000001][];
        for(int i = 1; i <= 1000000; ++i)
            div[i] = new int[divCnt[i]];

        int ptr[] = new int[1000001];
        for(int i = 1000000; i >= 1; --i) {
            for(int j = i; j <= 1000000; j += i)
                div[j][ptr[j]++] = i;
        }

        long mod = (long)1e9 + 7;
        
        long ans[] = new long[1000001];
        ans[0] = 1;

        for(int i = 0; i < n; ++i) {
            for(int j : div[a[i]]) {
                ans[j] = (ans[j] + ans[j - 1]) % mod;
            }
        }

        long fans = 0;
        for(int i = 1; i <= 1000000; ++i) {
            fans = (fans + ans[i]) % mod;
        }

        System.out.print(fans);
    }
}