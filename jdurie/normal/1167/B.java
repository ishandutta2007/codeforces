//package cfed65;
import java.io.*;
import java.util.*;
 
 
public class B{
   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      // Start writing your solution here. -------------------------------------
   
      System.out.println("? 1 2");
      System.out.flush();
      int[]onetwo=getNums(sc.nextInt());
      System.out.println("? 2 3");
      System.out.flush();
      int[]twothree=getNums(sc.nextInt());
      System.out.println("? 4 5");
      System.out.flush();
      int[]fourfive=getNums(sc.nextInt());
      System.out.println("? 5 6");
      System.out.flush();
      int[]fivesix=getNums(sc.nextInt());
      System.out.print("! ");
      print(onetwo,twothree);
      System.out.print(" ");
      print(fourfive,fivesix);
      System.out.println();
      System.out.flush();
      // Stop writing your solution here. -------------------------------------
      out.close();
   }

   private static int[]getNums(int x){
	   int[]arr= {4,8,15,16,23,42};
	   for(int i:arr)
		   for(int j:arr)
			   if(i*j==x&&i!=j)
				   return new int[]{i,j};
	   return new int[]{-1};
   }
   private static void print(int[]one,int[]two) {
	   if(one[0]==two[0])
		   System.out.print(one[1]+" "+one[0]+" "+two[1]);
	   else if(one[0]==two[1])
		   System.out.print(one[1]+" "+one[0]+" "+two[0]);
	   else if(one[1]==two[0])
		   System.out.print(one[0]+" "+one[1]+" "+two[1]);
	   else if(one[1]==two[1])
		   System.out.print(one[0]+" "+one[1]+" "+two[0]);
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