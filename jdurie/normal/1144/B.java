import java.io.*;
import java.util.*;

public class B {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		TreeMap<Integer,Integer>odds=new TreeMap<Integer,Integer>();
		TreeMap<Integer,Integer>evens=new TreeMap<Integer,Integer>();
		int oddCt=0,evenCt=0;
		for(int i=0;i<n;i++){
			int x=sc.nextInt();
			if(x%2==0){
				evens.put(x,(evens.containsKey(x)?evens.get(x)+1:1));
				evenCt++;
			}else{
				odds.put(x,(odds.containsKey(x)?odds.get(x)+1:1));
				oddCt++;
			}
		}
		int sum=0;
		while(oddCt>evenCt+1){
			sum+=removeFirst(odds);
			oddCt--;
		}
		while(evenCt>oddCt+1){
			sum+=removeFirst(evens);
			evenCt--;
		}
		System.out.println(sum);
		// ------------------------
		out.close();
	}
	//------------------------
	private static int removeFirst(TreeMap<Integer,Integer>map){
		int k=map.firstKey();
		if(map.get(k)==1)
			map.remove(k);
		else
			map.put(k,map.get(k)-1);
		return k;
	}
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