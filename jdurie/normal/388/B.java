import java.util.*;
public class FoxMinimalPath{
    private static boolean[][]grid;
    public static void main(String[]args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int l = (int) (Math.log(k) / Math.log(2));
        int n = 2 + 2 * l;
        for (int i = 0; i <= l; i++) {
            if (k / (int) Math.pow(2, i) % 2 == 1)
                n += l - i;
        }
        grid=new boolean[n][n];
        int lastA=0,lastB=0,ind=2;
        for(int i=0;i<l;i++){
            for(int c=0;c<2;c++) {
                connect(ind,lastA);
                connect(ind,lastB);
                ind++;
            }
            lastA=ind-2;
            lastB=ind-1;
        }
        connect(lastA,1);
        connect(lastB,1);
        for(int i=0;i<l;i++)
            if(k / (int) Math.pow(2, i) % 2 == 1){
                connect(ind,2*i);
                if(i>0)
                    connect(ind,2*i+1);
                for(int j=i;j<l-1;j++)
                    connect(++ind,ind-1);
                connect(ind++,1);
            }
        System.out.println(n);
        for(boolean[]arr:grid) {
            for (boolean b : arr)
                System.out.print(b ? "Y" : "N");
            System.out.println();
        }
    }
    public static void connect(int a,int b){
        grid[a][b]=true;
        grid[b][a]=true;
    }
}