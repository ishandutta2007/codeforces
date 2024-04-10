import java.io.*;
import java.util.*;

public class Try {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
            int n=sc.nextInt();
            int t=sc.nextInt();
            int k=sc.nextInt();
            int d=sc.nextInt();
        
            int check=d/t+1;
        
            if(check*k>=n)
                System.out.print("NO");
            else
                System.out.print("YES");
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}