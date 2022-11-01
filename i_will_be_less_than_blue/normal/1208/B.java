import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.Set;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Stream;
import java.util.Map;
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
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.i();
            int[] a = in.ia(n);
            Map<Integer, Integer> freq = ArrayUtil.countFrequencyOfEveryElement(a);
            boolean all1 = freq.values().stream().allMatch(e -> e == 1);
            if (all1) {
                out.println(0);
                return;
            }
            Map<Integer, List<Integer>> indexList = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int u = a[i];
                if (freq.get(u) > 1) {
                    if (!indexList.containsKey(u)) {
                        indexList.put(u, new ArrayList<>());
                    }
                    indexList.get(u).add(i);
                }
            }
            for (int u : indexList.keySet()) {
                indexList.get(u).sort(Comparator.reverseOrder());
            }

            int maxIndexI = calculateMaxIndex(a, n);
            int ans = Cons.inf;
            for (int i = 0; i <= maxIndexI; i++) {
                if (freq.get(a[i]) > 1) {
                    int mindInd = i;
                    for (int j = n - 1; j >= i; j--) {
                        if (freq.get(a[j]) > 1) {
                            if (a[i] == a[j] && freq.get(a[i]) == 2) continue;
                            int firstOccurance = indexList.get(a[j]).get(indexList.get(a[j]).size() - 1);
                            int secondOccur = indexList.get(a[j]).get(1);
                            if (firstOccurance < i) {
                                mindInd = Math.max(mindInd, j);
                            } else {
                                mindInd = Math.max(mindInd, secondOccur);
                            }
                        }
                    }
                    ans = Math.min(ans, mindInd - i + 1);
                }
            }
            out.println(ans);
        }

        private int calculateMaxIndex(int[] a, int n) {
            int ind = 0;
            Set<Integer> set = new HashSet<>();
            for (; ind < n; ind++) {
                if (!set.add(a[ind])) {
                    return ind;
                }
            }
            return -1;
        }

    }

    static class Cons {
        public static final int inf = (int) 1e9 + 100;

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
}