import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String[]s1=sc.nextLine().split(":");
		String[]s2=sc.nextLine().split(":");
		int h=i(s2[0])-i(s1[0]),m=i(s2[1])-i(s1[1]);
		while(m<0){
			h--;
			m+=60;
		}
		if(h%2==1){
			h--;
			m+=60;
		}
		h=i(s1[0])+h/2;
		m=i(s1[1])+m/2;
		while(m>=60){
			m-=60;
			h++;
		}
		while(m<0){
			h--;
			m+=60;
		}
		System.out.println((h<10?"0":"")+h+":"+(m<10?"0":"")+m);
		sc.close();
	}
	private static int i(String s){
		return Integer.parseInt(s);
	}
}