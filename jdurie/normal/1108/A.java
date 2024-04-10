import java.util.*;
public class A {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int q=sc.nextInt();
		for(int i=0;i<q;i++){
			int l1=sc.nextInt();
			System.out.print(l1+" ");
			sc.nextInt();
			int l2=sc.nextInt();
			if(l2!=l1){
				System.out.println(l2);
				sc.nextInt();
			}else
				System.out.println(sc.nextInt());
		}
		sc.close();
	}
}