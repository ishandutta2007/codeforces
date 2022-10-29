import java.util.*;
import java.math.*;
import java.awt.*;

public class Main {
	public static void main(String args[]) {
		Solve a = new Solve();
		a.A();
	}
}

class Solve{
	public void Solve(){
		
	}
	public void A(){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.println(n / 2);
		if (n % 2 == 1){
			for(int i = 1; i < n / 2; i++){
				System.out.print(2 + " ");
			}
			System.out.println(3);
		}
		else{
			for(int i = 1; i <= n / 2; i++){
				System.out.print(2 + (i == n / 2 ? "\n" : " "));
			}
		}
	}
}