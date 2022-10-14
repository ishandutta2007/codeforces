import java.util.*;
public class B {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		HashMap<Integer,Integer>divs=new HashMap<Integer,Integer>();
		int max=0;
		for(int i=0;i<n;i++){
			int x=sc.nextInt();
			if(divs.containsKey(x))
				divs.put(x,divs.get(x)+1);
			else
				divs.put(x,1);
			if(x>max)
				max=x;
		}
		for(int i=1;i<=max;i++)
			if(max%i==0){
				if(divs.get(i)==1)
					divs.remove(i);
				else
					divs.put(i, divs.get(i)-1);
			}
		int max2=0;
		for(int i:divs.keySet())
			if(i>max2)
				max2=i;
		System.out.println(max+" "+max2);
		sc.close();
	}
}