//package cf567d2;
import java.io.*;
import java.util.*;

public class A {
    // ------------------------

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        // ------------------------
        long x=sc.nextLong(),y=sc.nextLong(),z=sc.nextLong(),xr=x%z,yr=y%z,ans=x/z+y/z;
        if(xr+yr>=z)
            System.out.println((ans+1)+" "+Math.min(z-xr,z-yr));
        else
            System.out.println(ans+" "+0);
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