import java.util.*;
import java.io.*;
public class ColorTheFence {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		PrintWriter out=new PrintWriter(new BufferedOutputStream(System.out));
		int v=sc.nextInt();
		TreeMap<Integer,Integer>map=new TreeMap<Integer,Integer>();
		for(int i=1;i<=9;i++)
			map.put(sc.nextInt(),i);
		sc.close();
		int min=map.firstKey();
		if(v<min)
			out.println(-1);
		while(v>=min){
			int i=maxBelow(map,v%min+min);
			out.print(map.get(i));
			v-=i;
		}
		out.close();
	}
	public static int maxBelow(TreeMap<Integer,Integer>map,int i){
		int maxKey=-1;
		for(int k:map.descendingKeySet())
			if(k<=i&&(maxKey==-1||map.get(k)>map.get(maxKey)))
				maxKey=k;
		return maxKey;
	}
}