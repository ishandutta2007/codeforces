import java.io.*;
import java.util.*;
public class Main{
   public static void main(String[] args){
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      // Start writing your solution here. -------------------------------------

      int n=sc.nextInt(),m=sc.nextInt();
		int[][]grid=new int[m][m];
		for(int r=0;r<n;r++){
			char[]line=sc.nextLine().toCharArray();
			for(int c=0;c<m;c++){
				if(line[c]=='1'){
					int s=c;
					while(++c<m&&line[c]=='1'){}
					grid[s][c-1]++;
				}
			}
		}
		for(int i=0;i<m;i++)
			for(int j=m-2;j>=i;j--)
				grid[i][j]+=grid[i][j+1];
		for(int i=1;i<m;i++)
			for(int j=i;j<m;j++)
				grid[i][j]+=grid[i-1][j];
		int max=0;
		for(int i=0;i<m;i++)
			for(int j=i;j<m;j++)
				max=Math.max(max,grid[i][j]*(j-i+1));
		System.out.println(max);
      
      // Stop writing your solution here. -------------------------------------
      out.close();
   }
   //-----------PrintWriter for faster output---------------------------------
   public static PrintWriter out;
   //-----------MyScanner class for faster input----------
   public static class MyScanner{
      BufferedReader br;
      StringTokenizer st;
      public MyScanner(){
         br = new BufferedReader(new InputStreamReader(System.in));
      }
      String next(){
          while(st==null||!st.hasMoreElements()){
              try{
                  st = new StringTokenizer(br.readLine());
              }catch(IOException e){
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
      int nextInt(){
          return Integer.parseInt(next());
      }
      long nextLong(){
          return Long.parseLong(next());
      }
      double nextDouble(){
          return Double.parseDouble(next());
      }
      String nextLine(){
          String str="";
          try{
        	  str=br.readLine();
          }catch(IOException e){
        	  e.printStackTrace();
          }
          return str;
      }
   }
}