import java.io.*;
import java.util.*;
public class Main
{
    public static void main (String[] args) throws IOException
    {
    	//System.out.println(args);
    	int DebugMode=0;
    	BufferedReader br;
    	if (DebugMode==1)
        br=new BufferedReader(new FileReader ("input.txt"));
    	else 
    	br = new BufferedReader (new InputStreamReader (System.in));
    	int e[][]=new int [200][];
    	for (int i=0; i<200; i++)
    		e[i]=new int[200]; 
    	String line=br.readLine();
    	StringTokenizer st=new StringTokenizer(line);
    	int n=Integer.parseInt(st.nextToken()), m=Integer.parseInt(st.nextToken());
    	for (int i=0; i<m; i++)
    	{
    		line=br.readLine();
        	st=new StringTokenizer(line);
        	int q=Integer.parseInt(st.nextToken()), w=Integer.parseInt(st.nextToken());
        	q--; w--;
        	e[q][w]=1;
        	e[w][q]=1;
    	}
    	int ans=0;
    	boolean done[]=new boolean[200];
    	for (int i=0; i<200; i++)
    		done[i]=false;
    	while (true)
    	{
    		int u=0;
    		int need[]=new int [200];
    		for (int i=0; i<n; i++)
    		if (!done[i])
    		{
    			int z=0;
    			for (int j=0; j<n; j++)
    				if (e[i][j]==1)
    				{
	    				if (!done[j])
	    					z++;
    				}
    			if (z==1)
    				need[u++]=i;
    		}
    		if (u==0)
    			break;
    		for (int i=0; i<u; i++)
    			done[need[i]]=true;
    		ans++;
    	}
    	System.out.println(ans);
    }
}