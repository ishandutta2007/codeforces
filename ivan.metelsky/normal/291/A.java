import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ProblemA {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        Map<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for (int i=0; i<n; i++) {
            int id = sc.nextInt();
            if (id == 0) continue;
            if (!cnt.containsKey(id)) cnt.put(id, 0);
            cnt.put(id, cnt.get(id) + 1);
        }
        int res = 0;
        for (int id : cnt.keySet()) {
            if (cnt.get(id) == 2) res++;
            else if (cnt.get(id) > 2) {
                System.out.println(-1);
                System.exit(0);
            }
        }
        System.out.println(res);
    }
}