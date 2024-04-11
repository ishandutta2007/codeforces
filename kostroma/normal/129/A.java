import java.math.BigInteger;
import java.io.*;
import java.util.*;
public class Main
{
    public static void main (String[] args) throws IOException
    {
    	int DebugMode=0;
    	BufferedReader br;
    	if (DebugMode==1)
        br=new BufferedReader(new FileReader ("input.txt"));
    	else 
    	br = new BufferedReader (new InputStreamReader (System.in));
        BigInteger a, sum=BigInteger.ZERO;
        String line=br.readLine();
        StringTokenizer st=new StringTokenizer (line);
        int n=Integer.parseInt(line);
        int u=0;
        line=br.readLine();
        st=new StringTokenizer (line);
        for (int i=0; i<n; i++)
        {
        a=new BigInteger ( st.nextToken() );
        BigInteger z=BigInteger.ONE.add(BigInteger.ONE);
        BigInteger c=a.gcd(z);
        if ( c.equals(BigInteger.ONE) )
            u++;
        //System.out.println(z);
        sum=sum.add(a);
        }
       BigInteger g=sum.gcd(BigInteger.ONE.add(BigInteger.ONE));
       if (g.equals(BigInteger.ONE))
            System.out.println(u);
       else 
             System.out.println(n-u);
    }
}