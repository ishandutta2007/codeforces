import java.util.*;
public class BubbleSortGraph {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		ArrayList<Integer>lasts=new ArrayList<Integer>();
		for(int i=0;i<n;i++){
			int num=sc.nextInt();
			int j=bSearch(lasts,num,0,lasts.size()-1);
			if(j==-1)
				lasts.add(num);
			else
				lasts.set(j,num);
		}
		sc.close();
		System.out.println(lasts.size());
	}
	private static int bSearch(ArrayList<Integer>list,int num,int start,int end){
		if(list.isEmpty())
			return -1;
		if(end-start<2)
			return list.get(start)>num?start:(list.get(end)>num?end:-1);
		int mid=(start+end)/2;
		if(list.get(mid)>num)
			return bSearch(list,num,start,mid);
		else
			return bSearch(list,num,mid+1,end);
	}
}