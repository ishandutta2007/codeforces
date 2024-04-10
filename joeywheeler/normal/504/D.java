import java.math.BigInteger;
import java.io.*;
import java.util.*;
public final class main {
    public static void main(String args[]) throws Throwable {
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        String line;
        BitSet r[] = new BitSet[2005];
        BigInteger b[] = new BigInteger[2005];
        int o[] = new int[2005];
        for (int i = 0; i < 2005; i++) {
            o[i] = -1;
        }
        int n = Integer.parseInt(bi.readLine());
        for (int i = 0; i < n; i++) {
            String l = bi.readLine();
            b[i] = new BigInteger(l);
            r[i] = new BitSet(2005);
            r[i].set(i);
            boolean g = false;
            for (int j = 0; j < 2005; j++) if (b[i].testBit(j)) {
                if (o[j] == -1) {
                    o[j] = i;
                    g = true;
                    break;
                } else {
                    b[i] = b[i].xor(b[o[j]]);
                    r[i].xor(r[o[j]]);
                }
            }
            if (g) {
                out.println("0");
            } else {
                r[i].set(i,false);
                out.print(r[i].cardinality() + " ");
                for (int j = 0; j < i; j++) {
                    if (r[i].get(j)) {
                        out.print(j + " ");
                    }
                }
                out.println("");
            }
        }
        out.close();
    }
}