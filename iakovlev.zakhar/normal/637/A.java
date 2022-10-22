import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;

public class A {

	static class Foto implements Comparable<Foto> {
		int numberLike;
		int lastLike;
		int number;

		public Foto(int numberLike, int lastLike, int number) {
			this.lastLike = lastLike;
			this.numberLike = numberLike;
			this.number = number;
		}

		@Override
		public int compareTo(Foto that) {
			// TODO Auto-generated method stub
			if (this.numberLike != that.numberLike) {
				return this.numberLike - that.numberLike;
			}
			return that.lastLike - this.lastLike;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		TreeMap<Integer, Foto> tree = new TreeMap<>();
		ArrayList<Integer> keys = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int x = in.nextInt();
			if (tree.containsKey(x)) {
				tree.put(x, new Foto(tree.get(x).numberLike + 1, i, x));
			} else {
				tree.put(x, new Foto(1, i, x));
				keys.add(x);
			}
		}
		Foto foto = new Foto(0, 0, 0);
		for (int i = 0; i < keys.size(); i++) {
			if (tree.get(keys.get(i)).compareTo(foto) > 0) {
				foto = tree.get(keys.get(i));
			}
		}
		System.out.println(foto.number);
	}

}