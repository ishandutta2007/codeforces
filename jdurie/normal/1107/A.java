import java.util.*;

public class A {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int q=sc.nextInt();
		sc.nextLine();
		for(int i=0;i<q; i++){
			int n=sc.nextInt();
			sc.nextLine();
			String s=sc.nextLine();
			if(n==2&&s.charAt(0)>=s.charAt(1))
				System.out.println("NO");
			else{
				System.out.println("YES\n2");
				System.out.println(s.charAt(0)+" "+s.substring(1));
			}
		}
		sc.close();
	}
}