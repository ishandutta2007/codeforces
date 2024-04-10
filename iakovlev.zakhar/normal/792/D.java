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
        long n = nextLong();
        int q = nextInt();
        long root = (n + 1) / 2;
        ArrayList<Long> pow = new ArrayList<>();
        pow.add(0L);
        pow.add(1L);
        while (pow.get(pow.size() - 1) * 2 < root) {
            pow.add(pow.get(pow.size() - 1) * 2);
        }
        for (int u = 0; u < q; u++) {
            long v = nextLong();
            String s = nextString();
            Stack<Long> st = new Stack<>();
            long th = root;
            int i = pow.size() - 1;
            while (th != v) {
                st.push(th);
                if (v < th) {
                    th -= pow.get(i);
                } else {
                    th += pow.get(i);
                }
                i--;
            }
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == 'U') {
                    if (th == root) {
                        continue;
                    } else {
                        i++;
                        th = st.pop();
                    }
                } else {
                    if (th % 2 == 1) {
                        continue;
                    } else if (s.charAt(j) == 'L') {
                        st.add(th);
                        th -= pow.get(i);
                        i--;
                    } else {
                        st.add(th);
                        th += pow.get(i);
                        i--;
                    }
                }
            }
            output.println(th);
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