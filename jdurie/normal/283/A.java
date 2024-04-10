import java.io.*;
import java.util.*;

public class Main {
    // ------------------------

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        // ------------------------
        Stack<Integer>stack=new Stack<Integer>();
        TreeMap<Integer,Integer>map=new TreeMap<Integer,Integer>();
        stack.push(0);
        long sum=0;
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            int t=sc.nextInt();
            if(t==1){
                int a=sc.nextInt(),x=sc.nextInt();
                map.put(a,x+(map.containsKey(a)?map.get(a):0));
                sum+=a*x;
            }else if(t==2){
                int k=sc.nextInt();
                stack.push(k);
                sum+=k;
            }else{
                if(map.containsKey(stack.size())){
                    int s=map.remove(stack.size());
                    sum-=s;
                    map.put(stack.size()-1,s+(map.containsKey(stack.size()-1)?map.get(stack.size()-1):0));
                }
                sum-=stack.pop();
            }
            out.println(sum/(double)stack.size());
        }
        // ------------------------
        out.close();
    }
    //------------------------

    public static PrintWriter out;
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
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}