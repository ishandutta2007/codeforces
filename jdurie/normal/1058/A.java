import java.util.*;
public class EasyProblem {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		boolean b=true;
		int i=0;
		while(b&&i<n){
			if(sc.nextInt()==1)
				b=false;
			i++;
		}
		if(b)
			System.out.println("EASY");
		else
			System.out.println("HARD");
		sc.close();
	}
}