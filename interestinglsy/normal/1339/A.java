import java.io.*;
import java.util.*;

public class Main{
	public static void main( String[] args ){
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		int t = scanner.nextInt();
		for( int i = 1 ; i <= t ; ++i ){
			int n = scanner.nextInt();
			System.out.println(n);
		}
	}
}