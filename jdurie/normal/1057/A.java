import java.util.*;
public class BmailNetwork {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]parent=new int[n];
		for(int i=1;i<n;i++)
			parent[i]=sc.nextInt()-1;
		sc.close();
		LinkedList<Integer>list=new LinkedList<Integer>();
		int num=n-1;
		while(num!=0){
			list.addFirst(num+1);
			num=parent[num];
		}
		list.addFirst(1);
		for(int i:list)
			System.out.print(i+" ");
	}
}