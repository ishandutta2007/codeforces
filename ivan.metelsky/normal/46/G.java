import java.util.*;
import java.io.*;

public class Solution {
    boolean[] isSq;
    int[] lens;
    int[] cnt;
    int[][] vx, vy;
    
    int N;
    
    int[] solX, solY;
    
    boolean[][][][] was;
    
    final int LIM = 90;
    
    class Segment implements Comparable<Segment> {
        int dx, dy;
        double angle;
        
        public Segment(int dx, int dy) {
            this.dx = dx;
            this.dy = dy;
            this.angle = Math.atan2(dy, dx);
        }
        
        public int compareTo(Segment other) {
            return new Double(this.angle).compareTo(new Double(other.angle));
        }
    }
    
    int it = 0;
    boolean retFlag = false;
    
    boolean[] skipped;
    
    void go(int pos, int take, int curX, int curY, int skip) {
        /*if (Math.abs(curX) >= LIM || Math.abs(curY) >= LIM)
            return;*/
        
        if (take == N) {
            if (curX==0 && curY==0) {
                System.out.println("YES");
                
                Segment[] segm = new Segment[N];
                for (int i=0; i < N; i++)
                    segm[i] = new Segment(solX[i], solY[i]);
                Arrays.sort(segm);
                int cx=0, cy=0;
                
                for (int i=0; i < N; i++) {
                    System.out.println(cx + " " + cy);
                    cx += segm[i].dx;
                    cy += segm[i].dy;
                }
                System.exit(0);
            }
            it++;
            if (it==10000) retFlag = true;
            return;
        }

        /*int A = Math.max(Math.abs(curX), Math.abs(curY));
        int B = Math.min(Math.abs(curX), Math.abs(curY));
        if (was[pos][A][B][skip]) {
            return;
        }
        was[pos][A][B][skip] = true;*/
        
        int[] nx = new int[cnt[pos]];
        int[] ny = new int[cnt[pos]];
        int[] dist = new int[cnt[pos]];
        
        for (int x=0; x < cnt[pos]; x++) {
            nx[x] = curX + vx[pos][x];
            ny[x] = curY + vy[pos][x];
            dist[x] = nx[x] * nx[x] + ny[x] * ny[x];
        }
        
        for (int x=0; x + 1 < cnt[pos]; x++)
            for (int y=0; y + 1 < cnt[pos]; y++)
                if (dist[y] > dist[y + 1]) {
                    int tmp = nx[y]; nx[y] = nx[y+1]; nx[y+1] = tmp;
                    tmp = ny[y]; ny[y] = ny[y+1]; ny[y+1] = tmp;
                    tmp = dist[y]; dist[y] = dist[y+1]; dist[y+1] = tmp;
                }
        
        if (skip > 0 && skipped[pos])
            go(pos - 1, take, curX, curY, skip - 1);
        
        if (retFlag) return;
    
        for (int x=0; x < cnt[pos]; x++) {
            solX[take] = nx[x] - curX;
            solY[take] = ny[x] - curY;
            go(pos - 1, take + 1, nx[x], ny[x], skip);
            if (retFlag) return;
        }       
    }
    
    public void doMain() {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        N = sc.nextInt();
        
        if (N==3) {
            System.out.println("YES");
            System.out.println("0 0");
            System.out.println("1 0");
            System.out.println("0 2");
            System.exit(0);
        }
        
        isSq = new boolean[100000];
        for (int i=0; i*i < isSq.length; i++)
            isSq[i*i] = true;
        
        lens = new int[11000];
        vx = new int[11000][100];
        vy = new int[11000][100];
        cnt = new int[11000];
        
        int pos = 0;
        skipped = new boolean[N + 2];
        for (int len=1; ; len++) {
            boolean ok = false;
            for (int x=0; x*x <= len; x++) {
                if (!isSq[len-x*x]) continue;
                lens[pos] = len;
                int y = (int)Math.sqrt(len - x*x);
                ok = true;
                
                vx[pos][cnt[pos]] = x;
                vy[pos][cnt[pos]++] = y;
                
                if (x != 0) {
                    vx[pos][cnt[pos]] = -x;
                    vy[pos][cnt[pos]++] = y;
                }
                
                if (y != 0) {
                    vx[pos][cnt[pos]] = x;
                    vy[pos][cnt[pos]++] = -y;
                }
                
                if (x != 0 && y != 0) {
                    vx[pos][cnt[pos]] = -x;
                    vy[pos][cnt[pos]++] = -y;
                }
            }
            if (ok) {
                pos++;
            }
            if (pos == N + 1) break;
        }
        
        int oo = 0, ee = 0, oe = 0;
        for (int i=0; i < N; i++) {
            if (vx[i][0] % 2 == 0 && vy[i][0] % 2 == 0)
                ee++;
            else if (vx[i][0] % 2 == 1 && vy[i][0] % 2 == 1)
                oo++;
            else
                oe++;
        }
        
        int stSkip = 0;
        
        if (oe % 2 == 1) {
            stSkip = 1;
        }
                
        solX = new int[N];
        solY = new int[N];
        
        /*was = new boolean[N+2][LIM][][];
        
        for (int i=0; i < was.length; i++)
            for (int A=0; A<LIM; A++)
                was[i][A] = new boolean[A+1][2];*/
        
        for (int skip=stSkip; skip<2; skip = (skip + 1) % 2) {      
            /*for (int i=0; i < was.length; i++)
                for (int j=0; j < was[i].length; j++)
                    for (int k=0; k < was[i][j].length; k++)
                        Arrays.fill(was[i][j][k], false);*/
            
            if (skip == 1) {
                for (int i=0; i < N+1; i++) {
                    skipped[i] = true;
                    retFlag = false;
                    it = 0;
                    go(N + skip - 1, 0, 0, 0, skip);
                    skipped[i] = false;
                }
            } else {
                retFlag = false;
                it = 0;
                go(N + skip - 1, 0, 0, 0, skip);
            }
        }
    }
    
    public static void main(String[] args) throws Exception {
        new Solution().doMain();
    }
}