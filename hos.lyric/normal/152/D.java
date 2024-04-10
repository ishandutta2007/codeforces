import static java.lang.Math.*;
import static java.math.BigInteger.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import java.math.*;
import java.util.*;
import java.io.*;

public class D {
	public static void main(String[] args) {
		new D().run();
	}
	Scanner in = new Scanner(System.in);
	
	void run() {
		for (; in.hasNext(); ) {
			solve();
		}
	}
	
	int[][] sum;
	
	void solve() {
		int m = in.nextInt(), n = in.nextInt();
		boolean[][] is = new boolean[m + 2][n + 2];
		for (int x = 1; x <= m; ++x) {
			String str = in.next();
			for (int y = 1; y <= n; ++y) {
				is[x][y] = (str.charAt(y - 1) == '#');
			}
		}
		sum = new int[m + 3][n + 3];
		for (int x = 0; x < m + 2; ++x) for (int y = 0; y < n + 2; ++y) {
			sum[x + 1][y + 1] = sum[x + 1][y] + sum[x][y + 1] - sum[x][y] + (is[x][y] ? 1 : 0);
		}
// _out(sum);
		boolean[] isX = new boolean[m + 2], isY = new boolean[n + 2];
		for (int x = 1; x <= m; ++x) for (int y = 1; y <= n; ++y) if (is[x][y]) {
			if (!is[x + 1][y] || !is[x - 1][y]) isX[x - 1] = isX[x] = isX[x + 1] = true;
			if (!is[x][y + 1] || !is[x][y - 1]) isY[y - 1] = isY[y] = isY[y + 1] = true;
		}
		int xsLen = 0, ysLen = 0;
		for (int x = 1; x <= m; ++x) if (isX[x]) ++xsLen;
		for (int y = 1; y <= n; ++y) if (isY[y]) ++ysLen;
		int[] xs = new int[xsLen], ys = new int[ysLen];
		xsLen = ysLen = 0;
		for (int x = 1; x <= m; ++x) if (isX[x]) xs[xsLen++] = x;
		for (int y = 1; y <= n; ++y) if (isY[y]) ys[ysLen++] = y;
// _out(xs);_out(ys);
		if (xsLen > 12 || ysLen > 12) {
			System.out.println("NO");
			return;
		}
		for (int i0 = 0; i0 < xsLen; ++i0) for (int i1 = i0 + 1; i1 < xsLen; ++i1) 
		for (int i2 = 0; i2 < ysLen; ++i2) for (int i3 = i2 + 1; i3 < ysLen; ++i3) 
		for (int i4 = 0; i4 < xsLen; ++i4) for (int i5 = i4 + 1; i5 < xsLen; ++i5) 
		for (int i6 = 0; i6 < ysLen; ++i6) for (int i7 = i6 + 1; i7 < ysLen; ++i7) 
		{
			if (check(xs[i0], xs[i1], ys[i2], ys[i3], xs[i4], xs[i5], ys[i6], ys[i7])) {
				System.out.println("YES");
				System.out.println(xs[i0] + " " + ys[i2] + " " + xs[i1] + " " + ys[i3]);
				System.out.println(xs[i4] + " " + ys[i6] + " " + xs[i5] + " " + ys[i7]);
				return;
			}
		}
		System.out.println("NO");
		return;
	}
	boolean check(int x0, int x1, int y0, int y1, int x2, int x3, int y2, int y3) {
		if (!(x1 - x0 > 1 && y1 - y0 > 1)) return false;
		if (!(x3 - x2 > 1 && y3 - y2 > 1)) return false;
		int area01 = ((x1 - x0) + (y1 - y0)) * 2;
		int area23 = ((x3 - x2) + (y3 - y2)) * 2;
		if (calc(x0, x1 + 1, y0, y1 + 1) - calc(x0 + 1, x1, y0 + 1, y1) != area01) return false;
		if (calc(x2, x3 + 1, y2, y3 + 1) - calc(x2 + 1, x3, y2 + 1, y3) != area23) return false;
		int area = area01 + area23;
		//*
		for (int x = x2; x <= x3; ++x) {
			if (covered(x0, x1, y0, y1, x, y2)) --area;
			if (covered(x0, x1, y0, y1, x, y3)) --area;
		}
		for (int y = y2; y <= y3; ++y) {
			if (covered(x0, x1, y0, y1, x2, y)) --area;
			if (covered(x0, x1, y0, y1, x3, y)) --area;
		}
		if (covered(x0, x1, y0, y1, x2, y2)) ++area;
		if (covered(x0, x1, y0, y1, x2, y3)) ++area;
		if (covered(x0, x1, y0, y1, x3, y2)) ++area;
		if (covered(x0, x1, y0, y1, x3, y3)) ++area;
		//*/
		/*
		int xOverlap = max(min(x1, x3) - max(x0, x2) - 1, 0);
		int yOverlap = max(min(y1, y3) - max(y0, y2) - 1, 0);
		if (x0 == x2) area -= yOverlap;
		if (x0 == x3) area -= yOverlap;
		if (x1 == x2) area -= yOverlap;
		if (x1 == x3) area -= yOverlap;
		if (y0 == y2) area -= xOverlap;
		if (y0 == y3) area -= xOverlap;
		if (y1 == y2) area -= xOverlap;
		if (y1 == y3) area -= xOverlap;
		if (x2 <= x0 && x0 <= x3 && covered(x0, x1, y0, y1, x0, y2)) --area;
		if (x2 <= x0 && x0 <= x3 && covered(x0, x1, y0, y1, x0, y3)) --area;
		if (x2 <= x1 && x1 <= x3 && covered(x0, x1, y0, y1, x1, y2)) --area;
		if (x2 <= x1 && x1 <= x3 && covered(x0, x1, y0, y1, x1, y3)) --area;
		if (y2 <= y0 && y0 <= y3 && covered(x0, x1, y0, y1, x2, y0)) --area;
		if (y2 <= y0 && y0 <= y3 && covered(x0, x1, y0, y1, x3, y0)) --area;
		if (y2 <= y1 && y1 <= y3 && covered(x0, x1, y0, y1, x2, y1)) --area;
		if (y2 <= y1 && y1 <= y3 && covered(x0, x1, y0, y1, x3, y1)) --area;
		if (covered(x0, x1, y0, y1, x2, y2)) ++area;
		if (covered(x0, x1, y0, y1, x2, y3)) ++area;
		if (covered(x0, x1, y0, y1, x3, y2)) ++area;
		if (covered(x0, x1, y0, y1, x3, y3)) ++area;
		//*/
// _out(x0,x1,y0,y1,x2,x3,y2,y3,area);
		if (sum[sum.length - 1][sum[0].length - 1] != area) return false;
		return true;
	}
	int calc(int x0, int x1, int y0, int y1) {
		return sum[x0][y0] - sum[x0][y1] - sum[x1][y0] + sum[x1][y1];
	}
	boolean covered(int x0, int x1, int y0, int y1, int x, int y) {
		return (x0 <= x && x <= x1 && y0 <= y && y <= y1 && (x == x0 || x == x1 || y == y0 || y == y1));
	}
	
	void _out(Object...os) {
		System.out.println(deepToString(os));
	}
}