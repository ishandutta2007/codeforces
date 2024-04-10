import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;
import java.util.Vector;

public class CF762D {
	InputStream is;
	PrintWriter out;
	long INF = 1l << 60;
	String INPUT = "0 0 1 0 0 1";
	
	void solve()
	{
		int n = ni();
		int [][] a = new int[3][n+3];
		for(int i = 0; i < 3; i++)
			for(int j = 1; j <= n; j++)
				a[i][j] = ni();
		long [][] f = new long[5][n + 3];
		f[0][0] = 0; f[1][0] = f[2][0] = f[3][0] = f[4][0] = -INF;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j < 5; j++)
				f[j][i] = -INF;
			f[0][i] = max(f[0][i], max(f[0][i-1] + a[0][i], max(f[1][i-1] + a[0][i] + a[1][i], max(f[2][i-1] + a[0][i] + a[1][i] + a[2][i], f[4][i-1] + a[0][i] + a[1][i] + a[2][i]))));
			f[1][i] = max(f[1][i], max(f[0][i-1] + a[0][i] + a[1][i], max(f[1][i-1] + a[1][i], f[2][i-1] + a[2][i] + a[1][i])));
			f[2][i] = max(f[2][i], max(f[2][i-1] + a[2][i], max(f[1][i-1] + a[2][i] + a[1][i], max(f[0][i-1] + a[0][i] + a[1][i] + a[2][i], f[3][i-1] + a[0][i] + a[1][i] + a[2][i]))));
			f[3][i] = max(f[3][i], max(f[0][i-1] + a[0][i] + a[1][i] + a[2][i], f[3][i-1] + a[0][i] + a[1][i] + a[2][i]));
			f[4][i] = max(f[4][i], max(f[2][i-1] + a[0][i] + a[1][i] + a[2][i], f[4][i-1] + a[0][i] + a[1][i] + a[2][i]));
		}
		out.println(f[2][n]);
	}
	
	long max(long p, long q){
		return p > q ? p : q;
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new CF762D().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int[][] nma(int n, int m)
	{
		int[][] a = new int[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				a[i][j] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = true;//System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}