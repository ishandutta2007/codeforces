import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.function.Consumer;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.ArrayList;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            List<Integer> evenXorList = new ArrayList<>();
            List<Integer> oddXorList = new ArrayList<>();
            List<Integer> evenNumbers = new ArrayList<>();
            List<Integer> oddNumbers = new ArrayList<>();
            for (int i = 0; i < 14; i++) {
                if ((i & 1) == 1) oddNumbers.add(i);
                else evenNumbers.add(i);
            }
            generateAllCombinationValue(evenXorList, evenNumbers);
            generateAllCombinationValue(oddXorList, oddNumbers);
            out.print("? ");
            Consumer<Integer> c = e -> out.print(e + " ");
            evenXorList.forEach(c);
            out.flush();
            int first = in.i();
            out.println();
            out.print("? ");
            oddXorList.forEach(c);
            out.flush();
            int second = in.i();
            Set<Integer> firstSet = new HashSet<>();
            Set<Integer> secondSet = new HashSet<>();
            evenXorList.forEach(e -> {
                firstSet.add(e ^ first);
            });
            oddXorList.forEach(e -> {
                secondSet.add(e ^ second);
            });
            firstSet.retainAll(secondSet);
            if (firstSet.size() != 1) {
                throw new IllegalArgumentException();
            }
            out.println("! ");
            firstSet.forEach(c);
        }

        private void generateAllCombinationValue(List<Integer> even, List<Integer> evenNumbers) {
            for (int i = 0; i < (1 << 7); i++) {
                if (even.size() == 100) return;
                int value = 0;
                for (int j = 0; j < 7; j++) {
                    if ((i & (1 << j)) > 0) {
                        value |= (1 << evenNumbers.get(j));
                    }
                }
                if (value != 0) even.add(value);
            }
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