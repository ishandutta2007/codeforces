import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Vector;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.Comparator;
import java.util.Stack;
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
        TaskD2 solver = new TaskD2();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD2 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.next();
            int n = s.length();
            Stack<TaskD2.pair> stack = new Stack<>();
            List<TaskD2.pair> answer = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (s.charAt(i) == '0') {
                    if (!stack.isEmpty() && stack.peek().c == '1') {
                        TaskD2.pair p = stack.pop();
                        answer.add(p);
                        answer.add(new TaskD2.pair('0', i));
                    } else {
                        stack.add(new TaskD2.pair('0', i));
                    }
                } else {
                    stack.add(new TaskD2.pair('1', i));
                }
            }
            while (!stack.isEmpty()) {
                TaskD2.pair p = stack.pop();
                answer.add(new TaskD2.pair('0', p.ind));
            }
            answer.sort(Comparator.comparing(e -> e.ind));
            answer.forEach(e -> out.print(e.c));
        }

        static class pair {
            char c;
            int ind;

            pair(char c, int ind) {
                this.c = c;
                this.ind = ind;
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

    }
}