import java.util.*;
import java.io.*;
public class C758 {
	public static void main(String[]args) {
		Scanner e = new Scanner(System.in);
		int n = e.nextInt();
		int m = e.nextInt();
		long k = e.nextLong();
		int x = e.nextInt()-1;
		int y = e.nextInt()-1;
		long cur = 0;
		int stu = 0;
		if(n>1) {
			stu = (n-1)*m;
			long top = 0;
			long bottom = 0;
			long mid = 0;
			long[][]array = new long[n][m];
			mid = k/(stu);
			top = (mid+1)/2;
			bottom = mid/2;
			for(int i = 0; i<m; i++) {
				array[0][i] +=top;
				array[n-1][i]+=bottom;
				for(int j = 1; j<n-1; j++) {
					array[j][i]+=mid;
				}
			}
			k = k%stu;
			if(mid%2==0) {
				for(int i = 0; i<n-1&k>0; i++) {
					for(int j = 0; j<m&k>0; j++) {
						array[i][j]++;
						k--;
					}
				}
			}
			else {
				for(int i = n-1; i>0&k>0; i--) {
					for(int j = 0; j<m&k>0; j++) {
						array[i][j]++;
						k--;
					}
				}
			}
			long max = 0;
			long min = Long.MAX_VALUE;
			for(int i = 0; i<n; i++) {
				for(int j = 0; j<m; j++) {
					max = Math.max(max, array[i][j]);
					min = Math.min(min, array[i][j]);
				}
			}
			System.out.println(max + " " + min + " " + array[x][y]);
		}
		
		else {
			stu = m;
			long nums = k/stu;
			long[]array = new long[m];
			k = k%stu;
			for(int i = 0; i<m; i++) {
				array[i] = nums;
			}
			for(int i = 0; i<k; i++) {
				array[i]++;
			}
			long max = 0;
			long min = Long.MAX_VALUE;
			for(int i = 0; i<m; i++) {
				max = Math.max(max, array[i]);
				min = Math.min(min, array[i]);
			}
			System.out.println(max + " " + min + " " + array[y]);
		}
	}
}