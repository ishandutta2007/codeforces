import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        long totalBlocks = 0;
        long a[] = new long[n];
        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextLong();
            totalBlocks += a[i];
        }

        Arrays.sort(a);

        long selected = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] > selected)
                selected++;
        }

        long leftCols = a[n - 1] - selected;
        long remBlocks = totalBlocks - leftCols - n;

        System.out.print(remBlocks);
    }
}