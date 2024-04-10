import java.util.*;
import java.io.*;

public class Solution {
    class Road implements Comparable<Road> {
        int from, to;
        int g, s;
        public Road(int from, int to, int g, int s) {
            this.from = from;
            this.to = to;
            this.g = g;
            this.s = s;
        }
        public int compareTo(Road other) {
            return this.g - other.g;
        }
    }
    
    int[] p;
    int[] rank;
    
    int findRoot(int x) {
        if (p[x] != x)
            p[x] = findRoot(p[x]);
        return p[x];
    }
    
    void union(int a, int b) {
        if (rank[a] < rank[b]) {
            p[a] = b;
        } else {
            p[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    
    public void go() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long G = Integer.parseInt(st.nextToken());
        long S = Integer.parseInt(st.nextToken());
        Road[] roads = new Road[M];
        for (int i=0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            roads[i] = new Road(Integer.parseInt(st.nextToken()) - 1, Integer.parseInt(st.nextToken()) - 1, 
                    Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
        }
        br.close();
        
        Arrays.sort(roads);
        
        long ans = Long.MAX_VALUE;
        
        Road[] useful = new Road[N + 10];
        int usefulCnt = 0;
        
        Road[] nextUseful = new Road[N + 10];
        int nextUsefulCnt = 0;
        
        p = new int[N];
        rank = new int[N];
        
        for (int i=0; i < M; i++) {
            useful[usefulCnt++] = roads[i];
            Arrays.sort(useful, 0, usefulCnt, new Comparator<Road>() {
                public int compare(Road a, Road b) {
                    return a.s - b.s;
                }
            });
            
            for (int j=0; j < N; j++) {
                p[j] = j;
                rank[j] = 0;
            }
            
            int compCnt = N;
            nextUsefulCnt = 0;
            for (int j=0; j < usefulCnt; j++) {
                int a = findRoot(useful[j].from);
                int b = findRoot(useful[j].to);
                if (a == b) continue;
                compCnt--;
                union(a, b);
                nextUseful[nextUsefulCnt++] = useful[j];
                
                if (compCnt == 1) {
                    ans = Math.min(ans, G * (long)roads[i].g + S * (long)useful[j].s);
                    break;
                }
            }
            
            for (int j=0; j < nextUsefulCnt; j++)
                useful[j] = nextUseful[j];
            
            usefulCnt = nextUsefulCnt;
        }
        
        System.out.println(ans == Long.MAX_VALUE ? -1 : ans);
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}