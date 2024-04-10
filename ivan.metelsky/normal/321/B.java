import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class ProblemB {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Integer> jiroAtk = new ArrayList<Integer>();
        List<Integer> jiroDef = new ArrayList<Integer>();
        List<Integer> ciel = new ArrayList<Integer>();
        for (int i=0; i<n; i++) {
            String typ = sc.next();
            if (typ.equals("ATK")) jiroAtk.add(sc.nextInt());
            else jiroDef.add(sc.nextInt());
        }
        for (int i=0; i<m; i++) ciel.add(sc.nextInt());
        sc.close();

        Collections.sort(jiroAtk);
        Collections.sort(jiroDef);
        Collections.sort(ciel);

        int ans = 0;
        for (int kill = 1; kill <= jiroAtk.size() && kill <= ciel.size(); kill++) {
            boolean ok = true;
            int sum = 0;
            for (int i=0, j = ciel.size() - kill; i < kill; i++, j++)
                if (ciel.get(j) >= jiroAtk.get(i)) {
                    sum += ciel.get(j) - jiroAtk.get(i);
                } else {
                    ok = false;
                }
            if (ok) ans = Math.max(ans, sum);
        }

        boolean ok = true;
        for (int y : jiroDef) {
            boolean find = false;
            for (int i=0; i < ciel.size(); i++)
                if (ciel.get(i) > y) {
                    find = true;
                    ciel.remove(i);
                    break;
                }
            if (!find) {ok = false; break;}
        }

        if (ok && jiroAtk.size() <= ciel.size()) {
            int sum = 0;
            for (int i = 0, j = ciel.size() - jiroAtk.size(); i < jiroAtk.size(); i++, j++)
                if (ciel.get(j) >= jiroAtk.get(i)) {
                    sum += ciel.get(j) - jiroAtk.get(i);
                } else {
                    ok = false;
                }
            if (ok) {
                for (int j=0; j < ciel.size() - jiroAtk.size(); j++) sum += ciel.get(j);
                ans = Math.max(ans, sum);
            }
        }

        System.out.println(ans);
    }
}