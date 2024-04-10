import java.io.BufferedWriter;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author ilyakor
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        String s = in.nextLine();
        String[] parts = s.split("\\s+");
        int n = Integer.parseInt(parts[parts.length - 1]);
        int cnt = (parts.length - 1) / 2;
        ArrayList<Integer> plusPos = new ArrayList<>();
        ArrayList<Integer> minusPos = new ArrayList<>();
        plusPos.add(-1);
        for (int i = 0; i < cnt - 1; ++i) {
            if (parts[i * 2 + 1].equals("+"))
                plusPos.add(i);
            else
                minusPos.add(i);
        }
        int lP = plusPos.size(), rP = plusPos.size() * n;
        int lM = minusPos.size(), rM = minusPos.size() * n;
        if (n < lP - rM || n > rP - lM) {
            out.printLine("Impossible");
            return;
        }
        out.printLine("Possible");
        int px = lP, py;
        while (true) {
            py = px - n;
            if (py >= lM && py <= rM)
                break;
            ++px;
        }
        for (int i = 0; i < plusPos.size(); ++i) {
            int val = Math.max(1, px - n * (plusPos.size() - i - 1));
            parts[plusPos.get(i) * 2 + 2] = "" + val;
            px -= val;
        }
        for (int i = 0; i < minusPos.size(); ++i) {
            int val = Math.max(1, py - n * (minusPos.size() - i - 1));
            parts[minusPos.get(i) * 2 + 2] = "" + val;
            py -= val;
        }
        for (String part : parts)
            out.print(part + " ");
        out.printLine();
    }
}

class InputReader {
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

    public String nextLine() {
        int c = readSkipSpace();
        StringBuilder sb = new StringBuilder();
        while (c != '\n' && c != -1) {
            sb.append((char)c);
            c = read();
        }
        return sb.toString();
    }

}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
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