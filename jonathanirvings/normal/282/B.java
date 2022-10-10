//Codeforces Round #173 (Div. 2)
//13 Mar 2013

import java.util.*;
import java.lang.Math;
import java.io.*;

public class Main
{
	public static void main (String[] args)
	{
		InputStream inputStream = System.in;
		InputReader in = new InputReader(inputStream);
		int N = in.nextInt();
        int risan = 0;
        while (N-- > 0)
        {
            int a = in.nextInt();
            int b = in.nextInt();
            if (risan + a >= -500 && risan + a <= 500)
            {
                risan += a;
                System.out.print("A");
            } else
            {
                risan -= b;
                System.out.print("G");
            }
        }
        System.out.println("");
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