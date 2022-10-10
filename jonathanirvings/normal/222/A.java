//Codeforces Round 137 (Div. 2 Only)
//10 Sep 2012

import java.util.*;
import java.lang.Math;
import java.io.*;

public class A
{
	public static void main (String[] args)
	{
		InputStream inputStream = System.in;
		InputReader in = new InputReader(inputStream);
        
        int n = in.nextInt();
        int k = in.nextInt();
        int data[];
        data = new int[100005];
        for (int i = 1; i <= n; ++i)
            data[i] = in.nextInt();
        boolean ok = true;
        boolean sama = true;
        for (int i = 1; i < n; ++i)
        {
            if (data[i] != data[i+1]) sama = false;
        }
        if (sama)
        {
            System.out.println(0);
        } else
        {
            for (int i = k + 1; i <= n; ++i)
                if (data[i] != data[k])
                {
                    System.out.println(-1);
                    ok = false;
                    break;
                }
            if (ok) 
            {
                int ix = k;
                while (data[ix] == data[k]) --ix;
                System.out.println(ix);
            }
        }
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