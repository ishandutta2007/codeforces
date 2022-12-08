import java.util.*;

public class memata {

    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        int[] v=new int[n];
        for(int i=0;i<n;i++)v[i]=scan.nextInt();
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(v[i]==v[j])v[j]=-1;
            }
        }
        int resp=0;
        for(int i=0;i<n;i++)if(v[i]!=-1)resp++;
        System.out.println(resp);
        for(int i=0;i<n;i++){
            if(v[i]!=-1)System.out.print(v[i]+" ");
        }
        System.out.println();
    }
}