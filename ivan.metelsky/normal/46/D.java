import java.util.*;
import java.io.*;

public class Solution {
    class Segment {
        int st, fn;
        int orderId;
        public Segment(int st, int fn, int orderId) {
            this.st = st;
            this.fn = fn;
            this.orderId = orderId;
        }
    }
    
    int L, b, f, n;
    List<Segment> segments;
    
    boolean canParkAt(int len, int st) {
        if (st + len > L)
            return false;
        
        int left = st - b;
        int right = st + len + f;
        
        for (Segment segm : segments) {
            int ll = Math.max(segm.st, left);
            int rr = Math.min(segm.fn, right);
            if (ll < rr)
                return false;
        }
        
        return true;
    }
    
    public void doMain() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        L = sc.nextInt();
        b = sc.nextInt();
        f = sc.nextInt();
        n = sc.nextInt();
        segments = new ArrayList<Segment>();
        
        for (int i=0; i < n; i++) {
            int qt = sc.nextInt();
            if (qt == 1) {
                int len = sc.nextInt();
                int bPos = Integer.MAX_VALUE;
                if (canParkAt(len, 0))
                    bPos = 0;
                for (Segment segm : segments)
                    if (canParkAt(len, segm.fn + b))
                        bPos = Math.min(bPos, segm.fn + b);
                if (bPos == Integer.MAX_VALUE)
                    System.out.println(-1);
                else {
                    System.out.println(bPos);
                    segments.add(new Segment(bPos, bPos + len, i + 1));
                }
            } else {
                int id = sc.nextInt();
                for (int pos=0; pos < segments.size(); pos++)
                    if (segments.get(pos).orderId == id) {
                        segments.remove(pos);
                        break;
                    }
            }
        }
        
        sc.close();
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}