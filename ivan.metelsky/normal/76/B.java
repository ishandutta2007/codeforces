import java.util.*;
import java.io.*;

public class Solution {
    boolean contains(int[] a, int value) {
        for (int x : a) if (value == x) return true;
        return false;
    }
    
    int count(List<Integer> pos, int mid, int[] except) {
        int minDist = 1000000000;
        int cnt = 0;
        for (int p : pos) {
            if (contains(except, p))
                continue;
            int dist = Math.abs(p - mid);
            if (dist < minDist) {
                minDist = dist;
                cnt = 1;
            } else if (dist == minDist)
                cnt++;
        }
        return cnt;
    }
    
    public void go() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int ML = Integer.parseInt(st.nextToken());
        int CL = Integer.parseInt(st.nextToken());
        int Y0 = Integer.parseInt(st.nextToken());
        int Y1 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] MX = new int[ML];
        for (int i=0; i < ML; i++)
            MX[i] = Integer.parseInt(st.nextToken());
        if (CL > 0)
            st = new StringTokenizer(br.readLine());
        int[] CX = new int[CL];
        for (int i=0; i < CL; i++)
            CX[i] = Integer.parseInt(st.nextToken());
        br.close();
        
        if (CL == 0) {
            System.out.println(ML);
            System.exit(0);
        }
        
        final int INF = 1000000000;

        // A -- leftmost mouse not assigned
        // B -- leftmost mouse assigned
        int curA = 0, curB = -INF;
        int lastMouse = -1;
        for (int i = 0; i < CL; i++) {
            int prevCheese = i > 0 ? CX[i - 1] : -INF;
            int curCheese = CX[i];
            int nextCheese = i + 1 < CL ? CX[i + 1] : INF;
            
            List<Integer> pos = new ArrayList<Integer>();
            
            boolean leftMouseAmb = true;
            
            int mmm = (lastMouse == -1 ? -INF : MX[lastMouse]);
            if (Math.abs(mmm - prevCheese) < Math.abs(mmm - curCheese)) {
                lastMouse++;
                leftMouseAmb = false;
            }
            
            while (lastMouse < ML && Math.abs(MX[lastMouse] - curCheese) <= Math.abs(MX[lastMouse] - nextCheese)) {
                pos.add(MX[lastMouse]);
                lastMouse++;
            }
            
            lastMouse--;
            
            mmm = (lastMouse == -1 ? -INF : MX[lastMouse]);
            boolean rightMouseAmb = Math.abs(mmm - curCheese) == Math.abs(mmm - nextCheese);
            
            int nextA = -1000000000, nextB = -1000000000;
            
            int left = (prevCheese + curCheese) / 2;
            int right = (curCheese + nextCheese) / 2;
            
            if (!rightMouseAmb) {
                nextA = Math.max(nextA, curA + count(pos, curCheese, new int[0]));
                if (leftMouseAmb)
                    nextA = Math.max(nextA, curB + count(pos, curCheese, new int[] {left}));
            } else {
                nextB = Math.max(nextB, curA + count(pos, curCheese, new int[0]));
                nextA = Math.max(nextA, curA + count(pos, curCheese, new int[] {right}));
                if (leftMouseAmb) {
                    nextB = Math.max(nextB, curB + count(pos, curCheese, new int[] {left}));
                    nextA = Math.max(nextA, curB + count(pos, curCheese, new int[] {left, right}));
                }
            }
            
            curA = nextA; curB = nextB;
        }
        
        System.out.println(ML - curA);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}