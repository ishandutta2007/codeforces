import java.util.*;
public class LittleGirlMaxXOR {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		System.out.println((long)Math.pow(2,pow(sc.nextLong()^sc.nextLong())+1)-1);
		sc.close();
	}
	public static int pow(long a){
		return a==0?-1:(int)Math.floor(Math.log(a)/Math.log(2));
	}
}