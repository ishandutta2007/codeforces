import java.util.*;
public class CoverPoints {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int max=0;
		for(int i=0;i<n;i++){
			int num=sc.nextInt()+sc.nextInt();
			if(num>max)
				max=num;
		}
		sc.close();
		System.out.println(max);
	}
}