
import java.util.*;

/**
 *
 * @author alexandru
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.print(s.charAt(0));
        char c = s.charAt(s.length()-1);
        s = s.substring(1, s.length()-1);
        
        s = s.replaceAll("dot", ".");
        s = s.replaceFirst("at", "@");
        System.out.print(s);
        System.out.println(c);
                

    }
    
}