import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int w=sc.nextInt(),h=sc.nextInt();
		int u1=sc.nextInt(),d1=sc.nextInt();
		int u2=sc.nextInt(),d2=sc.nextInt();
		sc.close();
		for(int i=h;i>=0;i--){
			w+=i;
			if(i==d1)
				w=Math.max(0,w-u1);
			if(i==d2)
				w=Math.max(0, w-u2);
		}
		System.out.println(w);
	}
}