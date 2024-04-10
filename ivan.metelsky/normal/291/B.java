import java.io.BufferedReader;
import java.io.InputStreamReader;

public class ProblemB {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        s = " " + s + " ";
        boolean inside = false;
        StringBuilder sb = new StringBuilder();
        char prev = 0;
        for (char c : s.toCharArray()) {
            if (c == '"') {
                if (inside) {
                    sb.append(">\n");
                    inside = false;
                } else {
                    sb.append("<");
                    inside = true;
                }
            } else if (c == ' ') {
                if (inside) {
                    sb.append(' ');
                } else if (prev != 0 && prev != ' ' && prev != '"') {
                    sb.append(">\n");
                }
            } else {
                if (inside) {
                    sb.append(c);
                } else {
                    if (prev == 0 || prev == ' ') sb.append('<');
                    sb.append(c);
                }
            }
            prev = c;
        }
        System.out.println(sb.toString());
    }
}