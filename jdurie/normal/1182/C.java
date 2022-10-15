//package cf566d2;
import java.io.*;
import java.util.*;

public class C{
	// ------------------------
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		TreeMap<String,LinkedList<String>>map=new TreeMap<String,LinkedList<String>>();
		HashMap<String,String>leftovers=new HashMap<String,String>();
		int n=sc.nextInt();
		LinkedList<String>lyrics=new LinkedList<String>();
		for(int i=0;i<n;i++){
			String s=sc.nextLine(),c=code(s);
			if(leftovers.containsKey(c)){
				if(!map.containsKey(c))
					map.put(c,new LinkedList<String>());
				map.get(c).add(s);
				map.get(c).add(leftovers.remove(c));
			}else
				leftovers.put(c,s);
		}
		TreeMap<Integer,LinkedList<String>>leftovers2=new TreeMap<Integer,LinkedList<String>>();
		for(String s:leftovers.values()){
			if(!leftovers2.containsKey(vowels(s)))
				leftovers2.put(vowels(s),new LinkedList<String>());
			leftovers2.get(vowels(s)).add(s);
		}
		//out.println(leftovers2);
		//out.println(map);
		while(!map.isEmpty()){
			String s1="",s3="";
			while(s1.equals("")&&!leftovers2.isEmpty())
				if(leftovers2.get(leftovers2.firstKey()).size()<2)
					leftovers2.remove(leftovers2.firstKey());
				else{
					s1=leftovers2.get(leftovers2.firstKey()).removeFirst();
					s3=leftovers2.get(leftovers2.firstKey()).removeFirst();
				}
			if(s1.equals("")&&!map.isEmpty()){
				s1=map.get(map.firstKey()).removeFirst();
				s3=map.get(map.firstKey()).removeFirst();
				if(map.get(map.firstKey()).size()==0)
					map.remove(map.firstKey());
			}
			String s2="",s4="";
			if(!map.isEmpty()){
				s2=map.get(map.firstKey()).removeFirst();
				s4=map.get(map.firstKey()).removeFirst();
				if(map.get(map.firstKey()).size()==0)
					map.remove(map.firstKey());
			}
			if(!s1.equals("")&&!s2.equals(""))
				lyrics.add(s1+" "+s2+"\n"+s3+" "+s4);
		}
		out.println(lyrics.size());
		for(String s:lyrics)
			out.println(s);
		// ------------------------
		out.close();
	}
	//------------------------
	private static int vowels(String s){
		String vowels="aeiou";
		int x=0;
		for(char c:s.toCharArray())
			if(vowels.indexOf(c)!=-1)
				x++;
		return x;
	}
	private static String code(String s){
		String vowels="aeiou";
		int v=0;
		char last='%';
		for(char c:s.toCharArray())
			if(vowels.indexOf(c)!=-1){
				v++;
				last=c;
			}
		return v+""+last;
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