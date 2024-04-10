import java.util.*;
public class Cornfield {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int d=sc.nextInt();
		int m=sc.nextInt();
		for(int i=0;i<m;i++){
			int x=sc.nextInt();
			int y=sc.nextInt();
			if(y>=x-d&&y<=x+d&&x+y>=d&&x+y<=2*n-d)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
		sc.close();
	}
}