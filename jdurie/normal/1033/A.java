import java.util.*;
public class KingEscape {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int ax=sc.nextInt(), ay=sc.nextInt();
		int bx=sc.nextInt(), by=sc.nextInt();
		int cx=sc.nextInt(), cy=sc.nextInt();
		sc.close();
		if(bx>ax!=cx>ax||by>ay!=cy>ay)
			System.out.println("NO");
		else
			System.out.println("YES");
	}
}