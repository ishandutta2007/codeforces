import java.util.*;
import java.io.*;

public class Solution {
    public void go() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] sets = new int[(n*(n-1))/2][];
        for (int i=0; i < sets.length; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int len = Integer.parseInt(st.nextToken());
            sets[i] = new int[len];
            for (int j=0; j < len; j++)
                sets[i][j] = Integer.parseInt(st.nextToken());
            Arrays.sort(sets[i]);
        }
        br.close();
        
        if (n == 2) {
            System.out.println(1 + " " + sets[0][0]);
            System.out.print(sets[0].length-1);
            for (int i=1; i < sets[0].length; i++)
                System.out.print(" " + sets[0][i]);
            System.out.println();
            System.exit(0);
        }
        
        BitSet[] occurs = new BitSet[201];
        for (int i=0; i < 201; i++)
            occurs[i] = new BitSet(sets.length);
        
        for (int i=0; i < sets.length; i++)
            for (int j=0; j < sets[i].length; j++)
                occurs[sets[i][j]].set(i);
        
        boolean[] was = new boolean[201];
        for (int i=1; i<=200; i++) {
            if (occurs[i].isEmpty()) continue;
            if (was[i]) continue;
            List<Integer> curSet = new ArrayList<Integer>();
            for (int j=1; j<=200; j++)
                if (occurs[i].equals(occurs[j])) {
                    curSet.add(j);
                    was[j] = true;
                }
            System.out.print(curSet.size());
            for (int x : curSet) System.out.print(" "+x);
            System.out.println();
        }
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}