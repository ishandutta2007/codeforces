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
import java.util.ArrayList;
import java.util.HashSet;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final long X1 = 2184057L;
        static final long X2 = 4242421L;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            int n = in.nextInt();
            HashMap<String, Set<String>> queriesPerHost = new HashMap<>();
            for (int i = 0; i < n; ++i) {
                String s = in.nextToken();
                int hostStart = 7; // http://
                int hostEnd = hostStart;
                while (hostEnd < s.length() && s.charAt(hostEnd) != '/')
                    ++hostEnd;
                String host = s.substring(hostStart, hostEnd);
                String query = s.substring(hostEnd);
                if (!queriesPerHost.containsKey(host))
                    queriesPerHost.put(host, new HashSet<String>());
                queriesPerHost.get(host).add(query);
            }

            // Shard by additional hash to avoid anti-Java-hash tests.
            HashMap<Long, HashMap<Long, ArrayList<String>>> reverseIndex = new HashMap<>();
            for (String host : queriesPerHost.keySet()) {
                Set<String> queries = queriesPerHost.get(host);
                long h = getHash(queries);
                long javaH = queries.hashCode();
                if (!reverseIndex.containsKey(h))
                    reverseIndex.put(h, new HashMap<Long, ArrayList<String>>());
                if (!reverseIndex.get(h).containsKey(javaH))
                    reverseIndex.get(h).put(javaH, new ArrayList<String>());
                reverseIndex.get(h).get(javaH).add(host);
            }
            ArrayList<ArrayList<String>> res = new ArrayList<>();
            for (HashMap<Long, ArrayList<String>> subMap : reverseIndex.values())
                for (ArrayList<String> hosts : subMap.values()) {
                    if (hosts.size() < 2) continue;
                    res.add(hosts);
                }
            out.printLine(res.size());
            for (ArrayList<String> hosts : res) {
                for (String host : hosts)
                    out.print("http://" + host + " ");
                out.printLine();
            }
        }

        private long getHash(Set<String> queries) {
            ArrayList<String> q = new ArrayList<>(queries);
            Collections.sort(q);
            long res = 1;
            for (String s : q) {
                long cur = 1;
                for (int i = 0; i < s.length(); ++i)
                    cur = cur * X1 + s.charAt(i);
                res = res * X2 + cur;
            }
            return res;
        }

    }

    static class InputReader {
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

        public int nextInt() {
            int sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
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
}