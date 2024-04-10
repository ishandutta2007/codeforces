
import java.awt.*;
import java.awt.geom.*;
import java.io.*;

public class A280{

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str = br.readLine();
		int ia = str.indexOf(' '), ib = str.lastIndexOf(' ');
		double w = Integer.parseInt(str.substring(0, ia));
		double h = Integer.parseInt(str.substring(ia + 1, ib));
		double a = Integer.parseInt(str.substring(ib + 1));
		Rectangle2D.Double rect = new Rectangle2D.Double(w * -0.5, h * -0.5, w, h);
		Shape rect2 = AffineTransform.getRotateInstance(Math.toRadians(a)).createTransformedShape(rect);
		Area union = new Area(rect);
		union.intersect(new Area(rect2));
		PathIterator path = union.getPathIterator(new AffineTransform());
		double[] darray = new double[6];
		path.currentSegment(darray);
		double x0 = darray[0], y0 = darray[1];
		double x1 = x0, y1 = y0;
		path.next();
		double area = 0;
		while( path.currentSegment(darray) != PathIterator.SEG_CLOSE ){
			double x2 = darray[0], y2 = darray[1];
			area += x1 * y2 - y1 * x2;
			x1 = x2; y1 = y2;
			path.next();
		}
		System.out.println(Math.abs((area + x1 * y0 - y1 * x0) / 2));
	}
}