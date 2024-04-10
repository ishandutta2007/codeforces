import java.util.List;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.ArrayList;
import java.util.Collections;
import java.io.InputStream;
import java.io.BufferedInputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(new BufferedInputStream(inputStream));
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        List<ComparablePair<RationalLong, Long>> events = new ArrayList<ComparablePair<RationalLong, Long>>();
        long cur = 0;
        long prev = 0;
        for (int i = 0; i < n; ++i) {
            long ki = in.nextLong();
            long bi = in.nextLong();
            if (ki == 0) continue;
            if (ki < 0) {
                cur += ki;
                prev += ki;
                ki = -ki;
                bi = -bi;
            }
            events.add(new ComparablePair<RationalLong, Long>(new RationalLong(-bi, ki), ki));
        }
        Random random = new Random(0xdead);
        Collections.shuffle(events, random);
        Collections.sort(events);        
        int res = 0;
        RationalLong pt = null;
        for (int index = 0; index < events.size(); ++index) {
            RationalLong time = events.get(index).first;
            if (!time.equals(pt)) {
                if (cur != prev) {
                    ++res;
                    prev = cur;
                }
                pt = time;
            }
            long delta = events.get(index).second;
            cur += delta;
        }
        if (cur != prev) {
            ++res;
        }
        out.println(res);
    }
}

class ComparablePair<P extends Comparable, Q extends Comparable>
        extends Pair<P, Q> implements Comparable<Pair<P, Q>> {

    public ComparablePair() {
    }

    public ComparablePair(P first, Q second) {
        super(first, second);
    }

    @Override
    public int compareTo(Pair<P, Q> other) {
        int valP = first.compareTo(other.first);
        if (valP != 0) return valP;
        return second.compareTo(other.second);
    }
}

class RationalLong implements Comparable<RationalLong> {
    long numerator;
    long denominator;

    public RationalLong() {
        numerator = 0;
        denominator = 1;
    }

    public RationalLong(long numerator) {
        this.numerator = numerator;
        denominator = 1;
    }

    public RationalLong(long numerator, long denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
    }

    public int compareTo(RationalLong r) {
        long value = numerator * r.denominator - denominator * r.numerator;
        if (value < 0) return -1;
        if (value > 0) return 1;
        return 0;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        RationalLong that = (RationalLong) o;

        long value = numerator * that.denominator - denominator * that.numerator;

        return value == 0;
    }

    @Override
    public int hashCode() {
        int result = (int) (numerator ^ (numerator >>> 32));
        result = 31 * result + (int) (denominator ^ (denominator >>> 32));
        return result;
    }
}

class Pair<P, Q> {
    public P first;
    public Q second;

    public Pair() {
    }

    public Pair(P first, Q second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Pair pair = (Pair) o;

        if (first != null ? !first.equals(pair.first) : pair.first != null) return false;
        if (second != null ? !second.equals(pair.second) : pair.second != null) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }
}