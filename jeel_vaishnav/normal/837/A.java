import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        sc.nextLine();
        String s=sc.nextLine();
        int len=0,max=0;
        for(int i=0;i<s.length();i++)
        {
            if(s.charAt(i)==' ')
            {
                if(len>max)
                    max=len;
                len=0;
            }
            else
            {
                if(s.charAt(i)>='A'&&s.charAt(i)<='Z')
                        len++;
            }
        }
        if(len>max)
            max=len;
        System.out.print(max);
    }
}