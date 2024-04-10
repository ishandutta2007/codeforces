import java.util.*;
import java.lang.Math;
import java.io.*;

public class Main
{
	public static void main (String[] args)
	{
		//Scanner in = new Scanner(System.in);
		InputStream inputStream = System.in;
		InputReader in = new InputReader(inputStream);
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int r,c,data[][];
		int jumr[];
		int jumc[];
		jumr = new int[1005];
		jumc = new int[1005];
		data = new int[1005][1005];
		int ansx,ansy;
		long minx,miny;
		r = in.nextInt();
		c = in.nextInt();
		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				data[i][j] = in.nextInt();
				jumr[i] += data[i][j];
				jumc[j] += data[i][j];
			}
		}
		//for (int i = 1; i <= c; ++i) System.out.println(jumc[i]);
		minx = miny = (long)1000000000000000000l;
		ansx = ansy = -1;
		//System.out.printf("%d %d\n",ansx,ansy);
		for (int i = 0; i <= r; ++i)
		{
			long tot = 0;
			for (int j = 1; j <= r; ++j)
			{
				int k = Math.abs(i - j);
				if (j <= i) ++k;
				k = (4 * k - 2) * (4 * k - 2);
				tot += (long)jumr[j] * (long)(k);
			}
			if (tot < minx)
			{
				minx = tot;
				ansx = i;
			}
		}
		for (int i = 0; i <= c; ++i)
		{
			long tot = 0;
			for (int j = 1; j <= c; ++j)
			{
				int k = Math.abs(i - j);
				if (j <= i) ++k;
				k = (4 * k - 2) * (4 * k - 2);
				tot += (long)jumc[j] * (long)(k);
			}
			if (tot < miny)
			{
				miny = tot;
				ansy = i;
			}
		}
		long risan = 0;
		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				int k = Math.abs(i - ansx);
				int l = Math.abs(j - ansy);
				if (i <= ansx) ++k;
				if (j <= ansy) ++l;
				k = (4 * k - 2) * (4 * k - 2);
				l = (4 * l - 2) * (4 * l - 2);
				risan += (long)(k + l) * (long)(data[i][j]);
				//System.out.println(risan);
			}
		}
		System.out.println(risan);
		System.out.printf("%d %d\n",ansx,ansy);
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