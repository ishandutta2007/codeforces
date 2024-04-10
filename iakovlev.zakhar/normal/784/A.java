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
        int[] a = {4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985, 1086, 1111, 1165};
        output.print(a[n - 1]);
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