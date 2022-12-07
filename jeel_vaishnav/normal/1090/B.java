import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;
import static java.lang.Math.*;

/* spar5h */

public class cf2 implements Runnable {   
	
	public void run() {
		
		Scanner s = new Scanner(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		HashMap<String, Integer> hm = new HashMap<String, Integer>();
		
		StringTokenizer st;
		
		while(true) {
			
			st = new StringTokenizer(s.nextLine(), " ");
			
			if(!st.hasMoreTokens())
				continue;
			
			String str = st.nextToken();
			
			//System.out.println(str);
			
			if(str.equals("\\begin{thebibliography}{99}"))
				break;
			
			if(str.charAt(0) == 92) {
				
				int end = -1;
				
				for(int i = 6; i < str.length(); i++)
					if(str.charAt(i) == '}') {
						end = i; break;
					}
				
				hm.put(str.substring(6,  end), hm.size());
			}
			
			while(st.hasMoreTokens()) {
				
				str = st.nextToken();
				
				//System.out.println(str);
				
				if(str.charAt(0) != 92)
					continue;
				
				int end = -1;
				
				for(int i = 6; i < str.length(); i++)
					if(str.charAt(i) == '}') {
						end = i; break;
					}
				
				hm.put(str.substring(6,  end), hm.size());
			}
		}
		
		String[] val = new String[hm.size()];
		
		boolean check = true;
		
		for(int i = 0; i < hm.size(); i++) {
			
			String str = s.nextLine();
			
			int end = -1;
			
			for(int j = 9; j < str.length(); j++)
				if(str.charAt(j) == '}') {
					end = j; break;
				}
			
			int x = hm.get(str.substring(9, end));
			
			if(x != i)
				check = false;
			
			val[x] = str;
		}
		
		s.nextLine();
		
		if(!check) {
			
			w.println("Incorrect");
			w.println("\\begin{thebibliography}{99}");
			
			for(int i = 0; i < hm.size(); i++)
				w.println(val[i]);
			
			w.println("\\end{thebibliography}");
		}
		else
			w.println("Correct");
		
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
		new Thread(null, new cf2(),"cf2",1<<26).start();
	}
}