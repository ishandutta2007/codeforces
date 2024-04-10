import java.util.*;
import java.io.*;

public class TaskC {
    class Summarizer {
        int n;
        long[] keys;
        long[] sum;

        void updateSum(int pos, long value) {
            while (pos <= n) {
                sum[pos] += value;
                pos = (pos | (pos - 1)) + 1;
            }
        }

        void update(long min, long max, long value) {
            if (min > keys[n-1])
                return;

            if (max < keys[0])
                return;

            int l = -1, r = n-1;
            while (r - l > 1) {
                int c = (l + r) / 2;
                if (keys[c] >= min)
                    r = c;
                else
                    l = c;
            }

            int left = r;

            l = 0; r = n;
            while (r - l > 1) {
                int c = (l + r) / 2;
                if (keys[c] <= max)
                    l = c;
                else
                    r = c;
            }

            int right = l;

            if (left > right)
                return;

            left++; right++;

            updateSum(left, value);
            updateSum(right+1, -value);
        }

        long getSum(int pos) {
            long res = 0;
            while (pos > 0) {
                res += sum[pos];
                pos &= pos - 1;
            }
            return res;
        }

        public long getValueAt(int pos) {
            pos++;
            return getSum(pos);
        }

        public Summarizer(long[] keys) {
            this.n = keys.length;
            this.keys = keys;
            this.sum = new long[n + 1];
        }
    }

    class Key implements Comparable<Key> {
        int id;
        long value;
        double ans;
        public Key(int id, long value) {
            this.id = id;
            this.value = value;
        }
        public int compareTo(Key other) {
            return this.value < other.value ? -1 : 1;
        }
    }

    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] parent = new int[n];
        long[] key = new long[n];
        boolean[] isLeaf = new boolean[n];
        Arrays.fill(isLeaf, true);
        int root = -1;
        int[][] edg = new int[n][2];
        int[] edgCnt = new int[n];
        for (int i=0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            parent[i] = Integer.parseInt(st.nextToken());
            if (parent[i] != -1) {
                parent[i]--;
                isLeaf[parent[i]] = false;
            } else root = i;
            key[i] = Integer.parseInt(st.nextToken());

            if (parent[i] != -1) {
                edg[parent[i]][edgCnt[parent[i]]++] = i;
            }
        }
        int k = Integer.parseInt(br.readLine());
        Key[] keys = new Key[k];
        for (int i=0; i < k; i++) {
            keys[i] = new Key(i, Integer.parseInt(br.readLine()));
        }
        br.close();

        long[] treeKeys = new long[n];
        for (int i=0; i < n; i++)
            treeKeys[i] = key[i];
        Arrays.sort(treeKeys);

        Arrays.sort(keys);

        long[] searchKeys = new long[k];
        for (int i=0; i < k; i++)
            searchKeys[i] = keys[i].value;

        Arrays.sort(searchKeys);

        Summarizer counts = new Summarizer(searchKeys);
        Summarizer sums = new Summarizer(searchKeys);

        final int INF = 1100000000;

        int[] Q = new int[n];
        long[] QL = new long[n];
        long[] QR = new long[n];

        int qBeg = 0, qEnd = 0;
        Q[qBeg] = root;
        QL[qBeg] = -INF;
        QR[qBeg++] = INF;

        while (qEnd < qBeg) {
            int curV = Q[qEnd];
            long curL = QL[qEnd];
            long curR = QR[qEnd++];

            if (!isLeaf[curV]) {
                int pos = Arrays.binarySearch(treeKeys, key[curV]);

                counts.update(key[curV] + 1, curR, 1);
                sums.update(key[curV] + 1, curR, treeKeys[pos-1]);

                counts.update(curL, key[curV] - 1, 1);
                sums.update(curL, key[curV] - 1, treeKeys[pos+1]);
            }

            for (int i=0; i < edgCnt[curV]; i++) {
                if (key[edg[curV][i]] < key[curV]) {
                    Q[qBeg] = edg[curV][i];
                    QL[qBeg] = curL;
                    QR[qBeg++] = key[curV] - 1;
                } else {
                    Q[qBeg] = edg[curV][i];
                    QL[qBeg] = key[curV] + 1;
                    QR[qBeg++] = curR;
                }
            }
        }

        double[] answer = new double[k];

        for (int i=0; i < k; i++) {
            int pos = Arrays.binarySearch(searchKeys, keys[i].value);
            long sum = sums.getValueAt(pos);
            long cnt = counts.getValueAt(pos);
            answer[keys[i].id] = sum / (double)cnt;
        }

        for (int i=0; i < k; i++)
            System.out.println(answer[i]);
    }

    public static void main(String[] args) throws Exception {
        (new TaskC()).doMain();
    }
}