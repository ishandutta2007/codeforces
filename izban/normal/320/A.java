import java.util.*;
import java.io.*;
import java.lang.Math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        while (in.hasNextInt()) {
            String s = Integer.toString(in.nextInt());
            boolean ok = true;
            for (int i = 0; i < s.length(); i++) {
                ok &= s.charAt(i) == '1';
                if (i + 1 < s.length() && s.charAt(i + 1) == '4') {
                    if (i + 2 < s.length() && s.charAt(i + 2) == '4') {
                        if (i + 3 < s.length() && s.charAt(i + 3) != '1') {
                            ok = false;
                            break;
                        } else i += 2;
                    } else i += 1;
                } else i += 0;
            }
            if (ok) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}