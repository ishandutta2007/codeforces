import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        if (n % 2 == 0) {
            System.out.println((n - 4) + " " + 4);
        } else {
            System.out.println((n - 9) + " " + 9);
        }
    }
}