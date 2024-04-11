/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scan=new Scanner(System.in);
        int n = scan.nextInt();
        if (n % 2 == 1) {
        	System.out.print("7");
        } else {
        	System.out.print("1");
        }
        n -= 2;
        for (int i = 0; i < n / 2; i++)
        	System.out.print("1");
	}
}