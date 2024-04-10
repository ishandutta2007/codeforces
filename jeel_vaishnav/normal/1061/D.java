import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long x = sc.nextLong();
        long y = sc.nextLong();

        Show show[] = new Show[n];
        for(int i = 0; i < n; ++i)
            show[i] = new Show(sc.nextLong(), sc.nextLong());

        Arrays.sort(show, new Comparator<Show>() {
            public int compare(Show s1, Show s2) {
                if(s1.l > s2.l)
                    return 1;
                if(s1.l < s2.l)
                    return -1;
                return 0;
            }
        });

        PriorityQueue<Long> queue = new PriorityQueue<>(new Comparator<Long>() {
            public int compare(Long l1, Long l2) {
                if(l1 < l2)
                    return -1;
                if(l1 > l2)
                    return 1;
                return 0; 
            }
        });

        long ans = 0;
        Stack<Long> stack = new Stack<>();
        for(int i = 0; i < n; ++i) {
            long l = show[i].l;
            long r = show[i].r;

            while(queue.size() != 0 && queue.peek() < l)
                stack.push(queue.poll());

            if(stack.size() == 0) {
                ans += x + (r - l) * y;
                ans %= 1000000007;
            }
            else {
                if((l - stack.peek()) * y < x) {
                    ans += (r - stack.pop()) * y;
                    ans %= 1000000007;
                }
                else {
                    ans += x + (r - l) * y;
                    ans %= 1000000007;
                }
            }

            queue.add(r);
        }

        System.out.print(ans);
    }
}
class Show {
    long l, r;
    Show(long a, long b) {
        l = a;
        r = b;
    }
}