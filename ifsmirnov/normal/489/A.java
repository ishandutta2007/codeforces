import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
	    init();

        int n = nextInt();

        int[] a = new int[n];
        int[] b = new int[n];
        List<Integer> result = new ArrayList<Integer>();
        for (int i = 0; i < n; ++i) {
            a[i] = nextInt();
            b[i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            int minIdx = i;
            for (int j = i; j < n; ++j) {
                if (b[j] == 0 && (b[minIdx] == 1 || a[j] < a[minIdx])) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                result.add(i);
                result.add(minIdx);
                int t = a[i];
                a[i] = a[minIdx];
                a[minIdx] = t;
            }
        }

        out.print(result.size() / 2 + "\n");
        for (int i = 0; i < result.size() / 2; ++i) {
            out.print(result.get(i*2) + " " + result.get(i*2+1) + "\n");
        }

        br.close();
        out.close();
    }

    static BufferedReader br;
    static StringTokenizer st;
    static PrintWriter out;

    public static void init() throws IOException {
        InputStream input = System.in;
        PrintStream output = System.out;
        /*File file = new File("input.txt");
        System.out.println("init");
        if (file.exists() && file.canRead()) {
            System.out.println("file is opened");
            input = new FileInputStream(file);
            //output = new PrintStream("output.txt");
        }
        */
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
    }

    static boolean hasNext() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) {
                return false;
            }
            st = new StringTokenizer(line);
        }
        return true;
    }

    static String next() throws IOException {
        return hasNext() ? st.nextToken() : null;
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}