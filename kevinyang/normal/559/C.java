import java.io.*;
import java.util.*;
public class Grid2 {
	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public String readLine() throws IOException {
			byte[] buf = new byte[64]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}
		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}
			if (neg)
				return -ret;
			return ret;
		}
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}
		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}
		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
	static int max=200001;
	static long mod=1000000007;
	static long[] f = new long[max];
	static long[] r = new long[max];
	static long k(long x, long n) {
		
		long returning = 1;
		while (n > 0) {
			if ((n & 1)> 0) returning=returning * x % mod;
			x= x * x % mod;
			n>>= 1;
		}
		return returning;
	}
	static long L(int x,int y) {
		return (f [x]*r[y]%mod)* r[x-y]%mod;
	}
	static long ret(int x,int y) {
		int x1 = x+y-2;
		int y1 = y-1;
		return L(x1,y1);
	}
	public static void main(String[] args)throws IOException {
		Reader e = new Reader();
		int h=e.nextInt();
		int w=e.nextInt();
		int n=e.nextInt();
		long[] vals=new long[n+1];
		long[] nums=new long[n+1];
		for(int i = 0;i<n;i++) {
			int a=e.nextInt();
			int b=e.nextInt();
			vals[i]=100001L*a+b;
		}
		vals[n]= 100001L*h+w;
		n++;
		Arrays.sort(vals);
		f[0]= 1;
		r[0]= 1;
		for(int i = 1;i<max;++i) f[i]= f[i-1] *i% mod;
		r[max-1]= k(f[max-1],mod-2);
		for(int i = max-2; i>=0; i--) r[i] = r[i+1]*(i + 1) %mod;
		for(int i = 0;i<n;++i) {
			int x = (int)(vals[i]/100001);
			int y = (int)(vals[i]%100001);
			//System.out.println(x);
			//System.out.println(y);
			nums[i]= ret(x,y);
			for (int j=0;j<i;j++) {
				/*
				boolean contain = false;//whether or not there is a # at the coordinates i,j
				boolean containi = false;//whether or not there is a # at the coordinates i+1,j
				boolean containj = false;//whether or not there is a # at the coordinates i,j+1
				*/
				int x1 = (int)(vals[j]/100001);
				int y1 = (int)(vals[j]%100001);
				if (x1>x||y1>y) continue;
				nums[i] -= nums[j]* ret(x-x1+1,y-y1+1)%mod;
				nums[i] = (nums[i] %mod+mod)% mod;
			}
			//System.out.println(Arrays.toString(vals));
		}
		System.out.println(nums[n-1]);
	}
}