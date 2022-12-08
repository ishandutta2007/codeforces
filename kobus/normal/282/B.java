import java.util.Scanner;
public class c {
  public static void main(String[] args) {
      Scanner c = new Scanner(System.in);
      int n = c.nextInt();
      int[] a = new int[n];
      int[] g = new int[n];
      int valorTotalA = 0;
      int valorTotalG = 0;
      for (int i = 0; i < n; i++){
        int bala = c.nextInt();
        a[i] = bala;
        valorTotalA += bala;
        bala = c.nextInt();
        g[i] = bala;
        valorTotalG += bala;
      }
      int valorA = 0;
      int valorG = 0;
      char[] str = new char [n];
      for(int i = 0; i < n; i++){
        if (Math.abs(valorG + g[i] - valorA) >= Math.abs(valorA + a[i] - valorG)) {
          valorA += a[i];
          str[i] = 'A';
        }
        else {
          valorG += g[i];
          str[i] = 'G';
        }
      }
      if (Math.abs(valorA - valorG) > 500) System.out.println("-1");
      else {
        System.out.println(str);
      }
  }
}