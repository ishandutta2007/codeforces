import java.util.*;
public class CollectingBeatsIsFun {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int k=sc.nextInt();
		sc.nextLine();
		int[]counts=new int[10];
		for(int i=0;i<4;i++){
			String s=sc.nextLine();
			for(int j=0;j<4;j++)
				if(s.charAt(j)!='.')
					counts[Integer.parseInt(s.charAt(j)+"")]++;
		}
		sc.close();
		int max=0;
		for(int i=1;i<10;i++)
			if(counts[i]>max)
				max=counts[i];
		System.out.println(max<=2*k?"YES":"NO");
	}
}