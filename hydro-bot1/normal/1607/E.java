// Hydro submission #62c56285c3a9fda5622969a1@1657102982467
import java.io.*;
import java.util.*;

public class E1607 {
  static String s;
  static int N, M, L;
  public static void main(String[] args) throws IOException, FileNotFoundException {
    Kattio in = new Kattio();

    int T = in.nextInt();
    while(T > 0){
      N = in.nextInt();
      M = in.nextInt();

      s = in.next();
      L = s.length();

      int a = 0;
      int b = L;
      while(a != b){
        int mid = (a + b + 1)/2;
        if(works(mid)){
          a = mid;
        } else {
          b = mid - 1;
        }
      }

      int left = calculateMaximum('L', 'R', a);
      int right = calculateMaximum('R', 'L', a);
      int up = calculateMaximum('U', 'D', a);
      int down = calculateMaximum('D', 'U', a);

      System.out.println((1 + up) + " " + (1 + left));

      T--;
    }
  }

  public static boolean works(int last){
    int left = calculateMaximum('L', 'R', last);
    int right = calculateMaximum('R', 'L', last);
    int up = calculateMaximum('U', 'D', last);
    int down = calculateMaximum('D', 'U', last);
    int minLeft = 1 + left;
    int maxRight = M - right;
    int minUp = 1 + up;
    int maxDown = N - down;

    if(minLeft <= maxRight && minUp <= maxDown){
      return true;
    }

    return false;
  }

  public static int calculateMaximum(char direction, char opposite, int last){
    int max = 0;
    int curr = 0;
    for(int i = 0; i < last; i++){
      if(s.charAt(i) == direction){
        curr++;
      } else if (s.charAt(i) == opposite) {
        curr--;
      }
      max = Math.max(max, curr);
    }
    return max;
  }

  static class Kattio extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;
    public Kattio() { this(System.in, System.out); }
    public Kattio(InputStream i, OutputStream o) {
      super(o);
      r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(String problemName) throws IOException {
      super(problemName + ".out");
      r = new BufferedReader(new FileReader(problemName + ".in"));
    }
    public String next() {
      try {
        while (st == null || !st.hasMoreTokens())
          st = new StringTokenizer(r.readLine());
        return st.nextToken();
      } catch (Exception e) { }
      return null;
    }
    public int nextInt() { return Integer.parseInt(next()); }
    public double nextDouble() { return Double.parseDouble(next()); }
    public long nextLong() { return Long.parseLong(next()); }
  }
}