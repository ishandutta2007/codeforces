import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long[]coords=new long[]{10000*sc.nextInt()+sc.nextInt(),10000*sc.nextInt()+sc.nextInt(),10000*sc.nextInt()+sc.nextInt()};
		Arrays.sort(coords);
		int[][]xy=new int[][]{{(int)(coords[0]/10000),(int)(coords[0]%10000)},{(int)(coords[1]/10000),(int)(coords[1]%10000)},{(int)(coords[2]/10000),(int)(coords[2]%10000)}};
		ArrayList<Integer>x=new ArrayList<Integer>();
		ArrayList<Integer>y=new ArrayList<Integer>();
		for(int i=xy[0][0];i<=xy[1][0];i++){
			x.add(i);
			y.add(xy[0][1]);
		}
		if(xy[0][1]<xy[1][1])
			for(int i=xy[0][1]+1;i<=xy[1][1];i++){
				y.add(i);
				x.add(xy[1][0]);
			}
		else
			for(int i=xy[0][1]-1;i>=xy[1][1];i--){
				y.add(i);
				x.add(xy[1][0]);
			}
		int min=Math.min(xy[0][1],xy[1][1]),max=Math.max(xy[0][1],xy[1][1]);
		if(xy[2][1]<min)
			for(int i=min-1;i>=xy[2][1];i--){
				y.add(i);
				x.add(xy[1][0]);
			}
		else if(xy[2][1]>max)
			for(int i=max+1;i<=xy[2][1];i++){
				y.add(i);
				x.add(xy[1][0]);
			}
		for(int i=xy[1][0]+1;i<=xy[2][0];i++){
			x.add(i);
			y.add(xy[2][1]);
		}
		System.out.println(x.size());
		for(int i=0;i<x.size();i++)
			System.out.println(x.get(i)+" "+y.get(i));
		sc.close();
	}
}