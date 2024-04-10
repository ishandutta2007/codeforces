import java.util.*;
import java.io.*;

public class B {
	FastScanner in;
	PrintWriter out;
	boolean systemIO = true;

	public static class Person implements Comparable<Person> {
		String name;
		int region;
		int skill;

		public Person(String name, int region, int skill) {
			this.name = name;
			this.region = region;
			this.skill = skill;
		}

		@Override
		public int compareTo(Person o) {
			// TODO Auto-generated method stub
			if (o == null) {
				return -1;
			}
			if (this.equals(null)) {
				return 1;
			}
			if (this.region != o.region) {
				return -o.region + this.region;
			}
			if (this.skill != o.skill) {
				return -(this.skill - o.skill);
			}
			return 0;
		}
		
		
	}
	
	public Person[] MergeSort1(Person[] a, int l, int r) {
    	if (r - l == 1) {
    		Person[] b = {a[l]};
			return b;
		}
    	Person[] c = MergeSort1(a, l, (r + l) / 2);
    	Person[] d = MergeSort1(a, (l + r) / 2, r);
    	return Merge(c, d);
	}
    
    public Person[] Merge(Person[] a, Person[] b) {
		Person[] ans = new Person[a.length + b.length];
		int x = 0;
		int y = 0;
		while (x < a.length && y < b.length) {
			if (a[x].compareTo(b[y]) > 0) {
				ans[x + y] = b[y];
				y++;
			} else {
				ans[x + y] = a[x];
				x++;
			}
		}
		while (x < a.length) {
			ans[x + y] = a[x];
			x++;
		}
		while (y < b.length) {
			ans[x + y] = b[y];
			y++;
		}
		return ans;
	}

//	public void solve() {
//		d();
//		int n = in.nextInt();
//		int m = in.nextInt();
//		TreeSet<Person>[] p = new TreeSet[3];
//		System.out.println(p.length);
//		Person u = null;
//		for (int i = 0; i < n; i++) {
//			String s = in.next();
//			int region = in.nextInt();
//			int skill = in.nextInt();
//			System.out.println(region);
//			p[region - 1].add(new Person(s, region, skill));
//		}
//		for (int i = 0; i < p.length; i++) {
//			if (p[i].size() == 2) {
//				out.println(p[i].pollFirst().name + " " + p[i].pollFirst().name);
//			} else {
//				String name1 = p[i].pollFirst().name;
//				Person p1 = p[i].pollFirst();
//				Person p2 = p[i].pollFirst();
//				if (p1.compareTo(p2) != 0) {
//					out.println(name1 + " " + p1.name);
//				} else {
//					out.println("?");
//				}
//			}
//		}
//	}
	
	public void d() {
		int n = in.nextInt();
		int m = in.nextInt();
		Person[][] p = new Person[m][];
		int[] number = new int[m];
		Person[] u = new Person[n];
		for (int i = 0; i < n; i++) {
			String s = in.next();
			int region = in.nextInt();
			int skill = in.nextInt();
//			System.out.println(region);
			u[i] = (new Person(s, region, skill));
			number[region - 1]++;
		}
		u = MergeSort1(u, 0, u.length);
		int x = 0;
		for (int i = 0; i < m; i++) {
			p[i] = new Person[number[i]];
			for (int j = 0; j < p[i].length; j++) {
				p[i][j] = u[x];
				x++;
			}
		}
		for (int i = 0; i < p.length; i++) {
			p[i] = MergeSort1(p[i], 0 , p[i].length);
		}
		for (int i = 0; i < p.length; i++) {
//			System.out.println("   l");
//			for (int j = 0; j < p[i].length; j++) {
//				System.out.println("llll" + p[i][j].name);
//			}
			if (p[i].length == 2 || p[i][2] == null || p[i][1].compareTo(p[i][2]) < 0) {
				out.println(p[i][0].name + " " + p[i][1].name);
			} else {
				out.println("?");
			}
		}
	}

	public void run() {
		try {
			if (systemIO) {
				in = new FastScanner(System.in);
				out = new PrintWriter(System.out);
			} else {
				in = new FastScanner(new File("segments.in"));
				out = new PrintWriter(new File("segments.out"));
			}
			d();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				return null;
			}
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
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

	}

	// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
	public static void main(String[] arg) {
		new B().run();
	}
}