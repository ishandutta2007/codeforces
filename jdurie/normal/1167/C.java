//package cfed65;
import java.io.*;
import java.util.*;
 
 
public class C{
   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      // Start writing your solution here. -------------------------------------
   
      int n=sc.nextInt(),m=sc.nextInt();
      int[]parent=new int[n];
      for(int i=0;i<n;i++)
    	  parent[i]=i;
      int[]size=new int[n];
      for(int i=0;i<n;i++) 
    	  size[i]=1;
      for(int i=0;i<m;i++) {
    	  int g=sc.nextInt();
    	  int par=-1;
    	  HashSet<Integer>temp=new HashSet<Integer>();
    	  for(int j=0;j<g;j++) {
    		  int x=sc.nextInt()-1;
    		  if(parent[x]!=x||par==-1)
    			  par=x;
    		  temp.add(x);
    	  }
    	  for(int j:temp) 
    		  fillpar(j,par,parent,size);
      }
      for(int i=0;i<n;i++)
    	 out.print(size[finalpar(i,parent)]+" ");

      // Stop writing your solution here. -------------------------------------
      out.close();
   }
   
   private static void fillpar(int j,int par,int[]parent,int[]size) {
	   par=finalpar(par,parent);
	   if(finalpar(j,parent)!=par) {
			  if(j!=parent[j])
				  fillpar(parent[j],par,parent,size);
			  else {
				  size[par]+=size[j];
			  }
			  parent[j]=par;
	   }
   }
   
   private static int finalpar(int i,int[]parent) {
	   int iinit=i;
	   while(parent[i]!=i)
		   i=parent[i];
	   parent[iinit]=i;
	   return i;
   }

   //-----------PrintWriter for faster output---------------------------------
   public static PrintWriter out;
      
   //-----------MyScanner class for faster input----------
   public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
   //--------------------------------------------------------
}