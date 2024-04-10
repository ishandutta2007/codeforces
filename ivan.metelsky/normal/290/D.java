import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemD {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        String s = sc.next();
        int x = sc.nextInt();
        sc.close();
        s = s.toLowerCase();
        String res = "";
        for (char c : s.toCharArray()) {
            if (c < x + 97) {
                res += Character.toUpperCase(c);
            } else {
                res += Character.toLowerCase(c);
            }
        }
        System.out.println(res);
    }
}