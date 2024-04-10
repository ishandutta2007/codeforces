import java.util.*;
import java.math.*;
import java.io.*;
import java.lang.Math.*;



public class a{
    static int [] x=new int[251], y=new int[251], ans=new int[1000001];

    public static void main(String [] args) {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt(), m=in.nextInt();
        for (int i=0; i<m; i++) {
            x[i]=in.nextInt(); y[i]=in.nextInt();
        }
        for (int i=0; i<m; i++) {
            for (int j=i+1; j<m; j++) if (y[i]!=y[j] && 1l*(x[j]-x[i])*y[i]%(y[j]-y[i])==0) {
                long x0=x[i]-1l*(x[j]-x[i])*y[i]/(y[j]-y[i]);
                if (x0>=1 && x0<=n) {
                    int newans=0;
                    for (int k=0; k<m; k++) {
                        if (1l*(x[i]-x0)*(y[k])-1l*(x[k]-x0)*(y[i])==0l)
                            newans++;
                    }
                    ans[(int)x0]=Math.max(ans[(int)x0],newans);
                }
            }
        }
        int cans=0;
        for (int i=1; i<=n; i++) cans+=Math.max(1, ans[i]);
        System.out.println(cans);
        //for (int i=1; i<=n; i++)
        //    System.out.println(ans[i]);
    }
}