
import java.io.*;
import java.util.*;

public class E {
	// ------------------------

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));
		// ------------------------
		int n=sc.nextInt(),k=sc.nextInt();
		int[]leftEnd=new int[n];
		int[]rightEnd=new int[n];
		int[]team=new int[n];
		int[]arr=new int[n];
		int[]indOf=new int[n];
		for(int i=0;i<n;i++){
			leftEnd[i]=i;
			rightEnd[i]=i;
			arr[i]=sc.nextInt()-1;
			indOf[arr[i]]=i;
		}
		int currT=1;
		for(int j=n-1;j>=0;j--){
			int i=indOf[j];
			if(team[i]==0){
				team[i]=currT;
				int left=i,right=i,lCt=0,rCt=0;
				while(lCt<k&&left>=0){
					if(team[left]>0)
						left=leftEnd[left];
					if(team[left]==0){
						team[left]=currT;
						lCt++;
					}
					left--;
				}
				while(rCt<k&&right<n){
					if(team[right]>0)
						right=rightEnd[right];
					if(team[right]==0){
						team[right]=currT;
						rCt++;
					}
					right++;
				}
				left=Math.max(0,left);
				right=Math.min(n-1,right);
				leftEnd[right]=left;
				rightEnd[left]=right;
				currT=3-currT;
			}
		}
		for(int i:team)
			out.print(i);
		out.println();
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