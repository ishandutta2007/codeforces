import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();
        long s = sc.nextLong();

        long ans = (s - 1) / n + 1;
        System.out.print(ans);
    }
}