import java.util.*;
import java.io.*;

public class Solution {
    class Segment {
        long x1, y1, x2, y2;
        public Segment(BufferedReader br) throws Exception {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x1 = Long.parseLong(st.nextToken());
            y1 = Long.parseLong(st.nextToken());
            x2 = Long.parseLong(st.nextToken());
            y2 = Long.parseLong(st.nextToken());
        }
        void invert() throws Exception {
            long tmp = x1; x1 = x2; x2 = tmp;
            tmp = y1; y1 = y2; y2 = tmp;
        }
    }
    
    boolean belongs(long x, long y, Segment a) {
        long A = a.y2 - a.y1;
        long B = a.x1 - a.x2;
        long C = - a.x1 * A - a.y1 * B;
        if (A * x + B * y + C != 0) return false;
        if (x < Math.min(a.x1, a.x2) || x > Math.max(a.x1, a.x2)) return false;
        if (y < Math.min(a.y1, a.y2) || y > Math.max(a.y1, a.y2)) return false;
        return true;
    }
    
    long scalar(Segment a, Segment b) {
        long dx1 = a.x2 - a.x1;
        long dy1 = a.y2 - a.y1;
        long dx2 = b.x2 - b.x1;
        long dy2 = b.y2 - b.y1;
        return dx1 * dx2 + dy1 * dy2;
    }
    
    boolean goodDivision(long x, long y, Segment a) {
        long dist1 = (x - a.x1) * (x - a.x1) + (y - a.y1) * (y - a.y1);
        long dist2 = (x - a.x2) * (x - a.x2) + (y - a.y2) * (y - a.y2);
        if (dist1 > dist2) {long tmp=dist1; dist1=dist2; dist2=tmp;}
        return 16 * dist1 >= dist2;
    }
    
    boolean ok1(Segment a, Segment b, Segment c) {
        if (a.x1 != b.x1 || a.y1 != b.y1)
            return false;
        if (!belongs(c.x1, c.y1, a) || !belongs(c.x2, c.y2, b))
            return false;
        if (scalar(a, b) < 0)
            return false;
        if (!goodDivision(c.x1, c.y1, a) || !goodDivision(c.x2, c.y2, b))
            return false;
        return true;
    }
    
    boolean ok(Segment a, Segment b, Segment c) throws Exception {
        boolean res = false;
        for (int mask=0; mask<8; mask++) {
            if ((mask & 1) != 0) a.invert();
            if ((mask & 2) != 0) b.invert();
            if ((mask & 4) != 0) c.invert();
            res |= ok1(a, b, c);
            if ((mask & 1) != 0) a.invert();
            if ((mask & 2) != 0) b.invert();
            if ((mask & 4) != 0) c.invert();
        }
        return res;
    }
    
    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tCnt = Integer.parseInt(br.readLine());
        for (int tNum=0; tNum<tCnt; tNum++) {
            Segment a = new Segment(br);
            Segment b = new Segment(br);
            Segment c = new Segment(br);
            System.out.println(ok(a, b, c) || ok(a, c, b) || ok(b, c, a) ? "YES" : "NO");
        }
        br.close();
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}