import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Ivan Miatselski
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputStreamReader in = new InputStreamReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskC {
    BufferedReader br;
    StringTokenizer st;
    public int nextInt() throws Exception {
        while (!st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return Integer.parseInt(st.nextToken());
    }
        public void solve(int testNumber, InputStreamReader in, PrintWriter out) {
            try {
                br = new BufferedReader(in);
                st = new StringTokenizer(br.readLine());
                int n = nextInt();
                long k =  nextInt();
                long[] a = new long[n];
                for (int i=0; i<n; i++)
                    a[i] =  nextInt();
                br.close();

                /*Random rnd = new Random();
                int[] p = new int[n];
                for (int i=0; i<n; i++) {
                    p[i] = i;
                    int j = rnd.nextInt(i+1);
                    int tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;
                }
                long[] b = new long[n];
                for (int i=0; i<n; i++)
                    b[i] = a[p[i]];
                for (int i=0; i<n; i++)
                    a[i] = b[i];*/
                Arrays.sort(a);

                int l = 0, r = 0;
                long need = 0;
                int max = 0;
                long num = -1;
                while (r < n) {
                    if (need <= k) {
                        if (r - l + 1 > max) {
                            max = r - l + 1;
                            num = a[r];
                        }
                        r++;
                        if (r == n) break;
                        long diff = a[r] - a[r-1];
                        need += (r - l) * diff;
                    } else {
                        need -= a[r] - a[l];
                        l++;
                    }
                }

                out.println(max + " " + num);
            } catch (Exception e) {
            }
        }

}