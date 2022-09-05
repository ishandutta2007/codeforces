import java.io.*;
import java.util.*;
import java.lang.*;
import java.awt.*;
import java.awt.geom.*;
import java.math.*;
import java.text.*;

public class A {
    public static void main(String []args) {
        Scanner sc = new Scanner(System.in);
		String str=sc.next();
		int len=str.length(),last_a=0,cnt_a=0;
		for(int i=0;i<len;++i)
		if(str.charAt(i)=='a'){last_a=i+1;++cnt_a;}
		int x=len-last_a-(last_a-cnt_a);
		if(!(x>=0&&x%2==0))System.out.println(":(");	
		else 
		{
			int i=0;
			for(int j=last_a+x/2;j<len;++j)
			{
				for(;str.charAt(i)=='a';++i);
				if(str.charAt(i)!=str.charAt(j))
				{
					System.out.println(":(");
					return ;
				}
				++i;
			}
			for(i=0;i<last_a+x/2;++i)
				System.out.print(str.charAt(i));	
		}
    }
}