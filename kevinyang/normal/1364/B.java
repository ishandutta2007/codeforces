import java.util.*;
import java.io.*;
public class B1364 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args)throws IOException {
		int t = readInt();
		while(t--!=0) {
			int n = readInt();
			int[]array = new int[n+1];
			for(int i = 0; i<n; i++) {
				array[i] = readInt();
			}
			array[n] = array[n-1];
			ArrayList<Integer>list = new ArrayList<Integer>();
			list.add(array[0]);
			int index = 0;
			int i = 1;
			while(i<n) {
				if(array[i]==list.get(index)) {
					i++;
					continue;
				}
				if(array[i]>list.get(index)) {
					for(i = i; i<n-1; i++) {
						if(!(array[i]<=array[i+1])) {
							break;
						}
						if(i==n-1)break;
					}
					
					list.add(array[i]); index++;
				}
				else {
					for(i = i; i<n-1; i++) {
						if(!(array[i]>=array[i+1])) {
							break;
						}
						if(i==n-1)break;
					}
					list.add(array[i]); index++;
				}
				if(i==n-1)break;
			}
			System.out.println(list.size());
			for(int j = 0; j<list.size(); j++) {
				if(j>0)System.out.print(" ");
				System.out.print(list.get(j));
			}
			System.out.println();
		}
		pr.close();
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}