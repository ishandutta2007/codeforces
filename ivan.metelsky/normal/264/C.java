import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    class Input {
        int n;
        int q;
        long[] v;
        int[] c;
        long[] a;
        long[] b;
    }

    class Output {
        long[] ans;
    }

    Input loadData() throws Exception {
        Input inp = new Input();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        inp.n = Integer.parseInt(st.nextToken());
        inp.q = Integer.parseInt(st.nextToken());
        inp.v = new long[inp.n];
        inp.c = new int[inp.n];
        inp.a = new long[inp.q];
        inp.b = new long[inp.q];
        st = new StringTokenizer(br.readLine());
        for (int i=0; i<inp.n; i++) inp.v[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i=0; i<inp.n; i++) inp.c[i] = Integer.parseInt(st.nextToken());
        for (int i=0; i<inp.q; i++) {
            st = new StringTokenizer(br.readLine());
            inp.a[i] = Integer.parseInt(st.nextToken());
            inp.b[i] = Integer.parseInt(st.nextToken());
        }
        br.close();
        return inp;
    }

    class TwoMaxStructure {
        long[] value;
        long max, max2;
        int maxPos, max2Pos;

        public TwoMaxStructure(int n) {
            value = new long[n+1];
        }

        void reset() {
            Arrays.fill(value, -1000000000000000000L);
            value[0] = 0;
            max = 0; maxPos = 0;
            max2 = value[1]; max2Pos = 1;
        }

        void update(int pos, long val) {
            if (value[pos] >= val) {
                return;
            }
            value[pos] = val;
            if (pos == maxPos) {
                max = val;
                return;
            }
            if (pos == max2Pos) {
                if (val >= max) {
                    max2Pos = maxPos; max2 = max;
                    maxPos = pos; max = val;
                } else {
                    max2 = val;
                }
                return;
            }
            if (val >= max) {
                max2Pos = maxPos; max2 = max;
                maxPos = pos; max = val;
            } else if (val >= max2) {
                max2Pos = pos; max2 = val;
            }
        }
    }

    Output solveProblem(Input inp) throws Exception {
        Output out = new Output();
        out.ans = new long[inp.q];
        TwoMaxStructure ds = new TwoMaxStructure(inp.n);
        for (int qq = 0; qq < inp.q; qq++) {
            long a = inp.a[qq], b = inp.b[qq];
            ds.reset();
            long ans = 0;
            for (int i=0; i < inp.n; i++) {
                long sameColor = ds.value[inp.c[i]] + inp.v[i] * a;
                long diffColor = (ds.maxPos != inp.c[i] ? ds.max : ds.max2) + inp.v[i] * b;
                long best = Math.max(sameColor, diffColor);
                ans = Math.max(ans, best);
                ds.update(inp.c[i], best);
            }
            out.ans[qq] = ans;
        }
        return out;
    }

    void printResult(Output out) throws Exception {
        for (long elm : out.ans) {
            System.out.println(elm);
        }
    }

    public void doMain() throws Exception {
        Input inp = loadData();
        Output out = solveProblem(inp);
        printResult(out);
    }

    public static void main(String[] args) throws Exception {
        new Solution().doMain();
    }
}