import java.util.*;


public class Main {
    final int maxn = 10000;
    int k, m;
    ArrayList<Integer> e[] = new ArrayList[maxn], g[] = new ArrayList[maxn];


    boolean used[] = new boolean[3];
    int P[] = new int[3];
    int B[] = new int[3];

    Integer comp(int a, int b) {
        for (int i = 1, j = 0; i <= b || j == 0; i *= 10, j++) a *= 10;
        return a + b;
    }

    public void calc(int x, ArrayList<Integer> A) {
        for (int i = 1; i < 3; i++) if (B[P[i]] == 3 && B[P[i - 1]] != 3) return;
        if (A.get(0) < 0 && B[0] == 3) return;
        ArrayList<Integer> a = new ArrayList<Integer>(A);
        ArrayList<Integer> b = new ArrayList<Integer>(), p = new ArrayList<Integer>();
        for (int i = 0; i < 3; i++) {
            b.add(B[i]);
            p.add(P[i]);
        }

        for (int i = 0; i < 3; i++) {
            int j = p.get(i);
            if (b.get(j) == 0) {
                a.set(j, a.get(j) + a.get(j + 1));
            }
            if (b.get(j) == 1) {
                a.set(j, a.get(j) - a.get(j + 1));
            }
            if (b.get(j) == 2) {
                a.set(j, a.get(j) * a.get(j + 1));
            }
            if (b.get(j) == 3) {
                if (a.get(j) == 0) return;
                a.set(j, comp(a.get(j), a.get(j + 1)));
            }
            for (int k = j + 1; k < a.size() - 1; k++) a.set(k, a.get(k + 1));
            for (int k = j; k < 2; k++) b.set(k, b.get(k + 1));
            for (int k = i + 1; k < 3; k++) if (p.get(k) >= p.get(i)) p.set(k, p.get(k) - 1);
            a.remove(a.size() - 1);
        }
        int res = a.get(0);
        if (res >= 0 && res < maxn)
            g[x].add(res);
    }

    public void work(int x, ArrayList<Integer> a, int cur) {
        if (cur == 3) {
            for (B[0] = 0; B[0] < 4; B[0]++) {
                for (B[1] = 0; B[1] < 4; B[1]++) {
                    for (B[2] = 0; B[2] < 4; B[2]++) {
                        calc(x, a);
                    }
                }
            }
            return;
        }
        for (int i = 0; i < 3; i++) if (!used[i]) {
            used[i] = true;
            P[cur] = i;
            work(x, a, cur + 1);
            used[i] = false;
        }
    }

    public void lol(int x) {
        ArrayList<Integer> a = new ArrayList<Integer>();
        a.add(x / 1000); a.add(x / 100 % 10); a.add(x / 10 % 10); a.add(x % 10);
        work(x, a, 0);
        a.set(0, -a.get(0));
        work(x, a, 0);
    }

    public String omg(int a, int b) {
        String res = "";
        for (int i = 0; i < 4; i++) {
            res = (char)('0' + b % 10) + res;
            b /= 10;
        }
        b = a;
        for (int i = 0; i < 4; i++) {
            res = (char)('0' + b % 10) + res;
            b /= 10;
        }
        return res;
    }

    int was[] = new int[maxn];
    public void Run() {
        for (int i = 0; i < maxn; i++) e[i] = new ArrayList<Integer>();
        for (int i = 0; i < maxn; i++) g[i] = new ArrayList<Integer>();

        Scanner in = new Scanner(System.in);
        k = in.nextInt();
        m = in.nextInt();

        ArrayList<String> ans = new ArrayList<String>();
        int sum = 0;
        for (int x = 0; x < maxn; x++) {
            lol(x);
            Collections.sort(g[x]);
            for (int i = 0; i < g[x].size(); i++) {
                int o = g[x].get(i);
                if (Math.abs(k - o) < maxn && was[Math.abs(k - o)] != x + 1) {
                    ans.add(omg(Math.abs(k - o), x));
                    was[Math.abs(k - o)] = x + 1;
                }
                if (ans.size() == m) break;
            }
            if (ans.size() == m) break;
        }
        for (int i = 0; i < m; i++) System.out.println(ans.get(i));
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}