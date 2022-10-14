import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		long a=sc.nextLong();
		long b=sc.nextLong();
		sc.close();
		ArrayList<Integer>aList=new ArrayList<Integer>();
		ArrayList<Integer>bList=new ArrayList<Integer>();
		int max=(int)Math.floor(-.5+Math.sqrt(.25+2*(a+b)));
		for(int i=max;i>=1;i--)
			if(a>b){
				a-=i;
				aList.add(i);
			}else{
				b-=i;
				bList.add(i);
			}
		System.out.println(aList.size());
		for(int j:aList)
			System.out.print(j+" ");
		System.out.println("\n"+bList.size());
		for(int k:bList)
			System.out.print(k+" ");
	}
}