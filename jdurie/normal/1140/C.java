
import java.io.*;
import java.util.*;

public class C{
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),k=sc.nextInt();
		Song[]list=new Song[n];
		for(int i=0;i<n;i++)
			list[i]=new Song(sc.nextLong(),sc.nextLong());
		Arrays.sort(list);
		TreeMap<Long,Integer>max=new TreeMap<Long,Integer>();
		long sum=0;
		long ans=0;
		long bs=0;
		for(int i=n-1;i>=0;i--){
			if(bs<k){
				max.put(list[i].len,(max.containsKey(list[i].len)?max.get(list[i].len)+1:1));
				sum+=list[i].len;
				ans=Math.max(ans,sum*list[i].beauty);
				bs++;
			}else if(list[i].len>max.firstKey()){
				long key=max.firstKey();
				if(max.get(key)==1)
					max.pollFirstEntry();
				else
					max.put(key,max.get(key)-1);
				sum-=key;
				max.put(list[i].len,(max.containsKey(list[i].len)?max.get(list[i].len)+1:1));
				sum+=list[i].len;
				ans=Math.max(ans,sum*list[i].beauty);
			}
		}
		System.out.println(ans);
		// ------------------------
		out.close();
	}
	//------------------------
	public static class Song implements Comparable<Song>{
		long len;
		long beauty;
		public Song(long l,long b){
			len=l;
			beauty=b;
		}
		public int compareTo(Song other){
			return (int)beauty-(int)other.beauty;
		}
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