import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class ProblemC {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] a = new String[n];
        String[] b = new String[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            a[i] = st.nextToken();
            b[i] = st.nextToken();
            if (a[i].compareTo(b[i]) > 0) {
                String tmp = a[i];
                a[i] = b[i];
                b[i] = tmp;
            }
        }
        int[] p = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(st.nextToken()) - 1;
        }
        String last = "";
        for (int i = 0; i < n; i++) {
            if (a[p[i]].compareTo(last) > 0) {
                last = a[p[i]];
            } else if (b[p[i]].compareTo(last) > 0) {
                last = b[p[i]];
            } else {
                System.out.println("NO");
                System.exit(0);
            }
        }
        System.out.println("YES");
    }
}