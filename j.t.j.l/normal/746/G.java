import java.io.ByteArrayInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Arrays;
import java.util.Vector;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.InputMismatchException;

public class CF746G {
	InputStream is;
	PrintWriter out;
	String INPUT = "3 1 1 2";//"14 5 6 4 4 2 2 1";//"7 3 3 2 3 1";
	
	void solve()
	{
		int n = ni(), t = ni(), k = ni();
		int[] a = na(t);
		int[] fa = new int[n+1];
		if (n - t < k){
			out.println(-1);
			return ;
		}
		int now = 1;
		fa[1] = 0;
		for(int i = 0; i < t; i++){
			for(int j = 1; j <= a[i]; j++)
				fa[now + j] = now;
			now += a[i];
		}
		int lf = n - t - k;
		for(int i = t - 1; i > 0; i--){
			int tmp = now - a[i];
			int p = min(min(a[i-1], a[i]) - 1, lf);
			for (int j = 1; j <= p; j++){
				fa[now - j] = tmp - j;
			}
			now = tmp;
			lf -= p;
		}
		if (lf != 0){
			out.println(-1);
		}
		else{
			out.println(n);
			for(int i = 2; i <= n; i++){
				out.println((i) + " " + (fa[i]));
			}
		}
	}

	int min(int p, int q){
		return p < q ? p : q;
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
	
	public static void main(String[] args) throws Exception { new CF746G().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}