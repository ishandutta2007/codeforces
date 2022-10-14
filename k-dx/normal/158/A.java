import java.util.ArrayList;
import java.util.Scanner;

public class next_round {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] t = new int[n];
        int last = -1;
//        ArrayList<Integer> standings = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            t[i] = sc.nextInt();
//            if (standings.isEmpty() || standings.get(standings.size()-1) != t[i])
//                standings.add(t[i]);
        }

//        System.out.println(standings);
//        for (Integer e : standings) {
//        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] > 0 && t[i] >= t[k-1]) {
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}