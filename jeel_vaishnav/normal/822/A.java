import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    static int fact(int num)
    {
        if(num==1)
            return 1;
        else
            return num*fact(num-1);
    }
    static int min(int a,int b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        System.out.print(fact(min(a,b)));
    }
}