import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        char trump=sc.next().charAt(0);
        String card1=sc.next();
        String card2=sc.next();
        if(card1.charAt(1)==trump&&card2.charAt(1)!=trump)
        {
            System.out.print("YES");
            return;
        }
        else if(card1.charAt(1)==card2.charAt(1))
        {
            int value1=0,value2=0;
            if(card1.charAt(0)>='0'&&card1.charAt(0)<='9')
                value1=card1.charAt(0)-'0';
            if(card2.charAt(0)>='0'&&card2.charAt(0)<='9')
                value2=card2.charAt(0)-'0';
            if(card1.charAt(0)=='T')
                value1=10;
            if(card2.charAt(0)=='T')
                value2=10;
            if(card1.charAt(0)=='J')
                value1=11;
            if(card2.charAt(0)=='J')
                value2=11;
            if(card1.charAt(0)=='Q')
                value1=12;
            if(card2.charAt(0)=='Q')
                value2=12;
            if(card1.charAt(0)=='K')
                value1=13;
            if(card2.charAt(0)=='K')
                value2=13;
            if(card1.charAt(0)=='A')
                value1=14;
            if(card2.charAt(0)=='A')
                value2=14;
            if(value1>value2)
                System.out.print("YES");
            else
                System.out.print("NO");
        }
        else
            System.out.print("NO");
    }
}