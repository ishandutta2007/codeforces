import java.util.*;
import java.lang.*;
/**
 *
 * @author Jeel
 */
public class JavaApplication1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        
        int n=sc.nextInt();
        long x=sc.nextLong();
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
           char o;
           long num;
           o=sc.next().charAt(0);
           num=sc.nextLong();
           
           if(o=='-')
           {
               if(x>=num)
                   x-=num;
               else
                   ans++;
           }
           
           else
           {
               x+=num;
           }
        }
        
        System.out.print(x+" "+ans);
    }
    
}