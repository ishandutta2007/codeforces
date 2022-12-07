import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
        
            int n,k;
            n=sc.nextInt();
            k=sc.nextInt();
        
            int a[]=new int[n];
        
            for(int i=0;i<n;i++)
                a[i]=sc.nextInt();
            
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(k+a[i]<=5)
                    count++;
            }
            System.out.println(+(count/3));
    }
}