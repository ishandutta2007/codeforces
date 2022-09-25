import java.util.*;


public class Main {

    long x, y;

    long gcd(long a, long b) {
        while (b > 0) {
            a = a % b;
            b = a ^ b;
            a = a ^ b;
            b = a ^ b;
        }
        return a;
    }

    long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    long solve(int n) {
        return n / lcm(x, y);
    }

    public void Run() {
        Scanner in = new Scanner(System.in);
        x = in.nextInt();
        y = in.nextInt();
        int a = in.nextInt();
        int b = in.nextInt();
        System.out.println(solve(b) - solve(a - 1));
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}