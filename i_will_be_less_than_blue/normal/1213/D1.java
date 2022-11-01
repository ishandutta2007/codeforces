import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.Set;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.TreeSet;
import java.util.TreeMap;
import java.util.Map;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskD1 solver = new TaskD1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD1 {
        private Set<Integer> allReachable = new TreeSet<>();

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            int k = in.i();
            int[] a = in.ia(n);
            RadixSort.radixSort(a);
            allReachable.add(0);
            Map<Integer, Integer> freq = ArrayUtil.countFrequencyOfEveryElement(a);
            Map<Integer, Map<Integer, Integer>> reachable = createAllReachable(freq);
//        reachable.forEach((e, v) -> {
//            out.printLine(e + " : " + v);
//        });
            int ans = Cons.inf;
            for (Integer e : allReachable) {
                int count = 0;
                int step = 0;
                for (int key : reachable.keySet()) {
                    if (reachable.get(key).containsKey(e)) {
                        if (freq.get(key) >= k) {
                            out.printLine(0);
                            return;
                        }
                        if (count + freq.get(key) >= k) {
                            step += (k - count) * reachable.get(key).get(e);
                            count += (k - count);
                        } else {
                            count += freq.get(key);
                            step += freq.get(key) * reachable.get(key).get(e);
                        }
                        if (count >= k) break;
                    }
                }
                if (step != 0 && count >= k) ans = Math.min(ans, step);
            }
            out.printLine(ans);
        }

        private Map<Integer, Map<Integer, Integer>> createAllReachable(Map<Integer, Integer> a) {
            Map<Integer, Map<Integer, Integer>> map = new TreeMap<>();
            a.forEach((k, v) -> {
                if (!map.containsKey(k)) map.put(k, new TreeMap<>(Comparator.reverseOrder()));
                int count = 0;
                int temp = k;
                while (temp > 0) {
                    map.get(k).put(temp, count++);
                    allReachable.add(temp);
                    temp >>= 1;
                }
                map.get(k).put(0, count);
            });
            return map;
        }

    }

    static class ArrayUtil {
        public static HashMap<Integer, Integer> countFrequencyOfEveryElement(int[] a) {
            HashMap<Integer, Integer> map = new HashMap<>();
            for (int t : a) {
                if (map.containsKey(t)) {
                    map.put(t, map.get(t) + 1);
                } else {
                    map.put(t, 1);
                }
            }
            return map;
        }

    }

    static class InputReader {
        private InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0;
        private int ptrbuf = 0;

        public InputReader(InputStream is) {
            this.is = is;
        }

        private int readByte() {
            if (lenbuf == -1) throw new InputMismatchException();
            if (ptrbuf >= lenbuf) {
                ptrbuf = 0;
                try {
                    lenbuf = is.read(inbuf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (lenbuf <= 0) return -1;
            }
            return inbuf[ptrbuf++];
        }

        public int[] ia(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = i();
            return a;
        }

        public int i() {
            int num = 0, b;
            boolean minus = false;
            while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-')) ;
            if (b == '-') {
                minus = true;
                b = readByte();
            }

            while (true) {
                if (b >= '0' && b <= '9') {
                    num = num * 10 + (b - '0');
                } else {
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

    }

    static class RadixSort {
        public static int[] radixSort(int[] f) {
            return radixSort(f, f.length);
        }

        public static int[] radixSort(int[] f, int n) {
            // credits uwi
            int[] to = new int[n];
            {
                int[] b = new int[65537];
                for (int i = 0; i < n; i++) b[1 + (int) (f[i] & 0xffff)]++;
                for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
                for (int i = 0; i < n; i++) to[b[(int) (f[i] & 0xffff)]++] = f[i];
                int[] d = f;
                f = to;
                to = d;
            }
            {
                int[] b = new int[65537];
                for (int i = 0; i < n; i++) b[1 + (int) (f[i] >>> 16 & 0xffff)]++;
                for (int i = 1; i <= 65536; i++) b[i] += b[i - 1];
                for (int i = 0; i < n; i++) to[b[(int) (f[i] >>> 16 & 0xffff)]++] = f[i];
                int[] d = f;
                f = to;
                to = d;
            }
            return f;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void close() {
            writer.close();
        }

        public void printLine(int i) {
            writer.println(i);
        }

    }

    static class Cons {
        public static final int inf = (int) 1e9 + 100;

    }
}