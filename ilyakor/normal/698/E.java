import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.time.Month;
import java.io.BufferedWriter;
import java.time.ZonedDateTime;
import java.util.InputMismatchException;
import java.io.IOException;
import java.time.Instant;
import java.time.ZoneId;
import java.time.chrono.ChronoZonedDateTime;
import java.time.DayOfWeek;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author ilyakor
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public static final ZoneId CET = ZoneId.of("UTC");
        int ss;
        int mm;
        int hh;
        int day;
        int dat;
        int month;
        ZonedDateTime date;

        public void solve(int testNumber, InputReader in, OutputWriter out) {
            ss = in.nextInt();
            mm = in.nextInt();
            hh = in.nextInt();
            day = in.nextInt();
            dat = in.nextInt();
            month = in.nextInt();
            int qc = in.nextInt();
            for (int it = 0; it < qc; ++it) {
                long val = in.nextLong();
                Instant instant = Instant.ofEpochSecond(val);
                date = instant.atZone(CET).plusSeconds(1);
                while (adjust()) ;
                out.printLine(date.toInstant().getEpochSecond());
            }
        }

        private boolean adjust() {
            if (month != -1 && date.getMonth().getValue() != month) {
                if (date.getMonth().getValue() > month) {
                    date = ZonedDateTime.of(date.getYear() + 1, month, 1, 0, 0, 0, 0, CET);
                } else {
                    date = ZonedDateTime.of(date.getYear(), month, 1, 0, 0, 0, 0, CET);
                }
                return true;
            }

            boolean datMatch = (dat != -1 && date.getDayOfMonth() == dat);
            boolean dayMatch = (day != -1 && date.getDayOfWeek().getValue() == day);
            if ((dat != -1 || day != -1) && !datMatch && !dayMatch) {
                date = date.plusDays(1).withHour(0).withMinute(0).withSecond(0);
                return true;
            }

            if (hh != -1 && date.getHour() != hh) {
                int delta = hh - date.getHour();
                if (delta < 0) delta += 24;
                date = date.plusHours(delta).withMinute(0).withSecond(0);
                return true;
            }

            if (mm != -1 && date.getMinute() != mm) {
                int delta = mm - date.getMinute();
                if (delta < 0) delta += 60;
                date = date.plusMinutes(delta).withSecond(0);
                return true;
            }

            if (ss != -1 && date.getSecond() != ss) {
                int delta = ss - date.getSecond();
                if (delta < 0) delta += 60;
                date = date.plusSeconds(delta);
                return true;
            }

            return false;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
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

    static class InputReader {
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

        public int nextInt() {
            int sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10 + c - '0';
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
        }

        public long nextLong() {
            long sgn = 1;
            int c = readSkipSpace();
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res = res * 10L + (long) (c - '0');
                c = read();
            } while (!isSpace(c));
            res *= sgn;
            return res;
        }

    }
}