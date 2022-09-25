import java.util.*;


public class Main {

    final int maxn = 1 << 17;



    public void Run() {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        ArrayList<Integer> v = new ArrayList<Integer>();
        for (int i = 0; i < 8; i++) v.add(0);
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            v.set(x, v.get(x) + 1);
        }

        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        ArrayList<Integer> c = new ArrayList<Integer>();

        for (int i = 0; i < v.get(4); i++) {
            a.add(1);
            b.add(2);
            c.add(4);
        }
        v.set(2, v.get(2)-v.get(4));
        v.set(1, v.get(1)-v.get(4));
        v.set(4, v.get(4)-v.get(4));

        int o = v.get(6);
        for (int i = 0; i < o; i++) {
            a.add(1);
            v.set(1, v.get(1) - 1);
            if (v.get(2) > 0) {
                b.add(2);
                v.set(2, v.get(2) - 1);
            } else {
                b.add(3);
                v.set(3, v.get(3) - 1);
            }
            c.add(6);
            v.set(6, v.get(6) - 1);
        }

        if (a.size() * 3 != n || v.get(2) != 0 || v.get(1) != 0 || v.get(3) != 0) {
            System.out.println(-1);
            return;
        }
        for (int i = 0; i * 3 < n; i++) {
            System.out.println(a.get(i) + " " + b.get(i) + " " + c.get(i));
        }
    }

    public static void main(String[] args) {
        new Main().Run();
    }
}