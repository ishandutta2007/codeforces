import java.util.*;
import static java.lang.Math.*;

public class SolutionF {
    static int queryBit(int[] bit, int ind) {
        int ans = 0;
        while(ind > 0) {
            ans += bit[ind];
            ind -= Integer.lowestOneBit(ind);
        }
        return ans;
    }
    static void updateBit(int[] bit, int ind, int val) {
        while(ind < bit.length) {
            bit[ind] += val;
            ind += Integer.lowestOneBit(ind);
        }
    }
    static TreeMap<Integer, Integer> lmap = new TreeMap<>();
    static TreeMap<Integer, Integer> rmap = new TreeMap<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        ArrayList<Event> list = new ArrayList<>();

        int p[] = new int[n];
        for(int i = 0; i < n; ++i) {
            p[i] = sc.nextInt();
        }

        int s[] = new int[n];
        for(int i = 0; i < n; ++i) {
            s[i] = sc.nextInt();
        }

        int b[] = new int[n];
        for(int i = 0; i < n; ++i) {
            b[i] = sc.nextInt();
        }

        for(int i = 0; i < n; ++i) {
            list.add(new Event(0, p[i], b[i] + p[i], 1));
            list.add(new Event(0, s[i] + 1, b[i] + p[i], -1));
            list.add(new Event(1, p[i], b[i] + 1 - p[i], -1));
            list.add(new Event(1, s[i] + 1, b[i] + 1 - p[i], 1));
        }

        int inc[] = new int[m];
        for(int i = 0; i < m; ++i)
            inc[i] = sc.nextInt();

        int pb[] = new int[m];
        for(int i = 0; i < m; ++i)
            pb[i] = sc.nextInt();

        for(int i = 0; i < m; ++i) {
            lmap.put(pb[i] + inc[i], 1);
            rmap.put(pb[i] - inc[i], 1);
            list.add(new Event(2, inc[i], pb[i], i));
        }

        Collections.sort(list, new Comparator<Event>() {
            public int compare(Event e1, Event e2) {
                if(e1.x < e2.x)
                    return -1;
                if(e1.x > e2.x)
                    return 1;
                if(e1.type < e2.type)
                    return -1;
                if(e1.type > e2.type) 
                    return 1;
                return 0;
            }
        });

        int ptr = 1;
        for(int i : lmap.keySet()) {
            lmap.put(i, ptr++);
        }
        int lbit[] = new int[ptr];

        ptr = 1;
        for(int i : rmap.keySet()) {
            rmap.put(i, ptr++);
        }
        int rbit[] = new int[ptr];

        int ans[] = new int[m];
        for(Event e : list) {
            int type = e.type;

            if(type == 0) {
                if(lmap.higherKey(e.y - 1) != null) { 
                    updateBit(lbit, lmap.get(lmap.higherKey(e.y - 1)), e.val);
                }
            }
            else if(type == 1) {
                if(rmap.higherKey(e.y - 1) != null) { 
                    updateBit(rbit, rmap.get(rmap.higherKey(e.y - 1)), e.val);
                } 
            }
            else {
                int lind = lmap.get(e.y + e.x);
                int rind = rmap.get(e.y - e.x);
                int ind = e.val;

                ans[ind] = queryBit(lbit, lind) + queryBit(rbit, rind);
            }   
        }

        for(int i : ans)
            System.out.print(i + " ");
    }
}
class Event {
    // type
    // 0 : lupd, 1 : rupd, 2 : people query
    int type, x, y, val;
    Event(int a, int b, int c, int d) {
        type = a;
        x = b;
        y = c;
        val = d;
    }
}