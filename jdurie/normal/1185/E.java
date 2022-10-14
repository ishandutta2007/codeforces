//package cf568d2;
import java.util.*;
public class E {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int w=0;w<t;w++){
            boolean[]cont=new boolean[26];
            boolean ok=true;
            int n=sc.nextInt(),m=sc.nextInt();
            sc.nextLine();
            char[][]grid=new char[n][m];
            LinkedList<String>snakes=new LinkedList<String>();
            for(int i=0;i<n;i++) {
                grid[i]=sc.nextLine().toCharArray();
                for(int j=0;j<m;j++)
                    if(grid[i][j]-'a'>=0&&grid[i][j]-'a'<26)
                        cont[grid[i][j]-'a']=true;
            }
            int let=25;
            while(let>=0&&!cont[let])
                let--;
            for(int l=let;l>=0;l--){
                if(ok) {
                    TreeSet<Integer> rows = new TreeSet<Integer>(), cols = new TreeSet<Integer>();
                    for (int i = 0; i < n; i++)
                        for (int j = 0; j < m; j++)
                            if (grid[i][j] == l + 'a') {
                                rows.add(i);
                                cols.add(j);
                            }
                    if (rows.size() == 1) {
                        int start = cols.first(), end = cols.last(), row = rows.first();
                        for (int j = start; j <= end; j++) {
                            if (grid[row][j] - 'a' < l || grid[row][j] - 'a' >= 26)
                                ok = false;
                        }
                        snakes.addFirst((row+1)+" "+(start+1)+" "+(row+1)+" "+(end+1));
                    } else if(cols.size()==1){
                        int start = rows.first(), end = rows.last(), col = cols.first();
                        for (int i = start; i <= end; i++) {
                            if (grid[i][col] - 'a' < l || grid[i][col] - 'a' >= 26)
                                ok = false;
                        }
                        snakes.addFirst((start+1)+" "+(col+1)+" "+(end+1)+" "+(col+1));
                    } else if(rows.isEmpty()&&cols.isEmpty())
                        snakes.addFirst(snakes.getFirst());
                    else
                        ok=false;
                }
            }
            System.out.println(ok?"YES":"NO");
            if(ok){
                System.out.println(snakes.size());
                for(String s:snakes)
                    System.out.println(s);
            }
        }
    }
}