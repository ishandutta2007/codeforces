import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        
        int a[]=new int[n];
        
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
        
        Arrays.sort(a);
        
        int flag=0;
        
        for(int i=0;i<n;i++)
        {
            if(a[i]!=a[0])
            {
                System.out.print(a[i]);
                flag=1;
                break;
            }
        }
        if(flag==0)
            System.out.print("NO");
    }
}