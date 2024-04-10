import java.util.*;
import java.io.*;

public class Solution {
    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] a = new int[N];
        for (int i=0; i<N; i++)
            a[i] = Integer.parseInt(st.nextToken());
        
        int[] howMany = new int[N];
        int[] firstAfter = new int[N];
        int[] lastBefore = new int[N];
        
        for (int i=0; i<N; i++) {
            int x = i, where = x >> 8;
            int prev = -1;
            while (x < N && (x >> 8) == where) {
                howMany[i]++;
                prev = x;
                x += a[x];
            }
            lastBefore[i] = prev;
            firstAfter[i] = x;
        }
        
        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());
            int typ = Integer.parseInt(st.nextToken());
            if (typ==0) {
                int x = Integer.parseInt(st.nextToken()) - 1;
                a[x] = Integer.parseInt(st.nextToken());
                int where = x >> 8;
                for (int pos=(where<<8) + 255; pos >= (where<<8); pos--){
                    if (pos>=N) continue;
                    int next = pos + a[pos];
                    if (next >= N || (next>>8) > where) {
                        howMany[pos] = 1;
                        firstAfter[pos] = next;
                        lastBefore[pos] = pos;
                    } else {
                        howMany[pos] = howMany[next] + 1;
                        firstAfter[pos] = firstAfter[next];
                        lastBefore[pos] = lastBefore[next];
                    }
                }
            } else {
                int x = Integer.parseInt(st.nextToken()) - 1;
                int tot = 0, last = -1;
                while (x < N) {
                    tot += howMany[x];
                    last = lastBefore[x];
                    x = firstAfter[x];
                }
                System.out.println((last+1) + " " + tot);
            }
        }
        
        br.close();
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}