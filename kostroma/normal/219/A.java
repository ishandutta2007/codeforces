
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;// 6/30/12 11:56 AM
// by Abrackadabra

public class Sol {
    public static void main(String[] args) throws IOException {
        //if (args.length > 0 && args[0].equals("Abra")||true ) debugMode = true;
        new Sol().run();
        /*new Thread(null, new Runnable() {
            public void run() {
                try {
                    new H().run();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }, "1", 1 << 24).start();*/
    }

    int IOMode = 0; //0 - consoleIO, 1 - <taskName>.in/out, 2 - input.txt/output.txt, 3 - test case generator
    String taskName = "";
    boolean testBasedProblem = false;

    public class Pair<F,S> implements Comparable<Pair<F,S>> {

        public F first;
        public S second;

        public Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }

        @Override
        @SuppressWarnings(value = "unchecked")
        public int compareTo(Pair<F, S> other) {
            int res = ((Comparable<F>)first).compareTo(other.first);
            if(res != 0)
                return res;
            return ((Comparable<S>)second).compareTo(other.second);
        }
    }

    String s;
    String ans;
    int k;
    int num[]=new int[300];

    void solve() throws IOException {
        k=nextInt();
        s=nextString();
        for (int i=0; i<s.length(); i++)
            num[s.charAt(i)]++;
        for (char c='a'; c<='z'; ++c){
           // out.println(num[c]);
            if ((num[c]%k)!=0){
                out.print("-1");
                return;
            }
            for (int i=0; i<num[c]; i+=k) {
                    ans+=c;
            }
        }
        for (int i=0; i<k; i++){
            for (int j=4; j<ans.length(); ++j)
                out.print(ans.charAt(j));
        }
    }

    long startTime = System.nanoTime(), tempTime = startTime, finishTime = startTime;
    long startMem = Runtime.getRuntime().totalMemory(), finishMem = startMem;
    int testIndex;

    void run() throws IOException {
        init();
        if (debugMode) {
            con.println("Start");
            con.println("Console:");
        }

        int tests = testBasedProblem ? nextInt() : 1;
        for (testIndex = 1; testIndex <= tests; testIndex++)
            solve();

        finishTime = System.nanoTime();
        finishMem = Runtime.getRuntime().totalMemory();
        out.flush();
        if (debugMode) {
            int maxSymbols = 1000;
            BufferedReader tbr = new BufferedReader(new FileReader("input.txt"));
            char[] a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File input:");
                con.println(a);
                if (a[maxSymbols - 1] != 0) con.println("...");
            }
            tbr = new BufferedReader(new FileReader("output.txt"));
            a = new char[maxSymbols];
            tbr.read(a);
            if (a[0] != 0) {
                con.println("File output:");
                con.println(a);
                if (a[maxSymbols - 1] != 0) con.println("...");
            }
            con.println("Execution time: " + (finishTime - startTime) / 1000000000.0 + " sec");
            con.println("Used memory:    " + (finishMem - startMem) + " bytes");
            con.println("Total memory:   " + Runtime.getRuntime().totalMemory() + " bytes");
        }
    }

    boolean tick(double x) {
        if (System.nanoTime() - tempTime > x * 1e9) {
            tempTime = System.nanoTime();
            con.println("Tick at " + (tempTime - startTime) / 1000000000 + " sec");
            con.print("   ");
            return true;
        }
        return false;
    }

    static boolean debugMode = false;
    PrintStream con = System.out;

    void init() throws IOException {
        if (debugMode && IOMode != 3) {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new FileWriter("output.txt"));
        } else
            switch (IOMode) {
                case 0:
                    br = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(System.out);
                    break;
                case 1:
                    br = new BufferedReader(new FileReader(taskName + ".in"));
                    out = new PrintWriter(new FileWriter(taskName + ".out"));
                    break;
                case 2:
                    br = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    out = new PrintWriter(new FileWriter("input.txt"));
                    break;
            }
        if (!debugMode)
            con = new PrintStream(new OutputStream() {
                public void write(int b) throws IOException {
                } // to /dev/null
            });
        if ((IOMode == 1 && taskName.length() == 0) || (IOMode != 1 && taskName.length() != 0)) {
            System.err.println("Leha, check IO settings");
            System.err.flush();
            System.exit(0);
        }
    }

    BufferedReader br;
    PrintWriter out;
    StringTokenizer in;

    boolean hasMoreTokens() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null) return false;
            in = new StringTokenizer(line);
        }
        return true;
    }

    String nextString() throws IOException {
        return hasMoreTokens() ? in.nextToken() : null;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextString());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextString());
    }
}