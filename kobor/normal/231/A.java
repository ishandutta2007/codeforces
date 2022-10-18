import java.util.Scanner;

public class ac {
   public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       int n = sc.nextInt();
       int a, b, c;
       int ans = 0;
       for(int i=0; i<n; i++){
           a = sc.nextInt();
           b = sc.nextInt();
           c = sc.nextInt();
           ans += a+b+c > 1 ? 1 : 0;
       }
       System.out.println(ans);
   }
}