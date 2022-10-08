import java.util.*;
import java.io.*;

public class Solution {
    int deg(String[] map, int x, int y) {
        int res=0;
        for (int dx=-1; dx<=1; dx++)
            for (int dy=-1; dy<=1; dy++) {
                if (dx==0 && dy==0) continue;
                if (x+dx>=0 && x+dx<map.length && y+dy>=0 && y+dy<map[0].length() && map[x+dx].charAt(y+dy)=='1')
                    res++;
            }
        return res;
    }
    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int c=0; c<t; c++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            
            String[] map = new String[n];
            for (int i=0; i<n; i++) map[i] = br.readLine();
            
            int res = 0;
            
            boolean[][] used = new boolean[n][m];
            int[] dx = new int[] {-1, 1, 0, 0};
            int[] dy = new int[] {0, 0, -1, 1};
            int[] qi = new int[n*m], qj = new int[n*m];
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (!used[i][j] && map[i].charAt(j)=='1') {
                        int mini = i, maxi = i, minj = j, maxj = j;
                        int qbeg = 0, qend = 0;
                        qi[qbeg] = i; qj[qbeg++] = j; used[i][j]=true;
                        while (qend < qbeg) {
                            int curi = qi[qend], curj = qj[qend++];
                            if (curi<mini) mini=curi;
                            if (curi>maxi) maxi=curi;
                            if (curj<minj) minj=curj;
                            if (curj>maxj) maxj=curj;
                            for (int dir=0; dir<4; dir++)
                                if (curi+dx[dir]>=0 && curi+dx[dir]<n && curj+dy[dir]>=0 && curj+dy[dir]<m
                                    && map[curi+dx[dir]].charAt(curj+dy[dir])=='1' &&
                                    !used[curi+dx[dir]][curj+dy[dir]]) {
                                    qi[qbeg] = curi+dx[dir];
                                    qj[qbeg++] = curj+dy[dir];
                                    used[curi+dx[dir]][curj+dy[dir]] = true;
                                }
                        }
                        boolean ok = true;
                        if (maxj-minj != maxi-mini || mini==maxi) continue;
                        for (int jj=minj; jj<=maxj; jj++) {
                            if (map[mini].charAt(jj) != '1') {ok=false; break;}
                            if (map[maxi].charAt(jj) != '1') {ok=false; break;}
                        }
                        if (!ok) continue;
                        for (int ii=mini; ii<=maxi; ii++) {
                            if (map[ii].charAt(minj) != '1') {ok = false; break;}
                            if (map[ii].charAt(maxj) != '1') {ok = false; break;}
                        }
                        if (!ok) continue;
                        for (int jj=minj-1; jj<=maxj+1; jj++) {
                            if (mini>0 && jj>=0 && jj<m && map[mini-1].charAt(jj) != '0') {ok=false; break;}
                            if (maxi+1<n && jj>=0 && jj<m && map[maxi+1].charAt(jj) != '0') {ok=false; break;}
                        }
                        if (!ok) continue;
                        for (int ii=mini-1; ii<=maxi+1; ii++) {
                            if (minj>0 && ii>=0 && ii<n && map[ii].charAt(minj-1) != '0') {ok=false; break;}
                            if (maxj+1<m && ii>=0 && ii<n && map[ii].charAt(maxj+1) != '0') {ok=false; break;}
                        }
                        if (!ok) continue;
                        for (int jj=minj+1; jj<maxj; jj++) {
                            if (map[mini+1].charAt(jj) != '0') {ok=false; break;}
                            if (map[maxi-1].charAt(jj) != '0') {ok=false; break;}
                        }
                        if (!ok) continue;
                        for (int ii=mini+1; ii<maxi; ii++) {
                            if (map[ii].charAt(minj+1) != '0') {ok=false; break;}
                            if (map[ii].charAt(maxj-1) != '0') {ok=false; break;}
                        }
                        if (!ok) continue;
                        res++;
                        //System.out.println("plain " + mini + " " + maxi + " " + minj + " " + maxj);
                    }
            
            for (int i=0; i<n; i++) Arrays.fill(used[i], false);
            
            dx = new int[] {1, 1, -1, -1};
            dy = new int[] {1, -1, 1, -1};
            
            for (int i=0; i<n; i++)
                for (int j=0; j<m; j++)
                    if (!used[i][j] && map[i].charAt(j)=='1') {
                        int mini = i, maxi = i, minj = j, maxj = j;
                        int qbeg = 0, qend = 0;
                        qi[qbeg] = i; qj[qbeg++] = j; used[i][j]=true;
                        while (qend < qbeg) {
                            int curi = qi[qend], curj = qj[qend++];
                            if (curi<mini) mini=curi;
                            if (curi>maxi) maxi=curi;
                            if (curj<minj) minj=curj;
                            if (curj>maxj) maxj=curj;
                            for (int dir=0; dir<4; dir++)
                                if (curi+dx[dir]>=0 && curi+dx[dir]<n && curj+dy[dir]>=0 && curj+dy[dir]<m
                                    && map[curi+dx[dir]].charAt(curj+dy[dir])=='1' &&
                                    !used[curi+dx[dir]][curj+dy[dir]]) {
                                    qi[qbeg] = curi+dx[dir];
                                    qj[qbeg++] = curj+dy[dir];
                                    used[curi+dx[dir]][curj+dy[dir]] = true;
                                }
                        }
                        if (maxi-mini != maxj-minj || (maxi-mini) % 2 != 0 || maxi-mini == 0) continue;
                        
                        boolean ok = true;
                        
                        for (int ii=(mini+maxi)/2, jj=minj; ii >= mini; ii--, jj++)
                            if (map[ii].charAt(jj) != '1' || deg(map,ii,jj) != 2) {ok=false; break;}
                        
                        if (!ok) continue;
                        
                        for (int ii=(mini+maxi)/2, jj=minj; ii <= maxi; ii++, jj++)
                            if (map[ii].charAt(jj) != '1' || deg(map,ii,jj) != 2) {ok=false; break;}
                        
                        if (!ok) continue;
                        
                        for (int ii=(mini+maxi)/2, jj=maxj; ii >= mini; ii--, jj--)
                            if (map[ii].charAt(jj) != '1' || deg(map,ii,jj) != 2) {ok=false; break;}
                        
                        if (!ok) continue;
                        
                        for (int ii=(mini+maxi)/2, jj=maxj; ii <= maxi; ii++, jj--)
                            if (map[ii].charAt(jj) != '1' || deg(map,ii,jj) != 2) {ok=false; break;}
                        
                        if (!ok) continue;
                        
                        res++;
                        
                        //System.out.println("diag " + mini + " " + maxi + " " + minj + " " + maxj);
                    }
            
            System.out.println(res);
        }
        br.close();
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).doMain();
    }
}