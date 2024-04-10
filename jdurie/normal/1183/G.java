//package cf570d3;
import java.io.*;
import java.util.*;

public class G{
	// ------------------------
	static class X implements Comparable<X>{
		int nof, f;
		public X(int N,int F){
			nof=N;
			f=F;
		}
		public int compareTo(X other){
			if(nof!=other.nof)
				return nof-other.nof;
			return other.f-f;
		}
		public String toString(){
			return nof+"/"+f;
		}
	}
	static class Y implements Comparable<Y>{
		int t,f;
		public Y(){
			t=0;
			f=0;
		}
		public int compareTo(Y other){
			return t-other.t;
		}
	}
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int q=sc.nextInt();
		for(int w=0;w<q;w++){
			int n=sc.nextInt();
			Y[]counts=new Y[n];
			for(int i=0;i<n;i++)
				counts[i]=new Y();
			for(int i=0;i<n;i++){
				int x=sc.nextInt()-1;
				counts[x].t++;
				if(sc.nextInt()==0)
					counts[x].f++;
			}
			TreeMap<X,Integer>set=new TreeMap<X,Integer>();
			Arrays.sort(counts);
			LinkedList<Integer>queue=new LinkedList<Integer>();
			int x=Integer.MAX_VALUE;
			for(int i=n-1;i>=0;i--){
				int y=Math.min(x,counts[i].t);
				queue.addLast(y);
				x=Math.max(0,y-1);
			}
			//for(Y y:counts)
				//out.println(y.t+" "+y.f);
			long ans=0,nofAns=0;
			int i=n-1;
			//out.println(queue);
			for(int k:queue)
				if(k>0){
					while(i>=0&&counts[i].t>=k){
						X key=new X(counts[i].t-counts[i].f,counts[i].f);
						set.put(key,set.containsKey(key)?set.get(key)+1:1);
						i--;
					}
					//out.println(set);
					X thisX=set.higherKey(new X(k-1,0));
					if(thisX==null)
						thisX=set.lastKey();
					ans+=k;
					if(set.get(thisX)==1)
						set.remove(thisX);
					else
						set.put(thisX,set.get(thisX)-1);
					nofAns+=Math.min(k,thisX.nof);
				}
			out.println(ans+" "+nofAns);
		}
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