import java.io.*;
import java.util.*;
 
 
public class E{
    private static  HashMap<Integer,HashSet<Integer>>graph;
    private static HashSet<Integer>one,two;
    public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      // Start writing your solution here. -------------------------------------
    int q=sc.nextInt();
    for(int w=0;w<q;w++){
        graph=new HashMap<Integer,HashSet<Integer>>();
        one=new HashSet<Integer>();
        two=new HashSet<Integer>();
      int n=sc.nextInt(),m=sc.nextInt();
      for(int i=1;i<=n;i++)
          graph.put(i,new HashSet<Integer>());
      for(int i=0;i<m;i++){
          int a=sc.nextInt(),b=sc.nextInt();
          graph.get(a).add(b);
          graph.get(b).add(a);
      }
        fill(1,true);
        if(two.size()>one.size()){
            out.println(one.size());
            for(int x:one)
                out.print(x+" ");
            out.println();
        }else{
            out.println(two.size());
            for(int x:two)
                out.print(x+" ");
            out.println();
        }
    }
      // Stop writing your solution here. -------------------------------------
      out.close();
   }

    private static void fill(int x,boolean o){
        if(!one.contains(x)&&!two.contains(x)){
            if(o)
                one.add(x);
            else
                two.add(x);
            for(int y:graph.get(x))
                fill(y,!o);
        }
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