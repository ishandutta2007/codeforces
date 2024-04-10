import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;
 
import static java.lang.Math.*;
 
public class Main implements Runnable
{
	static class InputReader
	{
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		private BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		public InputReader(InputStream stream)
		{
			this.stream = stream;
		}
		
		public int read()
		{
			if (numChars==-1) 
				throw new InputMismatchException();
			
			if (curChar >= numChars)
			{
				curChar = 0;
				try 
				{
					numChars = stream.read(buf);
				}
				catch (IOException e)
				{
					throw new InputMismatchException();
				}
				
				if(numChars <= 0)				
					return -1;
			}
			return buf[curChar++];
		}
	 
		public String nextLine()
		{
			String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
		}
		public int nextInt()
		{
			int c = read();
			
			while(isSpaceChar(c)) 
				c = read();
			
			int sgn = 1;
			
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			
			int res = 0;
			do 
			{
				if(c<'0'||c>'9') 
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c)); 
			
			return res * sgn;
		}
		
		public long nextLong() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			long res = 0;
			
			do 
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c));
				return res * sgn;
		}
		
		public double nextDouble() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') 
			{
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) 
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
		
		public String readString() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do 
			{
				res.appendCodePoint(c);
				c = read();
			} 
			while (!isSpaceChar(c));
			
			return res.toString();
		}
	 
		public boolean isSpaceChar(int c) 
		{
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	 
		public String next() 
		{
			return readString();
		}
		
		public interface SpaceCharFilter 
		{
			public boolean isSpaceChar(int ch);
		}
	}
 	
	public static void main(String args[]) throws Exception
	{
		new Thread(null, new Main(),"Main",1<<26).start();
	}	
	int max(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    int min(int a,int b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
	public void run()
	{
		InputReader sc= new InputReader(System.in);
		PrintWriter w= new PrintWriter(System.out);
        int n=sc.nextInt();
	    int m=sc.nextInt();
        int k=sc.nextInt();
        int x[]=new int[k];
        int y[]=new int[k];
        for(int i=0;i<k;i++)
        {
            x[i]=sc.nextInt();
            y[i]=sc.nextInt();
        }
        int start=0,end=(int)1e9,ans=(int)1e9;
        while(start<=end)
        {
                //w.println(start+" "+end);
                int t=(start+end)/2;
                Event eventh[]=new Event[2*k+2];
                Event eventv[]=new Event[2*k+2];
                for(int i=0;i<k;i++)
                {
                    eventh[2*i]=new Event(i,max(x[i]-t,1),0);
                    eventh[2*i+1]=new Event(i,min(x[i]+t,n)+1,1);
                    eventv[2*i]=new Event(i,max(y[i]-t,1),0);
                    eventv[2*i+1]=new Event(i,min(y[i]+t,m)+1,1);
                }  
                eventh[2*k]=new Event(Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE);
                eventh[2*k+1]=new Event(Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE);
                eventv[2*k]=new Event(Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE);
                eventv[2*k+1]=new Event(Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE);
                Arrays.sort(eventh,new Comparator<Event>(){
                    public int compare(Event e1,Event e2)
                    {
                        if(e1.value>e2.value)
                            return 1;
                        if(e1.value<e2.value)
                            return -1;
                        if(e1.type==1&&e2.type==0)
                            return -1;
                        else if(e1.type==0&&e2.type==1)
                            return 1;
                        return 0;
                    }
                });  
                Arrays.sort(eventv,new Comparator<Event>(){
                    public int compare(Event e1,Event e2)
                    {
                        if(e1.value>e2.value)
                            return 1;
                        if(e1.value<e2.value)
                            return -1;
                        if(e1.type==1&&e2.type==0)
                            return -1;
                        else if(e1.type==0&&e2.type==1)
                            return 1;
                        return 0;
                    }
                });
                int active[]=new int[k];
                int x0=n+1,y0=m+1,cntx=0,cnty=0,flagx=0,flagy=0,lastx=1,lasty=1;
                for(int i=0;i<2*k&&flagx==0;i++)
                {
                    //for(int j=0;j<k;j++)
                        //w.print(active[j]+" ");
                    //w.println();
                    Event cur=eventh[i];
                    if(cntx==0&&cur.value!=lastx)
                    {
                        x0=lastx;
                        break;
                    }
                    flagy=0;
                    lasty=1;
                    cnty=0;
                    for(int j=0;j<2*k&&flagy==0;j++)
                    {
                        Event rec=eventv[j];
                        if(active[rec.index]==1)
                        {
                            //w.println(lasty);
                            if(cnty==0&&rec.value!=lasty)
                            {
                                flagy=1;
                                break;
                            }
                            if(rec.type==0)
                                cnty++;
                            else
                                cnty--;
                            lasty=rec.value;
                        }
                    }
                   // w.println("y: "+lasty);
                    if(cur.value!=lastx&&lasty!=m+1)
                        flagy=1;
                    if(flagy==1)
                    {
                        x0=lastx;
                        break;
                    }
                    if(cur.type==0)
                    {
                        active[cur.index]=1;
                        cntx++;
                    }
                    else
                    {
                        cntx--;
                        active[cur.index]=0;
                    }
                    lastx=cur.value;
                    i++;
                    while(i<2*k&&eventh[i].value==lastx)
                    {
                        cur=eventh[i];
                        if(cur.type==0)
                        {
                            active[cur.index]=1;
                            cntx++;
                        }
                        else
                        {
                            cntx--;
                            active[cur.index]=0;
                        }
                        i++;
                    }
                    i--;
                }
                if(lastx!=n+1)
                    x0=lastx;
                //w.println("x0 "+x0);
                cntx=0;
                cnty=0;
                flagx=0;
                flagy=0;
                lasty=1;
                for(int i=0;i<k;i++)
                    active[i]=0;
                for(int i=0;i<2*k&&flagy==0;i++)
                {
                    Event cur=eventv[i];
                    if(cnty==0&&cur.value!=lasty)
                    {
                        y0=lasty;
                        break;
                    }
                    flagx=0;
                    lastx=1;
                    cntx=0;
                    for(int j=0;j<2*k&&flagx==0;j++)
                    {
                        Event rec=eventh[j];
                        
                        if(active[rec.index]==1)
                        {
                            if(cntx==0&&rec.value!=lastx)
                            {
                                //if(t==0)
                                    //w.println(cur.index+" "+cur.value+" "+rec.index+" "+rec.value+" "+lastx);
                                flagx=1;
                                break;
                            }
                            if(rec.type==0)
                                cntx++;
                            else
                                cntx--;
                            lastx=rec.value;
                        }
                    }
                    if(cur.value!=lasty&&lastx!=n+1)
                    {
                        flagx=1;
                    }
                    if(flagx==1)
                    {
                        y0=lasty;
                        break;
                    }
                    if(cur.type==0)
                    {
                        active[cur.index]=1;
                        cnty++;
                    }
                    else
                    {
                        cnty--;
                        active[cur.index]=0;
                    }
                    lasty=cur.value;
                    i++;
                    while(i<2*k&&eventv[i].value==lasty)
                    {
                        cur=eventv[i];
                        if(cur.type==0)
                        {
                            active[cur.index]=1;
                            cnty++;
                        }
                        else
                        {
                            cnty--;
                            active[cur.index]=0;
                        }
                        i++;
                    }
                    i--;
                }
                if(lasty!=m+1)
                    y0=lasty;
                if(x0==n+1)
                {
                    ans=t;
                    end=t-1;
                }
                else
                {
                    //if(t==0)
                        //w.println(x0+" "+y0);
                    //if(t==3)
                     //w.println(x0+" "+y0);
                    eventh[2*k]=new Event(k,x0,0);
                    eventh[2*k+1]=new Event(k,min(x0+2*t,n)+1,1);
                    eventv[2*k]=new Event(k,y0,0);
                    eventv[2*k+1]=new Event(k,min(y0+2*t,m)+1,1);
                    Arrays.sort(eventh,new Comparator<Event>(){
                    public int compare(Event e1,Event e2)
                    {
                        if(e1.value>e2.value)
                            return 1;
                        if(e1.value<e2.value)
                            return -1;
                        if(e1.type==1&&e2.type==0)
                            return -1;
                        else if(e1.type==0&&e2.type==1)
                            return 1;
                        return 0;
                    }
                    });  
                    Arrays.sort(eventv,new Comparator<Event>(){
                        public int compare(Event e1,Event e2)
                        {
                            if(e1.value>e2.value)
                            return 1;
                            if(e1.value<e2.value)
                                return -1;
                            if(e1.type==1&&e2.type==0)
                                return -1;
                            else if(e1.type==0&&e2.type==1)
                                return 1;
                            return 0;
                        }
                    });
                    active=new int[k+1];
                    x0=n+1;
                    y0=m+1;
                    cntx=0;
                    cnty=0;
                    flagx=0;
                    flagy=0;
                    lastx=1;
                    for(int i=0;i<2*k+2&&flagx==0;i++)
                    {
                        Event cur=eventh[i];
                        if(cntx==0&&cur.value!=lastx)
                        {
                            x0=lastx;
                            break;
                        }
                        flagy=0;
                        lasty=1;
                        cnty=0;
                        for(int j=0;j<2*k+2&&flagy==0;j++)
                        {
                            Event rec=eventv[j];
                            if(active[rec.index]==1)
                            {
                                if(cnty==0&&rec.value!=lasty)
                                {
                                    flagy=1;
                                    break;
                                }
                                if(rec.type==0)
                                    cnty++;
                                else
                                    cnty--;
                                lasty=rec.value;
                            }
                        }
                        if(cur.value!=lastx&&lasty!=m+1)
                            flagy=1;
                        if(flagy==1)
                        {
                            x0=lastx;
                            break;
                        }
                        if(cur.type==0)
                        {
                            active[cur.index]=1;
                            cntx++;
                        }
                        else
                        {
                            cntx--;
                            active[cur.index]=0;
                        }
                        lastx=cur.value;
                        i++;
                        while(i<2*k+2&&eventh[i].value==lastx)
                        {
                            cur=eventh[i];
                            if(cur.type==0)
                            {
                                active[cur.index]=1;
                                cntx++;
                            }
                            else
                            {
                                cntx--;
                                active[cur.index]=0;
                            }
                            i++;
                        }
                        i--;
                    }
                    if(lastx!=n+1)
                        x0=lastx;
                    cntx=0;
                    cnty=0;
                    flagx=0;
                    flagy=0;
                    lasty=1;
                    for(int i=0;i<k+1;i++)
                        active[i]=0;
                    for(int i=0;i<2*k+2&&flagy==0;i++)
                    {
                        Event cur=eventv[i];
                        if(cnty==0&&cur.value!=lasty)
                        {
                            y0=lasty;
                            break;
                        }
                        flagx=0;
                        lastx=1;
                        cntx=0;
                        for(int j=0;j<2*k+2&&flagx==0;j++)
                        {
                            Event rec=eventh[j];
                            if(active[rec.index]==1)
                            {
                                if(cntx==0&&rec.value!=lastx)
                                {
                                    flagx=1;
                                    break;
                                }
                                if(rec.type==0)
                                    cntx++;
                                else
                                    cntx--;
                                lastx=rec.value;
                            }
                        }
                        if(cur.value!=lasty&&lastx!=n+1)
                            flagx=1;
                        if(flagx==1)
                        {
                            y0=lasty;
                            break;
                        }
                        if(cur.type==0)
                        {
                            active[cur.index]=1;
                            cnty++;
                        }
                        else
                        {
                            cnty--;
                            active[cur.index]=0;
                        }
                        lasty=cur.value;
                        i++;
                        while(i<2*k+2&&eventv[i].value==lasty)
                        {
                            cur=eventv[i];
                            if(cur.type==0)
                            {
                                active[cur.index]=1;
                                cnty++;
                            }
                            else
                            {
                                cnty--;
                                active[cur.index]=0;
                            }
                            i++;
                        }
                        i--;
                    }
                    if(lasty!=m+1)
                        y0=lasty;
                    if(x0==n+1)
                    {
                        ans=t;
                        end=t-1;
                    }
                    else
                        start=t+1;
                }
            }
        w.print(ans);
		w.close();		
	}
}
class Event
{
    int index;
    int value;
    int type;
    Event(int index,int value,int type)
    {
        this.index=index;
        this.value=value;
        this.type=type;
    }
}