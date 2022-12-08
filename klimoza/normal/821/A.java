    import java.io.*;
    import java.math.BigInteger;
    import java.util.*;
    public class B{
        Scanner in;
        public static void main(String[] args){
            new B().run();
        }
        public void run() {
            in = new Scanner(System.in);
            int n  = in.nextInt();
            int[][] ar = new int[n][n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    ar[i][j] = in.nextInt();
                }
            }
            boolean bl = true;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    boolean[] arch = new boolean[100000];
                    if(ar[i][j]!=1){
                        int f = 0;
                        for(int t = 0; t < n; t++){
                            if(t != j && !arch[ar[i][t]]){
                                if(ar[i][j] <= ar[i][t] || !checkStolbik(ar,j,ar[i][j] - ar[i][t], n)){
                                    f++;
                                } else{
                                    break;
                                }
                            }
                            if(f == n-1){
                                bl = false;
                                break;
                            }
                        }
                    }
                    if(!bl){
                        break;
                    }
                }
                if(!bl){
                    break;
                }
            }
            if(bl){
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
        public boolean checkStolbik(int[][] ar, int t, int h, int n){
            for(int i = 0; i < n; i++){
                if(ar[i][t] == h){
                    return true;
                }
            }
            return false;
        }
    }