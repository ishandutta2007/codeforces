import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        long n = in.nextLong();

        long ans = count(n);
        out.println(ans);
    }

    long count(long n) {
        if (n % 3 != 0) {
            return 0;
        }

        n /= 3;

        long r = 0;
        long maxx = cuberoot(n);

        long[] divs = factor(n);

        for (int i = 0; i < divs.length && divs[i] <= maxx; i++) {
            long x = divs[i];
            long nab = n / x;
            long maxy = sqroot(nab);
            for (int j = i; j < divs.length && divs[j] <= maxy; j++) {
                long y = divs[j];
                if (nab % y != 0) {
                    continue;
                }
                long z = nab / y;

                if ((x + y + z) % 2 != 0) {
                    continue;
                }

                long a = (x + y - z) / 2;
                long b = (x - y + z ) / 2;
                long c = (-x + y + z) / 2;

                if (a > 0 && b > 0 && c > 0 && (a + b) * (a + c) * (b + c) == n) {
//                    System.out.println(a + " " + b + " " + c);
                    if (a == b && a == c) {
                        r++;
                    } else if (a == b || a == c || b == c) {
                        r += 3;
                    } else {
                        r += 6;
                    }
                }
            }
        }

        return r;
    }

    long[] factor(long n) {
        ArrayList<Long> ans = new ArrayList<Long>();
        for (long x = 1; x * x <= n; x++) {
            if (n % x == 0) {
                ans.add(x);
                if (n / x != x) {
                    ans.add(n / x);
                }
            }
        }
        long[] r = new long[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            r[i] = ans.get(i);
        }
        Arrays.sort(r);
        return r;
    }

    long cuberoot(long n) {
        long l = 0;
        long r = Math.round(Math.sqrt(n));
        while (l < r - 1) {
            long m = (l + r) / 2;
            if (m * m * m <= n) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }

    long sqroot(long n) {
        long l = 0;
        long r = Math.round(Math.sqrt(n)) + 10;
        while (l < r - 1) {
            long m = (l + r) / 2;
            if (m * m <= n) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }

    public void run() {
        try {
            in = new FastScanner(System.in);
            out = new PrintWriter(System.out);

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] arg) {
        new C().run();
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream in) throws IOException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                    return "";
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
    }
}