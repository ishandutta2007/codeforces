import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
    void main() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        
        int N = sc.nextInt();
        
        int maxBoss = sc.nextInt();
        int regBoss = sc.nextInt();
        
        int[] pow = new int[N];
        int[] dmg = new int[N];
        
        for (int i=0; i<N; i++) {
            pow[i] = sc.nextInt();
            dmg[i] = sc.nextInt();
        }
        
        sc.close();
        
        int curHealth = maxBoss;
        int curDamage = 0;
        
        boolean[] used = new boolean[N];
        List<String> out = new ArrayList<String>();
        
        for (int t=0; t <= 10000; t++) {
            curHealth -= curDamage;         
            curHealth += regBoss;
            if (curHealth > maxBoss) curHealth = maxBoss;
            
            if (curHealth <= 0) {
                System.out.println("YES");
                System.out.println(t + " " + out.size());
                for (String elem : out)
                    System.out.println(elem);
                System.exit(0);
            }
            
            int maxDmg = -1;
            int id = -1;
            for (int i=0; i < N; i++)
                if (!used[i] && curHealth * 100 <= pow[i] * maxBoss && dmg[i] > maxDmg) {
                    maxDmg = dmg[i];
                    id = i;
                }
            
            if (id != -1) {
                used[id] = true;
                curDamage += maxDmg;
                out.add(t + " " + (id + 1));
            }
        }
        
        System.out.println("NO");
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).main();
    }
}