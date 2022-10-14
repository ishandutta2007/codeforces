//package cf567d2;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {
    // ------------------------
    private static BigInteger s;
    private static int l;
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        // ------------------------
        l=sc.nextInt();
        String str=sc.nextLine();
        s=new BigInteger(str);
        int left=l/2,right=(l+1)/2;
        while(str.charAt(left)=='0')
            left--;
        while(right<l&&str.charAt(right)=='0')
            right++;
        if(right==l)
            out.println(getSum(left));
        else
            out.println(getSum(left).min(getSum(right)));
        // ------------------------
        out.close();
    }
    //------------------------
    private static BigInteger getSum(int i){
        BigInteger x=BigInteger.TEN.pow(l-i);
        return s.divide(x).add(s.mod(x));
    }
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