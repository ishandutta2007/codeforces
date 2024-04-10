import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Set;
import java.util.Vector;
import java.util.Random;

public class Main {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	static int INF = 1000000009;
	
	int max(int p, int q){
		return p > q ? p : q;
	}
	
	int min(int p, int q){
		return p < q ? p : q;
	}
	
	void solve(){
		int n = ni(), m = ni();
		long a[] = nal(n);
		int f[] = new int[n + 1];
		int g[] = new int[n + 1];
		int sm[] = new int[n + 1];
		for (int i = 1; i <= n; i++){
			long x = a[i - 1];
			while(x % 2 == 0){
				x /= 2;
				f[i]++;
			}
			while(x % 5 == 0){
				x /= 5;
				g[i]++;
			}
			sm[i] = sm[i - 1] + g[i];
		}
		/*
		for (int i = 0; i <= n; i++)
			out.print(f[i] + " "); out.println();
		for (int i = 0; i <= n; i++)
			out.print(g[i] + " "); out.println();
		for (int i = 0; i <= n; i++)
			out.print(sm[i] + " "); out.println();
		*/
		int dp[][][] = new int[2][m + 1][sm[n] + 1];
		dp[0][0][0] = 0;
		for (int i = 0; i < n; i++){
			int p = i & 1;
			int q = 1 - p;
			for (int j = 0; j <= m && j <= i + 1; j++)
				for (int k = 0; k <= sm[i + 1]; k++)
					dp[q][j][k] = -INF;
			//out.println("====================" + i);
			for (int j = 0; j <= m && j <= i; j++)
				for (int k = 0; k <= sm[i]; k++){
					// not i
					dp[q][j][k] = max(dp[q][j][k], dp[p][j][k]);
					// i
					if (j < m)
						dp[q][j + 1][k + g[i + 1]] = max(dp[q][j + 1][k + g[i + 1]], dp[p][j][k] + f[i + 1]);
				}
			/*for (int j = 0; j <= m && j <= i + 1; j++){
				for (int k = 0; k <= sm[i + 1]; k++)
					out.print(dp[q][j][k] + " ");
				out.println();
			}*/
		}
		int ans = 0;
		for (int k = 0; k <= sm[n]; k++)
			ans = max(ans, min(dp[n & 1][m][k], k));
		out.println(ans);
		/*
		int mm = 1 << n;
		int ans2 = 0;
		for (int x = 0; x < mm; x++){
			int p = 0, q = 0, r = 0;
			for (int i = 0; i < n; i++){
				if (((x >> i) & 1) == 1){
					r++;
					p += f[i + 1];
					q += g[i + 1];
				}
			}
			if (r == m){
				ans2 = max(ans2, min(p, q));
			}
		}
		out.println(ans2);
		if (ans == ans2)
			out.println("Yes");
		else{
			out.println("Niconiconi");
		}*/
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		/*
		Random rd = new Random();
		rd.setSeed(25252);
		for (int t = 0; t < 100; t++){
			INPUT = "";
			INPUT += "10 " + (new Integer(t % 5 + 2)) + "\n";
			for (int i = 1; i <= 10; i++){
				INPUT += (new Integer(Math.abs(rd.nextInt()))) + " ";
			}
			INPUT += "\n";
			out.println(INPUT);
			out.flush();
			is = new ByteArrayInputStream(INPUT.getBytes());
			solve();
		}
		*/
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new Main().run(); }
	
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
	
	private long[] nal(int n)
	{
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
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
	
	private boolean oj = true; //System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}