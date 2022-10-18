import java.util.Scanner;
import java.math.BigInteger;

public class ac {
   public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       String s = sc.next();
       for(int i=0; i<s.length(); i++){
           for(int j=i; j<s.length(); j++){
               for(int k=j; k<s.length(); k++){
                   int ans = s.charAt(i) - '0';
                   if(j>i) ans = ans*10 + s.charAt(j) - '0';
                   if(k>j) ans = ans*10 + s.charAt(k) - '0';
                   if(ans % 8 == 0){
                       System.out.println("YES");
                       System.out.println(ans);
                       System.exit(0);
                   }
               }
           }
       }
      System.out.println("NO");
   }
}