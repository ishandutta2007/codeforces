import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class CDF_A {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long sum = 1;
        long diff = 1;
        for (int i=0; i<n; i++) {
            String s = br.readLine();
            if (s.equals("UR") || s.equals("DL"))
                diff++;
            else if (s.equals("UL") || s.equals("DR"))
                sum++;
            else {
                sum++;
                diff++;
            }
        }
        br.close();

        System.out.println(sum * diff);
    }
}