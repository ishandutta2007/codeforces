import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int r=sc.nextInt();
		int[]heaters=new int[n];
		for(int i=0;i<n;i++)
			heaters[i]=sc.nextInt();
		sc.close();
		int needsHeat=0;
		int h=0;
		boolean possible=true;
		while(possible&&needsHeat<n){
			boolean needs=true;
			int i=Math.min(needsHeat+r-1,n-1);
			while(needs&&i>=0&&i>=needsHeat-r+1){
				if(heaters[i]==1){
					needs=false;
					h++;
				}else
					i--;
			}
			if(needs)
				possible=false;
			else
				needsHeat=i+r;
		}
		if(possible)
			System.out.println(h);
		else
			System.out.println(-1);
		
	}
}