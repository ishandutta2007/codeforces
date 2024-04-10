import java.io.*;
import java.util.*;

public class Main{
	static final int MAXN = 131072;
	static int[] a = new int[MAXN];
	static int[] ansl = new int[MAXN];
	public static void main( String[] args ){
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		int t = scanner.nextInt();
		for( int ti = 1 ; ti <= t ; ++ti ){
			int n = scanner.nextInt();
			for( int i = 1 ; i <= n ; ++i ) a[i] = scanner.nextInt();
			Arrays.sort(a,1,n+1);
			int l = 1, r = n;
			boolean moveR = true;
			for( int i = n ; i >= 1 ; --i ){
				if(moveR){
					ansl[i] = a[r];
					--r;
				}else{
					ansl[i] = a[l];
					++l;
				}
				moveR ^= true;
			}
			for( int i = 1 ; i <= n ; ++i ){
				System.out.print(ansl[i]);
				System.out.print(' ');
			}
			System.out.println();
		}
	}
}