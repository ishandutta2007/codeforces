import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskE {
    static final int mod = 1000000007;

    SegmentTreeFastIntervalAddSumMod tree;

    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s1 = in.nextToken();
        String s2 = in.nextToken();
        String s3 = in.nextToken();
        String s = s1 + "\1" + s2 + "\2" + s3 + "\3";
        SuffixTree.Node root = SuffixTree.buildSuffixTree(s);
        tree = new SegmentTreeFastIntervalAddSumMod((1 << 19), mod);
        dfs(root, s1.length(), s1.length() + s2.length() + 1, s1.length() + s2.length() + s3.length() + 2);
        for (int i = 1; i <= s1.length() && i <= s2.length() && i <= s3.length(); ++i) {
            out.print(tree.get(i) + " ");
        }
        out.printLine();
    }

    public int[] dfs(SuffixTree.Node node, int i1, int i2, int i3) {
        if (node.begin <= i1 && i1 < node.end) {
            return new int[]{1, 0, 0};
        }
        if (node.begin <= i2 && i2 < node.end) {
            return new int[]{0, 1, 0};
        }
        if (node.begin <= i3 && i3 < node.end) {
            return new int[]{0, 0 ,1};
        }
        int[] cnts = new int[3];
        for (char f = 0; f < SuffixTree.alphabetSize; f++) {
            if (node.children[f] != null) {
                int[] _cnts = dfs(node.children[f], i1, i2, i3);
                for (int i = 0; i < 3; ++i)
                    cnts[i] += _cnts[i];
            }
        }
        long val = 1;
        for (int i = 0; i < 3; ++i) {
            val *= cnts[i];
            val %= mod;
        }
        if (val != 0) {
            Assert.assertTrue(node.end <= i1);
            tree.modifyAdd(1 + node.depth, 1 + node.depth + node.end  - node.begin - 1, (int) val);
        }
        return cnts;
    }
}

class SegmentTreeFastIntervalAddSumMod {
    final int n;
    final long[] t;
    final long[] m;
    final boolean[] h;
    final long[] q;
    final int mod;

    public SegmentTreeFastIntervalAddSumMod(int n, int mod) {
        this.n = n;
        this.mod = mod;
        t = new long[2 * n];
        m = new long[2 * n];
        h = new boolean[2 * n];
        q = new long[2 * n];
        for (int i = n; i < 2 * n; i++)
            q[i] = 1;
        for (int i = 2 * n - 1; i > 1; i -= 2)
            q[i >> 1] = q[i] + q[i ^ 1];
    }

    void modifierHelper(int i, long p) {
        t[i] += p * q[i];
        t[i] %= mod;
        m[i] += p;
        m[i] %= mod;
        h[i] = true;
    }

    void pop(int i) {
        if (h[i >> 1]) {
            t[i >> 1] = t[i] + t[i ^ 1] + m[i >> 1] * q[i >> 1];
            t[i >> 1] %= mod;
        } else {
            t[i >> 1] = t[i] + t[i ^ 1];
            t[i >> 1] %= mod;
        }
    }

    void popUp(int i) {
        for (; i > 1; i >>= 1)
            pop(i);
    }

    void push(int i) {
        if (h[i >> 1]) {
            modifierHelper(i, m[i >> 1]);
            modifierHelper(i ^ 1, m[i >> 1]);
            h[i >> 1] = false;
            m[i >> 1] = 0;
        }
    }

    void pushDown(int i) {
        int k;
        for (k = 0; (i >> k) > 0; k++)
            ;
        for (k -= 2; k >= 0; k--)
            push(i >> k);
    }

    public void modifyAdd(int a, int b, int v) {
        a += n;
        b += n;
        pushDown(a);
        pushDown(b);
        int ta = a;
        int tb = b;

        for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
            if ((a & 1) != 0)
                modifierHelper(a, v);
            if ((b & 1) == 0)
                modifierHelper(b, v);
        }

        popUp(ta);
        popUp(tb);
    }

    public int querySum(int a, int b) {
        a += n;
        b += n;
        pushDown(a);
        pushDown(b);

        long res = 0;
        for (; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
            if ((a & 1) != 0)
                res += t[a];
            if ((b & 1) == 0)
                res += t[b];
            res %= mod;
        }
        return (int)(res % mod);
    }

    public int get(int i) {
        return querySum(i, i);
    }

}

class InputReader {
    private InputStream stream;
    private byte[] buffer = new byte[10000];
    private int cur;
    private int count;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public static boolean isSpace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

    public int read() {
        if (count == -1) {
            throw new InputMismatchException();
        }
        try {
            if (cur >= count) {
                cur = 0;
                count = stream.read(buffer);
                if (count <= 0)
                    return -1;
            }
        } catch (IOException e) {
            throw new InputMismatchException();
        }
        return buffer[cur++];
    }

    public int readSkipSpace() {
        int c;
        do {
            c = read();
        } while (isSpace(c));
        return c;
    }

    public String nextToken() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (!isSpace(c)) {
            sb.append((char) c);
            c = read();
        }
        return sb.toString();
    }

}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) {
                writer.print(' ');
            }
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

class SuffixTree {
    public static String alphabet = "abcdefghijklmnopqrstuvwxyz\1\2\3";
    public static int alphabetSize = alphabet.length();

    public static class Node {
        public int depth; // from start of suffix
        public int begin;
        public int end;
        public Node[] children;
        public Node parent;
        public Node suffixLink;

        Node(int begin, int end, int depth, Node parent) {
            children = new Node[alphabetSize];
            this.begin = begin;
            this.end = end;
            this.parent = parent;
            this.depth = depth;
        }

        boolean contains(int d) {
            return depth <= d && d < depth + (end - begin);
        }
    }

    public static Node buildSuffixTree(String s) {
        int n = s.length();
        byte[] a = new byte[n];
        for (int i = 0; i < n; i++) {
            a[i] = (byte) alphabet.indexOf(s.charAt(i));
        }
        Node root = new Node(0, 0, 0, null);
        Node cn = root;
        // root.suffixLink must be null, but that way it gets more convenient
        // processing
        root.suffixLink = root;
        Node needsSuffixLink = null;
        int lastRule = 0;
        int j = 0;
        for (int i = -1; i < n - 1; i++) {// strings s[j..i] already in tree,
            // delta s[i+l] to it.
            int cur = a[i + 1]; // last char of current string
            for (; j <= i + 1; j++) {
                int curDepth = i + 1 - j;
                if (lastRule != 3) {
                    cn = cn.suffixLink != null ? cn.suffixLink : cn.parent.suffixLink;
                    int k = j + cn.depth;
                    while (curDepth > 0 && !cn.contains(curDepth - 1)) {
                        k += cn.end - cn.begin;
                        cn = cn.children[a[k]];
                    }
                }
                if (!cn.contains(curDepth)) { // explicit node
                    if (needsSuffixLink != null) {
                        needsSuffixLink.suffixLink = cn;
                        needsSuffixLink = null;
                    }
                    if (cn.children[cur] == null) {
                        // no extension - delta leaf
                        cn.children[cur] = new Node(i + 1, n, curDepth, cn);
                        lastRule = 2;
                    } else {
                        cn = cn.children[cur];
                        lastRule = 3; // already exists
                        break;
                    }
                } else { // implicit node
                    int end = cn.begin + curDepth - cn.depth;
                    if (a[end] != cur) { // split implicit node here
                        Node newn = new Node(cn.begin, end, cn.depth, cn.parent);
                        newn.children[cur] = new Node(i + 1, n, curDepth, newn);
                        newn.children[a[end]] = cn;
                        cn.parent.children[a[cn.begin]] = newn;
                        if (needsSuffixLink != null) {
                            needsSuffixLink.suffixLink = newn;
                        }
                        cn.begin = end;
                        cn.depth = curDepth;
                        cn.parent = newn;
                        cn = needsSuffixLink = newn;
                        lastRule = 2;
                    } else if (cn.end != n || cn.begin - cn.depth < j) {
                        lastRule = 3;
                        break;
                    } else {
                        lastRule = 1;
                    }
                }
            }
        }
        root.suffixLink = null;
        return root;
    }

}

class Assert {

    public static void assertTrue(boolean flag) {
        if (!flag)
            throw new AssertionError();
    }

}