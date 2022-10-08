import java.util.*;

public class CDF22_D {
    class Segment implements Comparable<Segment> {
        int l, r;
        public Segment(int l, int r) {
            this.l = Math.min(l, r);
            this.r = Math.max(l, r);
        }
        boolean contains(Segment other) {
            return (l <= other.l && other.r <= r && (l != other.l || r != other.r));
        }
        boolean equals(Segment other) {
            return l == other.l && other.r == r;
        }
        boolean containsPoint(int x) {
            return l <= x && x <= r;
        }
        public int compareTo(Segment other) {
            return this.l - other.l;
        }
    }
    
    public void main() throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Segment[] data = new Segment[n];
        for (int i=0; i<n; i++) {
            data[i] = new Segment(sc.nextInt(), sc.nextInt());
        }
        List<Segment> segm = new ArrayList<Segment>();
        for (int i=0; i<n; i++) {
            boolean find = false;
            for (int j=0; j<i; j++)
                if (data[i].equals(data[j]) || data[i].contains(data[j]))
                    find = true;
            for (int j=i+1; j<n; j++)
                if (data[i].contains(data[j]))
                    find = true;
            if (!find) segm.add(data[i]);
        }
        Collections.sort(segm);
        int cur = segm.get(0).r;
        List<Integer> res = new ArrayList<Integer>();
        res.add(cur);
        for (int i=1; i < segm.size(); i++) {
            if (!segm.get(i).containsPoint(cur)) {
                cur = segm.get(i).r;
                res.add(cur);
            }
        }
        System.out.println(res.size());
        for (int x : res) {
            System.out.print(x + " ");
        }
        System.out.println();
        sc.close();
    }
    
    public static void main(String[] args) throws Exception {
        (new CDF22_D()).main();
    }
}