
import java.io.*;
import java.util.*;

public class D {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt();
		char[]l=sc.nextLine().toCharArray();
		char[]r=sc.nextLine().toCharArray();
		TreeMap<Character,TreeSet<Integer>>left=new TreeMap<Character,TreeSet<Integer>>();
		TreeMap<Character,TreeSet<Integer>>right=new TreeMap<Character,TreeSet<Integer>>();
		for(int i=0;i<n;i++){
			if(!left.containsKey(l[i])){
				left.put(l[i],new TreeSet<Integer>());
				right.put(l[i],new TreeSet<Integer>());
			}
			left.get(l[i]).add(i+1);
		}
		for(int i=0;i<n;i++){
			if(!right.containsKey(r[i])){
				left.put(r[i],new TreeSet<Integer>());
				right.put(r[i],new TreeSet<Integer>());
			}
			right.get(r[i]).add(i+1);
		}
		HashSet<String>ans=new HashSet<String>();
		int k=0;
		for(char c:left.keySet())
			if(c!='?')
				while(!left.get(c).isEmpty()&&!right.get(c).isEmpty()){
					k++;
					ans.add(left.get(c).pollFirst()+" "+right.get(c).pollFirst());
				}
		if(left.containsKey('?')){
			TreeSet<Integer>lQ=left.remove('?');
			TreeSet<Integer>rQ=right.remove('?');
			while(!right.isEmpty()&&!lQ.isEmpty()){
				while(!lQ.isEmpty()&&!right.firstEntry().getValue().isEmpty()){
					k++;
					ans.add(lQ.pollFirst()+" "+right.get(right.firstKey()).pollFirst());
				}
				right.pollFirstEntry();
			}
			while(!left.isEmpty()&&!rQ.isEmpty()){
				while(!rQ.isEmpty()&&!left.firstEntry().getValue().isEmpty()){
					k++;
					ans.add(left.get(left.firstKey()).pollFirst()+" "+rQ.pollFirst());
				}
				left.pollFirstEntry();
			}
			while(!lQ.isEmpty()&&!rQ.isEmpty()){
				k++;
				ans.add(lQ.pollFirst()+" "+rQ.pollFirst());
			}
		}
		out.println(k);
		for(String s:ans)
			out.println(s);
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