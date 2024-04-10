//package cfed65;
import java.io.*;
import java.util.*;
 
 
public class G{
   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      // Start writing your solution here. -------------------------------------
   
      int t=sc.nextInt();
      for(int w=0;w<t;w++) {
    	  int n=sc.nextInt();
    	  char[]s=sc.nextLine().toCharArray();
    	  boolean b=false;
    	  for(int i=0;i<=s.length-11;i++)
    		  if(s[i]=='8')
    			  b=true;
    	  System.out.println(b?"YES":"NO");
      }

      // Stop writing your solution here. -------------------------------------
      out.close();
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