import java.util.Scanner;

public class ac {
   public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       int a = sc.nextInt();
       for(int i=0; i<a; i++){
           String s = sc.next();
           if(s.length()>10){
               Integer pom = s.length()-2;
               System.out.println(s.charAt(0)+ pom.toString() + s.charAt(s.length()-1));
           }
           else System.out.println(s);
       }
   }
}