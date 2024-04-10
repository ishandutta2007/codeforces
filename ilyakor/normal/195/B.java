import java.util.List;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.io.InputStream;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;

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
        PrintWriter out = new PrintWriter(new BufferedOutputStream(outputStream));
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        List<ii> order = new ArrayList<ii>();
        //in = new Scanner(new BufferedInputStream(System.in));
        //out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = in.nextInt();
        int m = in.nextInt();
        for (int i = 0; i < m; ++i) {
            order.add(new ii(Math.abs((m + 1) - 2 * (i + 1)), i + 1));
        }
        Collections.sort(order);
        for (int i = 0; i < n; ++i) {
            int res = order.get(i % m).second;
            out.println(res);
        }
    }
}

class ii implements Comparable<ii> {
    public int first;
    public int second;

    public ii() {
    }

    public ii(int first, int second) {
        this.first = first;
        this.second = second;
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        ii ii = (ii) o;

        if (first != ii.first) return false;
        if (second != ii.second) return false;

        return true;
    }

    public int hashCode() {
        int result = first;
        result = 31 * result + second;
        return result;
    }

    public int compareTo(ii o) {
        if (first != o.first) {
            return first < o.first ? -1 : 1;
        }
        if (second != o.second) {
            return second < o.second ? -1 : 1;
        }
        return 0;
    }

    public ii add(ii o) {
        return new ii(first + o.first, second + o.second);
    }

    public ii subtract(ii o) {
        return new ii(first - o.first, second - o.second);
    }

    public ii negate() {
        return new ii(-first, -second);
    }
}