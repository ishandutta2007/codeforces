import java.io.*;
import java.util.*;
 
 
public class Main{
   public static void main(String[] args) {
      MyScanner sc = new MyScanner();
      out = new PrintWriter(new BufferedOutputStream(System.out));
      
      // Start writing your solution here. -------------------------------------
   
     int n=sc.nextInt();
		TreeMap<Integer,Integer>primeMap=new TreeMap<Integer,Integer>();
		for(int i=2;i<2750132;i++){
			boolean prime=true;
			for(int j:primeMap.keySet()){
				if(i%j==0){
					prime=false;
					break;
				}
				if(j>Math.sqrt(i))
					break;
			}
			if(prime)
				primeMap.put(i,primeMap.size()+1);
		}
		TreeMap<Integer,Integer>set=new TreeMap<Integer,Integer>();
		for(int i=0;i<2*n;i++){
			int x=sc.nextInt();
			set.put(x,set.containsKey(x)?set.get(x)+1:1);
		}
		while(!set.isEmpty()){
			int m=set.get(set.lastKey()),x=set.pollLastEntry().getKey();
			if(primeMap.containsKey(x)){
				int z=primeMap.get(x);
				for(int i=0;i<m;i++)
					out.print(z+" ");
				remove(set,z,m);
			}else{
				for(int i=0;i<m;i++)
					out.print(x+" ");
				remove(set,bigFactor(x),m);
			}
		}
		out.println();

      // Stop writing your solution here. -------------------------------------
      out.close();
   }

     private static void remove(TreeMap<Integer,Integer>set,int y,int size){
		set.put(y,set.get(y)-size);
		if(set.get(y)==0)
			set.remove(y);
	}
	private static int bigFactor(int x){
		for(int i=2;i<=x;i++)
			if(x%i==0)
				return x/i;
		return -1235;
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