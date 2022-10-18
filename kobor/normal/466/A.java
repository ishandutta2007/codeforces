import java.util.Scanner;

public class ac {
   public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       int n = sc.nextInt();
       int m = sc.nextInt();
       int a = sc.nextInt();
       int b = sc.nextInt();
       if(a*m < b) System.out.println(a*n);
       else System.out.println(n/m * b + Math.min(n%m * a, b));
   }
}