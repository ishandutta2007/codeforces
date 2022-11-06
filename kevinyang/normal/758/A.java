import java.util.*;
import java.io.*;
public class A758 {
	public static void main(String[]args) {
		Scanner e = new Scanner(System.in);
		int n = e.nextInt();
		int[]array = new int[n];
		int max = 0;
		for(int i = 0; i<n; i++) {
			array[i] = e.nextInt();
			 max = Math.max(max, array[i]);
		}
		int sum = 0;
		for(int i = 0; i<n; i++) {
			sum+=(max-array[i]);
		}
		System.out.println(sum);
	}
}