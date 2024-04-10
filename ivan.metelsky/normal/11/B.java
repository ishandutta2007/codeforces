import java.util.*;

public class Solution {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        long x = sc.nextLong();
        if (x==0) {
            System.out.println(x);
            System.exit(0);
        }
        long l = 0, r = 0;
        for (int i=1; ; i++) {
            l -= i; r += i;
            if (l <= x && x <= r && (r - x) % 2 == 0) {
                System.out.println(i);
                System.exit(0);
            }
        }
    }
}