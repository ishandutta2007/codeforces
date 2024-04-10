import java.util.*;
public class D {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		HashMap<Integer,TreeSet<Integer>>map=new HashMap<Integer,TreeSet<Integer>>();
		for(int i=1;i<=n;i++)
			map.put(i,new TreeSet<Integer>());
		for(int i=1;i<=n;i++){
			map.get(i).add(sc.nextInt());
			map.get(i).add(sc.nextInt());
		}
		sc.close();
		int curr=1;
		boolean[]used=new boolean[n];
		do{
			System.out.print(curr+" ");
			used[curr-1]=true;
			int a=map.get(curr).first(),b=map.get(curr).last();
			if(!used[b-1]&&map.get(b).contains(a))
				curr=b;
			else
				curr=a;
		}while(curr!=1);
	}
}