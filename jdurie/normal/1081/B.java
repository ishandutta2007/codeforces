import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[]a=new int[n];
		HashMap<Integer,Integer>map=new HashMap<Integer,Integer>();
		for(int i=0;i<n;i++){
			a[i]=sc.nextInt();
			if(!map.containsKey(a[i]))
				map.put(a[i],1);
			else
				map.put(a[i],map.get(a[i])+1);
		}
		boolean bool=false;
		for(int i:map.keySet())
			if(map.get(i)%(n-i)!=0)
				bool=true;
		System.out.println(bool?"Impossible":"Possible");
		if(!bool){
			HashMap<Integer,HashSet<Integer>>runningCt=new HashMap<Integer,HashSet<Integer>>();
			int[]b=new int[n];
			int hatNo=1;
			for(int i=0;i<n;i++){
				if(!runningCt.containsKey(a[i]))
					runningCt.put(a[i],new HashSet<Integer>());
				runningCt.get(a[i]).add(i);
				if(runningCt.get(a[i]).size()==n-a[i]){
					for(int j:runningCt.get(a[i]))
						b[j]=hatNo;
					runningCt.remove(a[i]);
					hatNo++;
				}
			}
			for(int i:b)
				System.out.print(i+" ");
		}
	}
}