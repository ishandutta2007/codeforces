
import java.io.*;
import java.util.*;
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

    int n, m;
    int rights[], lefts[];
    TreeSet<Pair<Integer, Integer>> segs = new TreeSet<Pair<Integer, Integer>>();
    int where[] = new int[1000500];
    int Size(int l, int r){
        if (l==1)
            return r;
        if (r==n)
            return n-l+1;
        return (r-l+2)/2;
    }

    void solve() throws IOException {
        n=nextInt();
        m=nextInt();
        lefts=new int[n+1];
        rights=new int[n+1];
        segs.add(new Pair<Integer, Integer>( -Size(1,n), 1));
        lefts[1]=n;
        rights[n]=1;
        for (int i=0; i<m; ++i){
            //System.err.println(segs.size());
            /*System.err.println(i);
            for (int j=1; j<=n; ++j)
                if (lefts[j]!=0)
                    System.err.println(j + " " + lefts[j]);   */

            int t, num;
            t=nextInt();
            num=nextInt();
            if (t==1){
                Pair <Integer, Integer> cur = segs.first();
                segs.remove(segs.first());
                int l=cur.second;
                int r=lefts[l];
                int pos=(l+r)/2;
                if (l==1)
                    pos=1;
                else
                    if (r==n)
                        pos=n;
                where[num]=pos;
                out.println(pos);
                lefts[l]=0;
                rights[r]=0;
                //System.err.println(l + " " + r + " " + pos);
                if (pos > l){
                    lefts[l]=pos-1;
                    rights[pos-1]=l;
                    segs.add(new Pair<Integer, Integer>(-Size(l, pos-1), l ));
                }
                if (pos < r){
                    lefts[pos+1]=r;
                    rights[r]=pos+1;
                    segs.add(new Pair<Integer, Integer>(-Size(pos+1, r), pos+1 ));
                }
            }
            else{
                int pos=where[num];
                where[num]=0;
                int l=pos, r=pos;
                if (pos+1<=n && lefts[pos+1]!=0){
                    r=lefts[pos+1];
                    segs.remove(new Pair<Integer, Integer>( -Size(pos+1, r), pos+1  ));
                    rights[lefts[pos+1]]=0;
                    lefts[pos+1]=0;
                }
                if (pos-1>=1 && rights[pos-1]!=0){
                    l=rights[pos-1];
                    segs.remove(new Pair<Integer, Integer>( -Size(l, pos-1), rights[pos-1]));
                    lefts[rights[pos-1]]=0;
                    rights[pos-1]=0;
                }
                segs.add(new Pair<Integer, Integer>( -Size(l,r), l ));
                lefts[l]=r;
                rights[r]=l;
            }
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