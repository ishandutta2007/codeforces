import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),m=sc.nextInt();
		int[]coords=new int[n+m];
		for(int i=0;i<n+m;i++)
			coords[i]=sc.nextInt();
		int[]drivers=new int[m];
		int ind=0;
		for(int i=0;i<n+m;i++)
			if(sc.nextInt()==1)
				drivers[ind++]=coords[i];
		sc.close();
		int person=0;
		int[]peopleForDriver=new int[m];
		while(coords[person++]!=drivers[0])
			peopleForDriver[0]++;
		int lastD=0;
		while(person<n+m&&coords[person]<=drivers[m-1]){
			if(coords[person]==drivers[lastD+1])
				lastD++;
			else if(coords[person]-drivers[lastD]<=drivers[lastD+1]-coords[person])
				peopleForDriver[lastD]++;
			else
				peopleForDriver[lastD+1]++;
			person++;
		}
		peopleForDriver[lastD]+=n+m-person;
		for(int i:peopleForDriver)
			System.out.print(i+" ");
	}
}