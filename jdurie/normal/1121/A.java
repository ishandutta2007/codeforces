import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt(),k=sc.nextInt();
		int[]p=new int[n];
		for(int i=0;i<n;i++)
			p[i]=sc.nextInt();
		int[]sch=new int[n];
		int[]max=new int[m];
		for(int i=0;i<n;i++){
			sch[i]=sc.nextInt()-1;
			max[sch[i]]=Math.max(max[sch[i]],p[i]);
		}
		int ct=0;
		for(int i=0;i<k;i++){
			int h=sc.nextInt()-1;
			if(p[h]!=max[sch[h]])
				ct++;
		}
		System.out.println(ct);
		sc.close();
	}
}