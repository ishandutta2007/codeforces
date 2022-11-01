import java.util.*;
import java.awt.geom.*;

public class Solution {
	public static void main(String[] args) {
		int w, h, alpha;
		Scanner in = new Scanner(System.in);
		w = in.nextInt();
		h = in.nextInt();
		alpha = in.nextInt();
		Area ar = new Area(new Rectangle2D.Double(-w*0.5, -h*0.5, w, h));
		ar.intersect(ar.createTransformedArea(AffineTransform.getRotateInstance(alpha / 180.0 * Math.PI)));
		PathIterator it = ar.getPathIterator(new AffineTransform());
		double arr[] = new double[6];
		it.currentSegment(arr);
		double sx, px, sy, py;
		sx = px = arr[0];
		sy = py = arr[1];
//		System.err.printf("%.9f %.9f\n", sx, sy);
		it.next();
		double res = 0.0;
		while (!it.isDone()) {
			if (it.currentSegment(arr) == PathIterator.SEG_CLOSE)
				break;
			double x = arr[0];
			double y = arr[1];
//			System.err.printf("%.9f %.9f\n", x, y);
			res += x * py - y * px;
			px = x;
			py = y;
			it.next();
		}
		res += sx * py - sy * px;
		System.out.printf("%.9f\n", Math.abs(res / 2.0));

	}
}