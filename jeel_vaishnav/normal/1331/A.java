import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Jeel Vaishnav
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        AIsItRated solver = new AIsItRated();
        solver.solve(1, in, out);
        out.close();
    }

    static class AIsItRated {
        public void solve(int testNumber, InputReader sc, PrintWriter out) {
            out.println("no");
        }

    }

    static class InputReader {
        private InputStream stream;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

    }
}