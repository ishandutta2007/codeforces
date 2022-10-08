import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    class Pair implements Comparable<Pair> {
        int len;
        int id;
        public Pair(int len, int id) {
            this.len = len;
            this.id = id;
        }
        public int compareTo(Pair other) {
            return this.len - other.len;
        }
    }
    
    void main() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        
        int N = sc.nextInt();
        Pair[] data = new Pair[N];
        for (int i=0; i < N; i++) {
            int len = sc.nextInt();
            data[i] = new Pair(len, i);
        }
        
        sc.close();
        
        Arrays.sort(data);
        
        char[] cur = new char[1];
        cur[0] = '0';
        
        String[] res = new String[N];
        
        for (int i=0; i < N; i++) {
            while (cur.length < data[i].len) {
                char[] next = new char[cur.length + 1];
                for (int j=0; j < cur.length; j++)
                    next[j] = cur[j];
                next[next.length - 1] = '0';
                cur = next;
            }
            res[data[i].id] = new String(cur);
            
            if (i + 1 < N) {
                int pos = cur.length - 1;
                while (pos >= 0 && cur[pos] == '1') {
                    cur[pos] = '0';
                    pos--;
                }
                if (pos < 0) {
                    System.out.println("NO");
                    System.exit(0);
                }
                cur[pos] = '1';
            }
        }
        
        System.out.println("YES");
        for (int i=0; i < N; i++)
            System.out.println(res[i]);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).main();
    }
}