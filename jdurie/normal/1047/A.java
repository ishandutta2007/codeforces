import java.util.*;
public class LittleC3I {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.close();
		if(n%3==2){
			System.out.print(1+" "+2+" "+(n-3));
		}else{
			System.out.print(1+" "+1+" "+(n-2));
		}
	}

}