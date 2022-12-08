import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class A {
    Scanner in;
    public static void main(String[] args){
        new A().run();
    }
    public void run(){
        in = new Scanner(System.in);
        int[] r1 = new int[4];
        int[] r2 = new int[4];
        int[] r3 = new int[4];
        int[] r4 = new int[4];
        for(int j = 0; j < 4; j++)
            r1[j]=in.nextInt();
        for(int j = 0; j < 4; j++)
            r2[j]=in.nextInt();
        for(int j = 0; j < 4; j++)
            r3[j]=in.nextInt();
        for(int j = 0; j < 4; j++)
            r4[j]=in.nextInt();
        while(true){
            if(r1[3] == 1){
                if(r1[1] + r1[0] + r1[2] + r2[0] + r3[1] + r4[2]!=0){
                    System.out.println("YES");
                    break;
                }
            }
            if(r2[3] == 1){
                if(r2[1] + r2[0] + r2[2] + r3[0] + r4[1] + r1[2]!=0){
                    System.out.println("YES");
                    break;
                }
            }
            if(r3[3] == 1){
                if(r3[1] + r3[0] + r3[2] + r4[0] + r1[1] + r2[2]!=0){
                    System.out.println("YES");
                    break;
                }
            }
            if(r4[3] == 1){
                if(r4[1] + r4[0] + r4[2] + r1[0] + r2[1] + r3[2]!=0){
                    System.out.println("YES");
                    break;
                }
            }
            System.out.println("NO");
            break;

        }




    }

}