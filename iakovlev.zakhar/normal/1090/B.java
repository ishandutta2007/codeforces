import java.io.*;
import java.util.*;
import java.util.regex.*;

public class B {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = true;

    public void solve() throws IOException {
        StringBuilder body = new StringBuilder();
        ArrayList<String> refs = new ArrayList<>();
        String s;
        boolean addingRefs = false;
        while ((s = in.nextLine()) != null) {
            if (s.startsWith("\\begin")) {
                addingRefs = true;
                continue;
            }
            if (addingRefs) {
                if (s.startsWith("\\end")) {
                    break;
                }
                refs.add(s);
            } else {
                body.append(s);
                body.append('\n');
            }
        }
        body.deleteCharAt(body.length() - 1);
        s = body.toString();
        Pattern p = Pattern.compile("\\\\cite\\{[a-z]+}");
        Matcher m = p.matcher(s);
        ArrayList<String> order = new ArrayList<>();
        while (m.find()) {
            String token = m.group();
            token = token.substring(6, token.length() - 1);
            order.add(token);
        }
        HashMap<String, Integer> mp = new HashMap<>();
        for (int i = 0; i < refs.size(); i++) {
            String ref = refs.get(i);
            String token = ref.substring(9, ref.lastIndexOf('}'));
            mp.put(token, i);
        }
        boolean fail = false;
        String[] refAns = new String[refs.size()];
        for (int i = 0; i < order.size(); i++) {
            String token = order.get(i);
            fail |= mp.get(token) != i;
            refAns[i] = refs.get(mp.get(token));
        }
        System.out.println(fail ? "Incorrect" : "Correct");
        if (fail) {
            System.out.println("\\begin{thebibliography}{99}");
            for (String line : refAns) {
                System.out.println(line);
            }
            System.out.println("\\end{thebibliography}");
        }
    }

    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("input.txt"));
                out = new PrintWriter(new File("output.txt"));
            }
            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

    }

    public static void main(String[] arg) {
        new B().run();
    }
}