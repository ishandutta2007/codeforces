import java.util.*;
import java.io.*;

public class TaskD {
    final int ADD = 1;
    final int DEL = 2;
    final int SUM = 3;

    class Operation {
        int typ;
        int value;
        public Operation(int typ, int value) {
            this.typ = typ;
            this.value = value;
        }
    }

    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Set<Integer> nums = new HashSet<Integer>();
        Operation[] ops = new Operation[n];
        for (int i=0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String op = st.nextToken();
            if (op.equals("sum")) ops[i] = new Operation(SUM, -1);
            else {
                int value = Integer.parseInt(st.nextToken());
                if (op.equals("add")) ops[i] = new Operation(ADD, value);
                else ops[i] = new Operation(DEL, value);
                nums.add(value);
            }
        }
        br.close();

        int tot = nums.size();
        int[] keys = new int[tot];
        {
        int pos = 0;
        for (int x : nums) keys[pos++] = x;
        }
        Arrays.sort(keys);

        int[] status = new int[tot];

        final int X = 8;

        int parts = (tot>>X) + 1;
        long[][] sum = new long[parts][5];
        int[] cnt = new int[parts];

        for (int i=0; i < n; i++) {
            if (ops[i].typ == ADD || ops[i].typ == DEL) {
                int pos = Arrays.binarySearch(keys, ops[i].value);
                status[pos] = 1 - status[pos];
                int part = (pos >> X);
                if (ops[i].typ == ADD) cnt[part]++; else cnt[part]--;
                while (cnt[part]<0) cnt[part]+=5;
                while (cnt[part]>=5) cnt[part]-=5;
                Arrays.fill(sum[part], 0);
                int md = 0;
                for (int j=(part<<X); j < ((part+1)<<X) && j < tot; j++) {
                    if (status[j] == 1) {
                        sum[part][md] += keys[j];
                        md++;
                        if (md==5) md = 0;
                    }
                }
            } else {
                long res = 0;
                int md = 0;
                for (int j=0; j < parts; j++) {
                    int take = -1;
                    if (md == 0) take = 2;
                    if (md == 1) take = 1;
                    if (md == 2) take = 0;
                    if (md == 3) take = 4;
                    if (md == 4) take = 3;
                    res += sum[j][take];
                    md += cnt[j];
                    while (md >= 5) md -= 5;
                }
                System.out.println(res);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        new TaskD().doMain();
    }
}