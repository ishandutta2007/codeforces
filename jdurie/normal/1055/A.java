import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),s=sc.nextInt();
		if(sc.nextInt()==0)
			System.out.println("NO");
		else{
			for(int i=1;i<s-1;i++)sc.nextInt();
			if(sc.nextInt()==1)
				System.out.println("YES");
			else{
				int[]arr=new int[n-s];
				for(int i=0;i<n-s;i++)
					arr[i]=sc.nextInt();
				for(int i=0;i<s-1;i++)sc.nextInt();
				if(sc.nextInt()==0)
					System.out.println("NO");
				else{
					boolean b=false;
					for(int i=0;i<n-s;i++)
						if(sc.nextInt()==1&&arr[i]==1)
							b=true;
					System.out.println(b?"YES":"NO");
				}
			}
		}
		sc.close();
	}
}