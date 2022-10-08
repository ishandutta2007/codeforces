import java.util.*;
import java.io.*;

public class TaskB {
    final int COMEIN = 0;
    final int GOT1 = 1;
    final int GOT2 = 2;
    final int GOT3 = 3;

    class Event implements Comparable<Event> {
        int manId;
        long time;
        int outcome;
        public Event(int manId, long time, int outcome) {
            this.manId = manId;
            this.time = time;
            this.outcome = outcome;
        }
        public int compareTo(Event other) {
            if (this.time == other.time) return 0;
            return (this.time < other.time ? -1 : 1);
        }
    }

    public void doMain() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[] k = new long[3];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i=0; i < 3; i++)
            k[i] = Integer.parseInt(st.nextToken());
        long[] t = new long[3];
        st = new StringTokenizer(br.readLine());
        for (int i=0; i < 3; i++)
            t[i] = Integer.parseInt(st.nextToken());

        PriorityQueue<Event> events = new PriorityQueue<Event>();
        int n = Integer.parseInt(br.readLine());
        int[] comeT = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i=0; i < n;i ++) {
            comeT[i] = Integer.parseInt(st.nextToken());
            events.add(new Event(i, comeT[i], COMEIN));
        }
        br.close();

        int[][] waitQ = new int[3][n];
        int[] qBeg = new int[3];
        int[] qEnd = new int[3];

        long res = 0;
        while (!events.isEmpty()) {
            Event cur = events.poll();
            if (cur.outcome == COMEIN) {
                if (k[0] > 0) {
                    k[0]--;
                    events.add(new Event(cur.manId, cur.time + t[0], GOT1));
                } else {
                    waitQ[0][qBeg[0]++] = cur.manId;
                }
            } else if (cur.outcome == GOT1) {
                if (k[1] > 0) {
                    k[1]--;
                    events.add(new Event(cur.manId, cur.time + t[1], GOT2));
                } else {
                    waitQ[1][qBeg[1]++] = cur.manId;
                }
                k[0]++;
                if (qEnd[0] < qBeg[0]) {
                    k[0]--;
                    events.add(new Event(waitQ[0][qEnd[0]++], cur.time + t[0], GOT1));
                }
            } else if (cur.outcome == GOT2) {
                if (k[2] > 0) {
                    k[2]--;
                    events.add(new Event(cur.manId, cur.time + t[2], GOT3));
                } else {
                    waitQ[2][qBeg[2]++] = cur.manId;
                }
                k[1]++;
                if (qEnd[1] < qBeg[1]) {
                    k[1]--;
                    events.add(new Event(waitQ[1][qEnd[1]++], cur.time + t[1], GOT2));
                }
            } else {
                res = Math.max(res, cur.time - comeT[cur.manId]);
                k[2]++;
                if (qEnd[2] < qBeg[2]) {
                    k[2]--;
                    events.add(new Event(waitQ[2][qEnd[2]++], cur.time + t[2], GOT3));
                }
            }
        }

        System.out.println(res);
    }

    public static void main(String[] args) throws Exception {
        new TaskB().doMain();
    }
}