import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    InputStreamReader inp = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(inp);
    Scanner sc = new Scanner(inp);
    
    class Point implements Comparable<Point> {
        public int x, y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int compareTo(Point other) {
            if (this.x != other.x) return this.x - other.x;
            return this.y - other.y;
        }
        public boolean equals(Object other) {
            Point oth = (Point)other;
            return this.x == oth.x && this.y == oth.y;
        }
        public int hashCode() {
            return this.x * 3274336 + this.y * 6754352;
        }
    }
    
    // input data
    int n;
    Point[] pnt;
    
    void inputData() throws Exception {
        n = Integer.parseInt(br.readLine());
        pnt = new Point[n];
        for (int i=0; i<n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            pnt[i] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
    }

    // intermediate
    
    HashSet<Point> res = new HashSet<Point>();
    
    void go(int l, int r) {
        if (l == r)
            return;
        int mid = (l + r) / 2;
        for (int i=l; i <= r; i++)
            res.add(new Point(pnt[mid].x, pnt[i].y));
        int pos = mid;
        while (pos > l && pnt[pos].x == pnt[mid].x)
            pos--;
        go(l, pos);
        pos = mid+1;
        while (pos < r && pnt[pos].x == pnt[mid].x)
            pos++;
        go(pos, r);
    }
    
    void solve() {
        Arrays.sort(pnt);
        for (Point p : pnt) res.add(p);
        go(0, n-1);
    }
    
    // output data
    
    void writeData() {
        System.out.println(res.size());
        for (Point p : res) System.out.println(p.x+" "+p.y);
    }
        
    // ================================================== //
    
    void solveAlternative() {
    }
    
    // ================================================== //
    
    static void solveTask() throws Exception {
        Solution sol = new Solution();
        sol.inputData();
        sol.solve();
        sol.writeData();
    }
    
    static void stressTest() {
        Random rnd = new Random();
        int it = 0;
        while (true) {
            it++;
            System.out.println("testing case #" + it);
            
            Solution sol = new Solution();
            
            // generate test case
            
            Solution sol1 = new Solution();
            
            // copy test case
            
            sol.solve();
            sol1.solveAlternative();
            
            // compare answers
        }
    }
    
    public static void main(String[] args) throws Exception {
        solveTask();
        // stressTest()
    }
}