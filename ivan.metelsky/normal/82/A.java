import java.util.*;
import java.io.*;

public class Solution {
    class Seq {
        String name;
        long count;
        public Seq(String name, long count) {
            this.name = name;
            this.count = count;
        }
    }
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        long n = sc.nextLong();
        List<Seq> q = new ArrayList<Seq>();
        q.add(new Seq("Sheldon", 1));
        q.add(new Seq("Leonard", 1));
        q.add(new Seq("Penny", 1));
        q.add(new Seq("Rajesh", 1));
        q.add(new Seq("Howard", 1));;
        while (true) {
            Seq cur = q.get(0);
            q.remove(0);
            if (n > cur.count) {
                n -= cur.count;
            } else {
                System.out.println(cur.name);
                break;
            }
            q.add(new Seq(cur.name, cur.count * 2));
        }
        sc.close();
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}