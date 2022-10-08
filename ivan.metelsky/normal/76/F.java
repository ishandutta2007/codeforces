import java.util.*;
import java.io.*;

public class CdfF {
    class Point implements Comparable<Point> {
        long x, t;
        long A, B;
        
        public Point(long x, long t) {
            this.x = x;
            this.t = t;
        }
        
        public int compareTo(Point other) {
            if (this.A != other.A)
                return (this.A < other.A ? -1 : 1);
            else
                return (this.B < other.B ? -1 : 1);
        }
    }
    
    Point[] pnt;
    long[] allB;
    long V;
    
    class Maximizer {
        int[] A;
        
        public Maximizer(int N) {
            this.A = new int[N + 1];
            Arrays.fill(A, -1000000000);
        }
        
        int getMax(int pos) {
            int res = -1000000000;
            while (pos > 0) {
                res = Math.max(res, A[pos]);
                pos = (pos & (pos - 1));
            }
            return res;
        }
        
        void update(int pos, int value) {
            while (pos < A.length) {
                A[pos] = Math.max(A[pos], value);
                pos = (pos | (pos - 1)) + 1;
            }
        }
    }
    
    int solve(boolean fixedStart) {
        Maximizer m = new Maximizer(pnt.length);
        int ans = 0;
        for (int i=0; i < pnt.length; i++) {
            int pos = Arrays.binarySearch(allB, pnt[i].B) + 1;
            int maxSoFar = m.getMax(pos);
            
            int newValue = maxSoFar + 1;
            
            if (fixedStart) {
                if (Math.abs(pnt[i].x) <= V * pnt[i].t)
                    newValue = Math.max(newValue, 1);
            } else {
                newValue = Math.max(newValue, 1);
            }
            
            ans = Math.max(ans, newValue);
            m.update(pos, newValue);
        }
        return ans;
    }
    
    public void go() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        pnt = new Point[N];
        for (int i=0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());
            pnt[i] = new Point(x, t);
        }
        V = Integer.parseInt(br.readLine());
        br.close();
        
        for (int i=0; i < N; i++) {
            pnt[i].A = V * pnt[i].t + pnt[i].x;
            pnt[i].B = V * pnt[i].t - pnt[i].x;
        }
        
        Arrays.sort(pnt);
        
        allB = new long[N];
        for (int i=0; i < N; i++)
            allB[i] = pnt[i].B;
        
        Arrays.sort(allB);
        
        System.out.println(solve(true) + " " + solve(false));
    }
    
    public static void main(String[] args) throws Exception {
        (new CdfF()).go();
    }
}