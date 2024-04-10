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
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        long j = 0;
        while (true) {
            j++;
            if (j == 1000000000L) {
                break;
            }
        }
        Arrays.sort(a);
        for (int i = 0; i < n; i++) {
            output.print(a[i] + " ");
        }
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