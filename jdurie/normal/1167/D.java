//package cfed65;
import java.io.*;
import java.util.*;
 
 
public class D{
   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      // Start writing your solution here. -------------------------------------
   
      int n=sc.nextInt();
      char[]s=sc.nextLine().toCharArray();
      int ct0=0,ct1=0;
      for(int i=0;i<n;i++) {
    	  if(s[i]=='(') {
    		  if(ct0>=ct1) {
    			  out.print(1);
    			  ct1++;
    		  }else {
    			  out.print(0);
    			  ct0++;
    		  }
    	  }else {
    		  if(ct0>=ct1) {
    			  out.print(0);
    			  ct0--;
    		  }else {
    			  out.print(1);
    			  ct1--;
    		  }
    	  }
      }
      out.println();
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