import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {
    int n;
    ArrayList<Integer> e[] = new ArrayList[100001];
    ArrayList<Integer> ans = new ArrayList();


    void dfs(int v) {
        int o = v;
        v %= n / 2;
        while (!e[v].isEmpty()) {
            int x = e[v].get(e[v].size() - 1);
            e[v].remove(e[v].size() - 1);
            dfs(x);
        }
        ans.add(o);
    }

    public void Run() {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        if (n % 2 == 1) {
            System.out.print(-1);
            return;
        }
        for (int i = 0; i * 2 < n; i++) {
            e[i] = new ArrayList<Integer>();
            e[i].add(2 * i);
            e[i].add(2 * i + 1);
        }
        dfs(0);
        for (int i = ans.size() - 1; i >= 0; i--) {
            System.out.print(ans.get(i) + (i > 0 ? " " : "\n"));
        }
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}