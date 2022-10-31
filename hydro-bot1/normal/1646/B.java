// Hydro submission #624bd77767547adfa4541974@1649137527826
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author 
 * @data 2022/3/4 23:42
 */
public class Main {
    static class FastReader{
        StringTokenizer st;
        BufferedReader br;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while (st==null||!st.hasMoreElements()){
                try {
                    st=new StringTokenizer(br.readLine());
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static PrintWriter out = new PrintWriter(System.out);
    static FastReader in = new FastReader();
    static List<Integer> list;
    static void solve(){
        list=new ArrayList<>();
        int n=in.nextInt();
        for(int i=1;i<=n;i++){
            list.add(in.nextInt());
        }
        Collections.sort(list);
        long left=list.get(0)+list.get(1);
        long right=list.get(n-1);
        if(right>left) {
            out.println("YES");
            return;
        }
        int x=n-2;
        for(int i=2;i<=x;i++,x--){
            left=left+list.get(i);
            right=right+list.get(x);
            if(right>left) {
                out.println("YES");
                return;
            }
        }out.println("NO");
    }
    public static void main(String[] args) {
        int t=in.nextInt();
        while (t-->0){
            solve();
            out.flush();
        }
    }
}