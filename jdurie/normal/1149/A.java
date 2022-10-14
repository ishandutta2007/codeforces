import java.io.*;
import java.util.*;

public class A{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		int ones=0,twos=0;
		for(int i=0;i<n;i++)
			if(sc.nextInt()==1)
				ones++;
			else
				twos++;
		ArrayList<Integer>primes=new ArrayList<Integer>();
		for(int i=2;i<=n;i++){
			boolean prime=true;
			for(int j=2;j<=Math.sqrt(i);j++)
				if(i%j==0){
					prime=false;
					break;
				}
			if(prime)
				primes.add(i);
		}
/*		int[]deltas=new int[primes.size()];
		deltas[0]=2;
		for(int i=1;i<primes.size();i++)
			deltas[i]=primes.get(i)-primes.get(i-1);*/
		int currSum=0;
		for(int i:primes){
			int usedTwos=Math.min(twos,(i-currSum)/2);
			int usedOnes=Math.min(ones,i-currSum-2*usedTwos);
			for(int x=0;x<usedTwos;x++)
				System.out.print("2 ");
			for(int x=0;x<usedOnes;x++)
				System.out.print("1 ");
			twos-=usedTwos;
			ones-=usedOnes;
			currSum+=2*usedTwos+usedOnes;
			while(currSum<i){
				currSum+=2;
				twos--;
				System.out.print("2 ");
			}
		}
		for(int x=0;x<twos;x++)
			System.out.print("2 ");
		for(int x=0;x<ones;x++)
			System.out.print("1 ");
		// ------------------------
		out.close();
	}
	//------------------------

	public static PrintWriter out;
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}