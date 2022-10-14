import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int pos=0,neg=0;
		for(int i=0;i<n;i++){
			int a=sc.nextInt();
			if(a>0)
				pos++;
			else if(a<0)
				neg++;
		}
		sc.close();
		if(pos>=Math.ceil(n/2.0))
			System.out.println(1);
		else if(neg>=Math.ceil(n/2.0))
			System.out.println(-1);
		else
			System.out.println(0);
	}
}