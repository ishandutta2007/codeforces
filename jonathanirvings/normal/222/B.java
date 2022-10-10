//Codeforces Round 137 (Div. 2 Only)
//10 Sep 2012

import java.util.*;
import java.lang.Math;
import java.io.*;

public class B
{
	public static void main (String[] args) throws IOException
	{
		InputStream inputStream = System.in;
		InputReader in = new InputReader(inputStream);
		int data[][],r,c,q,a,b;
        String s;
        data = new int[1005][1005];
        int isic[], isir[];
        isic = new int[1005];
        isir = new int[1005];
        //System.out.println(data[0][0]);
        r = in.nextInt(); c = in.nextInt(); q = in.nextInt();
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                data[i][j] = in.nextInt();
        //System.out.println(data[0][0]);
        for (int i = 0; i < r; ++i) isir[i] = i;
        for (int i = 0; i < c; ++i) isic[i] = i;
        while (q-- > 0)
        {
            s = in.next();
            a = in.nextInt();
            b = in.nextInt();
            --a; --b;
            //System.out.println(s);
            if (s.equals("g"))
            {
                System.out.println(data[isir[a]][isic[b]]);
            } else if (s.equals("c"))
            {
                int tmp = isic[a];
                isic[a] = isic[b];
                isic[b] = tmp;
            } else
            {
                int tmp = isir[a];
                isir[a] = isir[b];
                isir[b] = tmp;
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