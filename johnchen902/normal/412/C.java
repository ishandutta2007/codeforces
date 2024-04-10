import static java.util.stream.IntStream.range;
import static java.util.stream.Stream.generate;
import static java.util.stream.Stream.of;
import static java.lang.System.out;

import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		try (Scanner scan = new Scanner(System.in)) {
			int n = scan.nextInt();
			String[] strs = generate(scan::next).limit(n)
					.toArray(String[]::new);
			range(0, strs[0].length())
					.mapToObj(
							(i) -> of(strs).map((str) -> str.charAt(i))
									.filter((c) -> c != '?').distinct()
									.reduce((l, r) -> '?'))
					.map((c) -> c.orElse('x')).forEach(out::print);
			out.println();
		}
	}
}