import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;
import static java.lang.Math.*;

/* spar5h */

public class cf1 implements Runnable{    
	
	public void run() {
		
		InputReader s = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int MAX = (int)1e5 + 5;
		
		int[] sieve = new int[MAX];
		Arrays.fill(sieve, 1); sieve[0] = 0; sieve[1] = 0;
		
		for(int i = 2; (long)i * i < MAX; i++) {
			for(int j = i; (long)i * j < MAX; j++)
				sieve[i * j] = 0;
		}
		
		int n = s.nextInt();
		int temp = n;
		
		ArrayList<Integer> pf = new ArrayList<Integer>();
		
		for(int j = 2; (long)j * j <= n; j++) {
			
			if(sieve[j] == 0 || temp % j != 0)
				continue;
			
			pf.add(j);
			
			while(temp % j == 0) 
				temp /= j;
		}
		
		if(temp > 1 && temp != n)
			pf.add(temp);
		
		Collections.sort(pf);
		
		if(n % 2 == 0) {
			
			int val = -1;
			
			for(int i = 0; i < pf.size(); i++)
				if(pf.get(i) % 2 == 1) {
					val = pf.get(i); break;
				}
			
			if(val != -1) {
				
				w.println("YES");
				w.println(2);
				w.println(1 + " " + (n / val));
				w.println((n - 1 - val) / 2 + " " + (n / 2));
			}
			else {
				w.println("NO");
			}
					
		}
		
		else {
			
			boolean check = false;
			int val1 = -1, val2 = -1, val3 = -1;
			
			outer:
			for(int i = 0; i < pf.size(); i++) {
				
				for(int j = i + 1; j < pf.size(); j++) {
					
					int mod = (n - 1) % pf.get(i);
					
					int mul = -1;
					
					for(int k = 1; k <= pf.get(i); k++) {
						
						if((pf.get(j) * k) % pf.get(i) == mod) {
							mul = k; break;
						}
					}
					
					if(mul != -1 && n - 1 >= mul * pf.get(j)) {
						check = true; val1 = pf.get(i); val2 = pf.get(j); val3 = mul; break outer; 
					}
				}
			}
			
			if(check) {
				
				w.println("YES");
				w.println(2);
				w.println(val3 + " " + (n / val2));
				w.println((n - 1 - val3 * val2) / val1 + " " + (n / val1));
			}
			
			else 
				w.println("NO");
			
		}
		
		w.close();
	}

	static class InputReader {
		
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		
		public InputReader(InputStream stream) {
			this.stream = stream;
		}
		
		public int read() {
			
			if (numChars==-1) 
				throw new InputMismatchException();
			
			if (curChar >= numChars) {
				
				curChar = 0;
				
				try {
					numChars = stream.read(buf);
				}
				catch (IOException e) {
					throw new InputMismatchException();
				}
				
				if(numChars <= 0)				
					return -1;
			}
			
			return buf[curChar++];
		}
		 
		public String nextLine() {
			
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String str = "";
	        
			try {
	            str = br.readLine();
	        }
	        catch (IOException e) {
	            e.printStackTrace();
	        }
			
	        return str;
		}
		
		public int nextInt() {
		
			int c = read();
			
			while(isSpaceChar(c)) 
				c = read();
			
			int sgn = 1;
			
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			
			int res = 0;
			
			do {
				if(c<'0'||c>'9') 
					throw new InputMismatchException();
				
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c)); 
			
			return res * sgn;
		}
		
		public long nextLong() {
			
			int c = read();
			
			while (isSpaceChar(c))
				c = read();
			
			int sgn = 1;
			
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			
			long res = 0;
			
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				
				res *= 10;
				res += c - '0';
				c = read();
			}
			
			while (!isSpaceChar(c));
				return res * sgn;
		}
		
		public double nextDouble() {
			
			int c = read();
			
			while (isSpaceChar(c))
				c = read();
			
			int sgn = 1;
			
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			
			double res = 0;
			
			while (!isSpaceChar(c) && c != '.') {
				
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				
				res *= 10;
				res += c - '0';
				c = read();
			}
			
			if (c == '.') {
				
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) 
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			
			return res * sgn;
		}
		
		public String readString() {
			
			int c = read();
			
			while (isSpaceChar(c))
				c = read();
			
			StringBuilder res = new StringBuilder();
			
			do {
				res.appendCodePoint(c);
				c = read();
			} 
			while (!isSpaceChar(c));
			
			return res.toString();
		}
	 
		public boolean isSpaceChar(int c) {
			
			if (filter != null)
				return filter.isSpaceChar(c);
			
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	 
		public String next() {
			return readString();
		}
		
		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	
	}

	public static void main(String args[]) throws Exception {
		new Thread(null, new cf1(),"cf1",1<<26).start();
	}
}