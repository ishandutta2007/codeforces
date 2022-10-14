import java.util.Scanner;

public class firstProject {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        /*
      int n      = sc.nextInt();        // read input as integer
      long k     = sc.nextLong();       // read input as long
      double d   = sc.nextDouble();     // read input as double
      String str = sc.next();           // read input as String
      String s   = sc.nextLine();       // read whole line as String
      */

        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            String str = sc.next();
            if (str.length() <= 10) {
                System.out.println(str);
            } else {
                System.out.printf("%c%d%c\n", str.charAt(0), str.length()-2, str.charAt(str.length() - 1));
            }
        }
    }
}