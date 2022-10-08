import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class ProblemC {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        int n = sc.nextInt();
        List<Integer> argue = new ArrayList<Integer>();
        int ciel = 0, jiro = 0;
        for (int i=0; i<n; i++) {
            int len = sc.nextInt();
            for (int j=0; j<len; j++) {
                int val = sc.nextInt();
                if (j < len - j - 1) {
                    ciel += val;
                } else if (j > len - j - 1) {
                    jiro += val;
                } else {
                    argue.add(val);
                }
            }
        }
        sc.close();
        Collections.sort(argue);
        for (int i = argue.size() - 1; i >= 0; i--) {
            if ((argue.size() - i) % 2 == 1) ciel += argue.get(i);
            else jiro += argue.get(i);
        }

        System.out.println(ciel + " " + jiro);
    }
}