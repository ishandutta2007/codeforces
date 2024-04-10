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
        int k = nextInt();
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(i + 1);
        }
        int[] del = new int[k];
        for (int i = 0; i < k; i++) {
            del[i] = nextInt();
        }
        int j = 0;
        for (int i = 0; i < k; i++) {
            j += del[i];
            j %= a.size();
            output.print(a.get(j) + " ");
            a.remove(j);
            j %= a.size();
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