import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {
    class Input {
        int[] a;
    }

    class Output {
        int ans;
    }

    Input loadData() throws Exception {
        Input inp = new Input();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        inp.a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=0; i < n; i++) {
            inp.a[i] = Integer.parseInt(st.nextToken());
        }
        return inp;
    }

    Output solveProblem(Input inp) throws Exception {
        Output out = new Output();

        int n = inp.a.length;
        int[] best = new int[100001];

        for (int elm : inp.a) {
            int max = 0;
            for (int i = 1; i * i <= elm; i++)
                if (elm % i == 0) {
                    if (i>1) max = Math.max(max, best[i]);
                    if (elm/i>1) max = Math.max(max, best[elm/i]);
                }
            max++;
            for (int i = 1; i * i <= elm; i++)
                if (elm % i == 0) {
                    if (i>1) best[i] = max;
                    if (elm/i>1) best[elm/i] = max;
                }
        }

        out.ans = 1;
        for (int i=1; i<=100000; i++)
            out.ans = Math.max(out.ans, best[i]);

        return out;
    }

    void printResult(Output out) throws Exception {
        System.out.println(out.ans);
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