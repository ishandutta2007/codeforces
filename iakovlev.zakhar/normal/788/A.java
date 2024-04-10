import java.io.*;
import java.math.*;
import java.util.*;


public class Main {
    
    public BufferedReader input;
    public PrintWriter output;
    public StringTokenizer stoken = new StringTokenizer("");
    
    public static void main(String[] args) throws IOException {
        new Main();
    }
    
    Main() throws IOException{
        input = new BufferedReader(
                  new InputStreamReader(System.in)
        );
        output = new PrintWriter(System.out);
        int n = nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
        }
        long[] zer = new long[n];
        for (int i = 0; i < n - 1; i+= 2) {
            if (i == 0) {
                zer[0] = zer[1] = Math.abs(a[1] - a[0]);
            } else {
                zer[i] = zer[i + 1] = Math.abs(a[i + 1] - a[i]) + zer[i - 1];
            }
        }
        long[] one = new long[n];
        for (int i = 1; i < n - 1; i+= 2) {
            if (i == 1) {
                one[1] = one[2] = Math.abs(a[2] - a[1]);
            } else {
                one[i] = one[i + 1] = Math.abs(a[i + 1] - a[i]) + one[i - 1];
            }
        }
        long[] bz = new long[n];
        long[] bo = new long[n];
        for (int i = 1; i < n; i ++) {
            bz[i] = zer[i - 1] - one[i - 1];
        }
        for (int i = 2; i < n; i++) {
            bo[i] = one[i - 1] - zer[i - 1] + zer[0];
        }
        long[] minBz = new long[n];
        long[] minBo = new long[n];
        for (int i = 1; i < n; i++) {
            minBz[i] = Math.min(minBz[i - 1], bz[i]);
            minBo[i] = Math.min(minBo[i - 1], bo[i]);
        }
        long ans = 0;
        for (int i = 1; i < n; i++) {
            ans = Math.max(ans, bz[i] - minBz[i - 1]);
            ans = Math.max(ans, bo[i] - minBo[i - 1]);
        }
        output.println(ans);
        input.close();
        output.close();
    }

    private Long nextLong() throws NumberFormatException, IOException {
        return Long.parseLong(nextString());
    }
    
    private int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(nextString());
    }

    private String nextString() throws IOException {
        while (!stoken.hasMoreTokens()){
            String st = input.readLine();
            stoken = new StringTokenizer(st);
        }
        return stoken.nextToken();
    }
    
    
}