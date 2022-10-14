import java.util.*;
public class E {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long n=sc.nextLong(),k=sc.nextLong();
		sc.close();
		if(n>(k-1)*k)
			System.out.println("NO");
		else{
			System.out.println("YES");
			long a=1,b=2;
			for(long i=0;i<n;i++){
				if(i%2==0)
					System.out.println(a+" "+b);
				else{
					System.out.println(b+" "+a);
					b++;
					if(b>k){
						a++;
						b=a+1;
					}
				}
			}
		}
	}
}