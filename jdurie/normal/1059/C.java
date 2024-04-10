import java.util.*;
public class SequenceTransformation2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		int p2 = 1;
		while (n > 0) {
			if (n == 3){
				System.out.println(p2 + " " + p2 + " " + 3 * p2);
				n = 0;
			}
			String s=p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" "+p2+" ";
			for(int i=0;i<(n+1)/32;i++)
				System.out.print(s);
			for(int i=0;i<(n+1)/2%16;i++)
				System.out.print(p2+" ");	
			p2 *= 2;
			n /= 2;
		}
	}
}