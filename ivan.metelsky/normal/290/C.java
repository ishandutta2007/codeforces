import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemC {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int tux = sc.nextInt();
        int foo = 0, bar = 0, baz = 0, quz = 1;
        while (tux > 0) {
            int pur = sc.nextInt();
            foo = foo + pur;
            bar = bar + 1;
            if (foo * quz >= bar * baz) {
                baz = foo;
                quz = bar;
            }
            tux--;
        }
        sc.close();
        System.out.println(baz / (double)quz);
    }
}