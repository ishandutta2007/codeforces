import java.util.*;
public class A {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		HashSet<Integer>set=new HashSet<Integer>();
		int r1=sc.nextInt();
		for(int j=0;j<r1;j++)
			set.add(sc.nextInt());
		for(int i=1;i<n;i++){
			int r=sc.nextInt();
			HashSet<Integer>temp=new HashSet<Integer>();
			for(int j=0;j<r;j++){
				int num=sc.nextInt();
				if(set.contains(num))
					temp.add(num);
			}
			set=temp;
		}
		sc.close();
		for(int i:set)
			System.out.print(i+" ");
	}
}