import java.util.*;
import java.lang.Math;
import java.io.*;
 
public class Main
{
        public static void main (String[] args)
        {
                InputStream inputStream = System.in;
                InputReader in = new InputReader(inputStream);
                int arr[] = new int[4];
                for (int i = 0; i < 4; ++i) arr[i] = in.nextInt();
                Arrays.sort(arr,0,4);
                int risan = 0;
                for (int i = 1; i < 4; ++i) if (arr[i] == arr[i-1]) ++risan;
                System.out.println(risan);
        }
}
 
class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;
 
    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }
 
    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
 
    public int nextInt() {
        return Integer.parseInt(next());
    }
}