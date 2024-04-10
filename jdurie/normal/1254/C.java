//package cf601d1;
import java.util.*;
import static java.lang.Math.*;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), min = 2;
		for(int i = 3; i <= n; i++) {
			System.out.println("2 1 " + min + " " + i);
			System.out.flush();
			if(sc.nextInt() == 1) min = i;
		}
		ArrayList<Pair> list = new ArrayList<Pair>();
		for(int i = 2; i <= n; i++)
			if(i != min) {
				System.out.println("1 1 " + min + " " + i);
				System.out.flush();
				list.add(new Pair(i, sc.nextLong()));
			}
		Collections.sort(list);
		LinkedList<Integer> from1 = new LinkedList<Integer>();
		LinkedList<Integer> fromMin = new LinkedList<Integer>();
		int last = list.get(list.size() - 1).i;
		for(int i = 0; i < list.size() - 1; i++) {
			System.out.println("2 1 " + list.get(i).i + " " + last);
			System.out.flush();
			if(sc.nextInt() == -1) 
				fromMin.addLast(list.get(i).i);
			else
				from1.addLast(list.get(i).i);
		}
		//System.out.println(min + " " + last);
		//System.out.println(fromMin + " " + from1);
		System.out.print("0 1");
		while(!from1.isEmpty())
			System.out.print(" " + from1.pollFirst());
		System.out.print(" " + last);
		while(!fromMin.isEmpty())
			System.out.print(" " + fromMin.pollLast());
		System.out.print(" " + min);
		System.out.flush();
	}
	static class Pair implements Comparable<Pair> {
		int i;
		long a;
		public Pair(int I, long A) {
			i = I;
			a = A;
		}
		public int compareTo(Pair p) {
			return ((Long)a).compareTo(p.a);
		}
	}
}