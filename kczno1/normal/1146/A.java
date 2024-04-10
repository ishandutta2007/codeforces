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
		int len=str.length(),cnt_a=0;
		for(int i=0;i<len;++i)
		if(str.charAt(i)=='a')++cnt_a;
		System.out.println(Math.min(cnt_a*2-1,len));	
    }
}