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
        String s = nextString();
        int th = 0;
        boolean plus = true;
        int x = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                if (plus) {
                    th += x;
                } else {
                    th -= x;
                }
                x = 0;
                if (s.charAt(i) == '+') {
                    plus = true;
                } else {
                    plus = false;
                }
            } else {
                x *= 10;
                x += (s.charAt(i) - '0');
            }
        }
        if (plus) {
            th += x;
        } else {
            th -= x;
        }
        s = Integer.toString(th);
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.charAt(i); j++) {
                output.print("+");
            }
            output.println(".>");
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