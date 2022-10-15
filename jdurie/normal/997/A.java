import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main implements Runnable
{
    boolean multiple = false;

    @SuppressWarnings("Duplicates")
    void solve() throws Exception
    {
        long n = sc.nextLong();
        long x = sc.nextLong();
        long y = sc.nextLong();
        boolean[] arr = new boolean[(int)n];
        String s = sc.nextToken();
        for (int i = 0; i < n; i++)
            arr[i] = s.charAt(i) == '1';
        long a = (arr[0]) ? 0 : 1;
        for (int i = 0; i < n - 1; i++)
            if (arr[i] && !arr[i + 1])
                a++;
            
        if (a == 0)
            System.out.println(0);
        else 
            System.out.println(min((a * y), (a - 1) * x + y));
    }

    long inv(long a, long b)
    {
        return 1 < a ? b - inv(b % a, a) * b / a : 1;
    }

    long gcd(long a, long b)
    {
        return a == 0 ? b : gcd(b % a, a);
    }

    long lcm(long a, long b) { return (a * b) / gcd(a , b); }

    class SegNode
    {
        int max;
        int L, R;
        SegNode left = null, right = null;

        int query(int queryL, int queryR)
        {
            if (queryL == L && queryR == R)
                return max;

            int leftAns = Integer.MIN_VALUE, rightAns = Integer.MIN_VALUE;
            if (left != null && queryL <= left.R)
                leftAns = left.query(queryL, min(queryR, left.R));
            if (right != null && queryR >= right.L)
                rightAns = right.query(max(queryL, right.L), queryR);

            return max(leftAns, rightAns);
        }

        SegNode(int[] arr, int l, int r)
        {
            L = l;
            R = r;
            max = arr[l];

            if (l == r) return;

            int mid = (l + r) / 2;
            left = new SegNode(arr, l, mid);
            right = new SegNode(arr, mid + 1, r);
            max = max(left.max, right.max);
        }
    }

    class Node implements Comparable<Node>
    {
        Node()
        {
        }

        @Override
        public int compareTo(Node o)
        {
            return 0;
        }
    }

    void print(int[] arr)
    {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    @Override
    public void run()
    {
        try
        {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            sc = new FastScanner(in);
            if (multiple)
            {
                int q = sc.nextInt();
                for (int i = 0; i < q; i++)
                    solve();
            }
            else
                solve();
        }
        catch (Throwable uncaught)
        {
            Main.uncaught = uncaught;
        }
        finally
        {
            out.close();
        }
    }

    public static void main(String[] args) throws Throwable
    {
        Thread thread = new Thread(null, new Main(), "", (1 << 26));
        thread.start();
        thread.join();
        if (Main.uncaught != null) {
            throw Main.uncaught;
        }
    }

    static Throwable uncaught; BufferedReader in; FastScanner sc; PrintWriter out;
}

class FastScanner
{
    BufferedReader in;
    StringTokenizer st;

    public FastScanner(BufferedReader in)
    {
        this.in = in;
    }

    public String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }

    public int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }
}