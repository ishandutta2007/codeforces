/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        while (t-- > 0) solve(sc);
	}
    public static void solve(Scanner sc) {
        String[] u = sc.nextLine().split(" ");
        int n = Integer.parseInt(u[0]);
        int k = Integer.parseInt(u[1]);
        String s = sc.nextLine();
        
        char[] t = {
        	'R', 'G', 'B'
        };
        int ans = (int)1e9;
        for (int i = 0; i<3;i++)
        {
        	int[] diff = new int[n+1];
        	for (int j = 0; j < n;j++) 
        	{
        		if (s.charAt(j)!= t[(j+i)%3]) diff[j +1]=1;
        		
        	}
        	Arrays.parallelPrefix(diff, Integer::sum);
        		for (int j=k;j<=n;j++)
        		   ans = Math.min(ans, diff[j]-diff[j-k]);
        }
        System.out.println(ans);

    }
}