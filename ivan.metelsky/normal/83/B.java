import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    List<Integer> solve(long[] a, long k) {
        int n = a.length;
        
        long sum = 0;
        for (int i=0; i < n; i++)
            sum += a[i];
        
        if (sum < k)
            return null;
        
        if (sum == k)
            return new ArrayList<Integer>();
        
        long[] b = a.clone();
        Arrays.sort(b);
        
        long curH = 0, skip = -1;
        long wasH = 0;
        for (int i=0; i < n; i++) {
            long tot = (b[i] - curH) * (n - i);
            if (tot <= k) {
                curH = b[i];
                k -= tot;
            } else {
                wasH = curH;
                curH += k / (n - i);
                skip = k % (n - i);
//              if (skip == 0) curH--;
                break;
            }
        }
        
        int pos = 0;
        while (a[pos] <= wasH || skip > 0) {
            if (a[pos] > wasH) skip--;
            pos++;
        }
        
        List<Integer> res = new ArrayList<Integer>();
        for (int i=pos; i < n; i++)
            if (a[i] > curH) res.add(i);
        for (int i=0; i < pos; i++)
            if (a[i] > curH + 1) res.add(i);
        
        return res;
    }
    
    class Pair {
        int id;
        long left;
        public Pair(int id, long left) {
            this.id = id;
            this.left = left;
        }
    }
    
    List<Integer> bruteForce(long[] a, long k) {
        int n = a.length;
        long sum = 0;
        for (int i=0; i < n; i++)
            sum += a[i];
        
        if (sum < k)
            return null;

        List<Pair> q = new ArrayList<Pair>();
        for (int i=0; i < n; i++)
            q.add(new Pair(i, a[i]));
        
        while (k > 0) {
            Pair p = q.get(0);
            q.remove(0);
            if (p.left > 1) q.add(new Pair(p.id, p.left-1));
            k--;
        }
        
        List<Integer> res = new ArrayList<Integer>();
        for (Pair p : q)
            res.add(p.id);
        return res;
    }
    
    public void go() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        long[] a = new long[n];
        st = new StringTokenizer(br.readLine());
        for (int i=0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        br.close();
        List<Integer> res = solve(a, k);
        if (res == null) {
            System.out.println(-1);
            System.exit(0);
        }
        for (int i=0; i < res.size(); i++) {
            System.out.print(res.get(i) + 1);
            if (i+1 < res.size()) System.out.print(" ");
        }
        System.out.println();
    }
    
    static boolean equal(List<Integer> a, List<Integer> b) {
        if (a == null) return b == null;
        if (b == null) return a == null;
        if (a.size() != b.size()) return false;
        for (int i=0; i < a.size(); i++)
            if (a.get(i) != b.get(i)) return false;
        return true;
    }
    
    public static void main(String[] args) throws Exception {
//      int it = 0;
//      Random rnd = new Random();
//      while (true) {
//          it++;
//          if (it%1000==0) System.out.println(it);
//          
//          int n = rnd.nextInt(10)+1;
//          int k = rnd.nextInt(101);
//          long[] a = new long[n];
//          int max = rnd.nextInt(10)+1;
//          for (int i=0; i < n; i++)
//              a[i] = rnd.nextInt(max)+1;
//          
//          List<Integer> l1 = new Solution().bruteForce(a.clone(), k);
//          List<Integer> l2 = new Solution().solve(a.clone(), k);
//
//          if (!equal(l1, l2)) {
//              System.out.println("case found");
//              System.exit(0);
//          }
//      }
        (new Solution()).go();
    }
}