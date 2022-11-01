import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Stack;
import java.util.Vector;
import java.util.Map;
import java.util.Map.Entry;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author unknown
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        CBracketSequencesConcatenationProblem solver = new CBracketSequencesConcatenationProblem();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBracketSequencesConcatenationProblem {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.i();
            String[] s = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.next();
            }
            long full = 0;
            Map<Integer, Integer> close = new HashMap<>();
            Map<Integer, Integer> open = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String cur = s[i];
                Stack<Character> st = new Stack<>();
                for (int j = 0; j < cur.length(); j++) {
                    if (cur.charAt(j) == ')') {
                        if (!st.isEmpty() && st.peek() == '(') st.pop();
                        else st.push(')');
                    } else {
                        st.push('(');
                    }
                }
                if (st.isEmpty()) {
                    ++full;
                } else {
                    boolean foundCl = false, foundOp = false;
                    int countOpen = 0, countClose = 0;
                    while (!st.isEmpty()) {
                        Character c = st.pop();
                        if (c.equals('(')) {
                            foundOp = true;
                            ++countOpen;
                        } else {
                            ++countClose;
                            foundCl = true;
                        }
                    }
                    if (foundCl && !foundOp) {
                        close.put(countClose, close.getOrDefault(countClose, 0) + 1);
                    } else if (!foundCl && foundOp) {
                        open.put(countOpen, open.getOrDefault(countOpen, 0) + 1);
                    }
                }
            }
            long ans = full * full;
            for (Map.Entry<Integer, Integer> o : open.entrySet()) {
                if (close.containsKey(o.getKey())) {
                    ans += (long) o.getValue() * (long) close.get(o.getKey());
                }
            }
            out.printLine(ans);
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

        private boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }

        private int skip() {
            int b;
            while ((b = readByte()) != -1 && isSpaceChar(b)) ;
            return b;
        }

        public String next() {
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
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

        public void printLine(long i) {
            writer.println(i);
        }

    }
}