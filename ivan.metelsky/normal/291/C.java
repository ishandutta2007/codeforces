import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ProblemC {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int n = Integer.parseInt(s.split(" ")[0]);
        int k = Integer.parseInt(s.split(" ")[1]);
        long[] ip = new long[n];
        for (int i=0; i<n; i++) {
            String addr = br.readLine();
            StringTokenizer st = new StringTokenizer(addr, ".");
            for (int j=0; j < 4; j++) ip[i] = ip[i]*256 + Integer.parseInt(st.nextToken());
        }
        long mask = 0;
        long[] ip2 = new long[n];
        for (int bits = 1; bits < 32; bits++) {
            mask += (1L << (32 - bits));
            for (int i=0; i < n; i++) {
                ip2[i] = ip[i] & mask;
            }
            Arrays.sort(ip2);
            int cnt = 0;
            for (int i=0; i<n; i++) if (i == 0 || ip2[i] > ip2[i-1]) cnt++;
            if (cnt == k) {
                System.out.println((mask>>24) + "." + ((mask>>16)&255) + "." + ((mask>>8)&255) + "." + (mask&255));
                System.exit(0);
            }
        }
        System.out.println(-1);
    }
}