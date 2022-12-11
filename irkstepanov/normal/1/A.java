import java.util.Scanner;
public class Solver {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextInt();
        long m = in.nextInt();
        long a = in.nextInt();
        System.out.println(((n + a - 1) / a) * ((m + a - 1) / a));
    }
}