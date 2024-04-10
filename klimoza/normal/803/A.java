import java.io.*;
import java.util.*;
import java.lang.*;

public class A {
    Scanner in;

    public static void main(String[] args) throws FileNotFoundException {
        new A().run();
    }

    public void run() throws FileNotFoundException {
        in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int[][] ar = new int[n][n];
        if(n*n >= k){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(k > 1){
                        if(i == j && ar[i][j] != 1){
                            ar[i][j] = 1;
                            k--;
                        } else if(i != j && ar[i][j] != 1){
                            ar[i][j] = 1;
                            ar[j][i] = 1;
                            k-=2;
                        }
                    } else {
                        if(k == 1){
                            int g = 0;
                            int h = 0;
                            while(ar[g][h] == 1){
                                g++;
                                h++;
                            }
                            ar[g][h] = 1;
                            k--;
                        }
                        break;
                    }

                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    System.out.print(ar[i][j] + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("-1");
        }

    }
}