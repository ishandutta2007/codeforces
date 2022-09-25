import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {

    int n, m;
    ArrayList<Integer> e[] = new ArrayList[100001];

    Boolean isEdge(int u, int v) {
        for (int i = 0; i < e[u].size(); i++) if (e[u].get(i) == v) return true;
        return false;
    }

    public void Run() {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        for (int i = 1; i <= n; i++) e[i] = new ArrayList<Integer>();
        for (int i = 0; i < m; i++) {
            int u, v;
            u = in.nextInt();
            v = in.nextInt();
            e[u].add(v);
            e[v].add(u);
        }

        ArrayList<Integer> v = new ArrayList<Integer>();
        for (int i = 1; i <= n; i++) v.add(i);

        Boolean found = false;
        for (int it = 0; it < 100; it++) {
            Boolean ok = true;
            Collections.shuffle(v);
            for (int i = 1; i < n; i++) {
                if (isEdge(v.get(i), v.get(i - 1))) {
                    ok = false;
                    break;
                }
            }
            if (m == n && isEdge(v.get(0), v.get(v.size() - 1))) ok = false;
            if (ok) {
                for (int i = 0; i < m; i++) {
                    System.out.println(v.get(i) + " " + v.get((i + 1) % n));
                }
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println(-1);
        }
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}