import java.util.*;
import java.io.*;

public class CDF22_E {
    void printEdge(int a, int b) {
        System.out.println((a+1)+" "+(b+1));
    }
    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] f = new int[n];
        for (int i=0; i<n; i++) {
            f[i] = Integer.parseInt(st.nextToken()) - 1;
        }
        br.close();
        
        int[] p = new int[n];
        Arrays.fill(p, -1);
        
        for (int i=0; i<n; i++) {
            if (p[i] != -1) continue;
            Stack<Integer> stack = new Stack<Integer>();
            int cur = i;
            while (p[cur] == -1) {
                p[cur] = -2;
                stack.push(cur);
                cur = f[cur];
            }
            int pp = p[cur] == -2 ? cur : p[cur];
            while (!stack.empty()) {
                int x = stack.pop();
                p[x] = pp;
            }
        }
        
        boolean[] hasIncoming = new boolean[n];
        for (int i=0; i<n; i++)
            hasIncoming[f[i]] = true;
        
        List<Integer> selfParents = new ArrayList<Integer>();
        int[] selfParentId = new int[n];
        for (int i=0; i < n; i++) if (p[i] == i) {
            selfParents.add(i);
            selfParentId[i] = selfParents.size() - 1;
        }
        
        List<Integer> leaf = new ArrayList<Integer>();
        for (int i=0; i<selfParents.size(); i++) leaf.add(-1);
        int leafCnt = 0;
        for (int i=0; i<n; i++)
            if (!hasIncoming[i]) {
                leaf.set(selfParentId[p[i]], i);
                leafCnt++;
            }
        
        if (selfParents.size() == 1 && leafCnt == 0) {
            System.out.println(0);
            System.exit(0);
        }
        
        for (int i=0; i < leaf.size(); i++)
            if (leaf.get(i) == -1) {
                leaf.set(i, selfParents.get(i));
                leafCnt++;
            }
        
        System.out.println(leafCnt);
        
        for (int i=0; i < selfParents.size(); i++) {
            int ii = (i + 1) % selfParents.size();
            printEdge(selfParents.get(i), leaf.get(ii));
            hasIncoming[leaf.get(ii)] = true;
        }
        
        for (int i=0; i < n; i++)
            if (!hasIncoming[i])
                printEdge(selfParents.get(0), i);
    }
    
    public static void main(String[] args) throws Exception {
        (new CDF22_E()).doMain();
    }
}