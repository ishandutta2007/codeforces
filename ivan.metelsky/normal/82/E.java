import java.util.*;
import java.io.*;

public class Solution {
    int n, h, f;
    
    class Window {
        double l, r;
        public Window(double l, double r) {
            if (l == 0.0)
                l = 1e-9;
            
            this.l = l;
            this.r = r;
        }
    }
    
    class Line {
        double x1, y1, x2, y2;
        double A, B, C;
        
        public Line(double x1, double y1, double x2, double y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
            
            this.A = y2 - y1;
            this.B = x1 - x2;
            this.C = -A * x1 - B * y1;
        }
    }
    
    class Point {
        double x, y;
        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }
    
    Point intr(Line l1, Line l2) {
        return new Point((l2.C * l1.B - l1.C * l2.B) / (l1.A * l2.B - l2.A * l1.B),
                (l2.C * l1.A - l1.C * l2.A) / (l1.B * l2.A - l2.B * l1.A));
    }
        
    double area(Point[] pnt) {
        double res = 0;
        int n = pnt.length;
        for (int i=0; i < n; i++) {
            int ii = i == n - 1 ? 0 : i + 1;
            res += (pnt[ii].x - pnt[i].x) * (pnt[ii].y + pnt[i].y);
        }
        return Math.abs(res) / 2.0;
    }
    
    
    double areaAbove(Point[] pp, double h) {
        int n = pp.length;
        Point[] pnt = new Point[n];
        for (int i=0; i < n; i++)
            pnt[i] = new Point(pp[i].x, pp[i].y - h);
        
        double res = 0;
        for (int i=0; i < n; i++) {
            int ii = i == n - 1 ? 0 : i + 1;
            
            if (pnt[i].y >= 0 && pnt[ii].y >= 0) {
                res += (pnt[ii].x - pnt[i].x) * (pnt[ii].y + pnt[i].y);
            } else if (pnt[i].y < 0 && pnt[ii].y >= 0) {
                Point mid = intr(new Line(pnt[i].x, pnt[i].y, pnt[ii].x, pnt[ii].y),
                        new Line(0, 0, 1, 0));
                res += (pnt[ii].x - mid.x) * (pnt[ii].y + mid.y);
            } else if (pnt[i].y >= 0 && pnt[ii].y < 0) {
                Point mid = intr(new Line(pnt[i].x, pnt[i].y, pnt[ii].x, pnt[ii].y),
                        new Line(0, 0, 1, 0));
                res += (mid.x - pnt[i].x) * (mid.y + pnt[i].y); 
            }
        }
        return Math.abs(res) / 2.0;
    }

    
    double solve(List<Window> wins) {
        double res = 0.0;
        
        int n = wins.size();
        
        Line top = new Line(-1, h, 1, h);
        
        List<Window> opp = new ArrayList<Window>();
        
        for (int i=0; i < n; i++) {
            opp.add(new Window(intr(top, new Line(0, -f, wins.get(i).l, -h)).x,
                    intr(top, new Line(0, -f, wins.get(i).r, -h)).x));
        }
        
        for (int i=0; i < n; i++) {
            res += 2 * area(new Point[] {
                new Point(wins.get(i).l, -h),
                new Point(opp.get(i).l, h),
                new Point(opp.get(i).r, h),
                new Point(wins.get(i).r, -h)
            });
        }
        
        for (int i=0; i < n; i++)
            for (int j=0; j < n; j++) {
                Line li_left = new Line(wins.get(i).l, -h, opp.get(i).l, h);
                Line li_right = new Line(wins.get(i).r, -h, opp.get(i).r, h);
                
                Line lj_left = new Line(wins.get(j).l, h, opp.get(j).l, -h);
                Line lj_right = new Line(wins.get(j).r, h, opp.get(j).r, -h);
                
                Point[] pnt = new Point[] {
                    intr(li_left, lj_left),
                    intr(li_left, lj_right),
                    intr(li_right, lj_right),
                    intr(li_right, lj_left)
                };
                
                double intrArea = areaAbove(pnt, -h) - areaAbove(pnt, h);
                
                res -= intrArea;
            }
        
        return res;
    }
    
    public void go() throws Exception {
        Scanner sc = new Scanner(new InputStreamReader(System.in));
        n = sc.nextInt();
        h = sc.nextInt();
        f = sc.nextInt();
        List<Window> pos = new ArrayList<Window>();
        List<Window> neg = new ArrayList<Window>();
        for (int i=0; i < n; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            if (l >= 0 && r >= 0) {
                pos.add(new Window(l, r));
            } else if (l <= 0 && r <= 0) {
                neg.add(new Window(-r, -l));
            } else {
                pos.add(new Window(0, r));
                neg.add(new Window(0, -l));
            }
        }
        sc.close();
        
        System.out.println(solve(pos) + solve(neg));
    }
    
    public static void main(String[] args) throws Exception {
        (new Solution()).go();
    }
}