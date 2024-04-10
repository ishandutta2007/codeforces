import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[][]obelisks=new int[n][2];
		for(int i=0;i<n;i++)
			obelisks[i]=new int[]{sc.nextInt(),sc.nextInt()};
		TreeSet<String>clues=new TreeSet<String>();
		int[][]cluesArr=new int[n][2];
		for(int i=0;i<n;i++){
			int a=sc.nextInt(),b=sc.nextInt();
			cluesArr[i]=new int[]{a,b};
			clues.add(a+" "+b);
		}
		boolean b=false;
		int[]t=new int[]{0,0};
		for(int i=0;i<n;i++)
			if(!b){
				b=true;
				t=new int[]{obelisks[0][0]+cluesArr[i][0],obelisks[0][1]+cluesArr[i][1]};
				for(int j=1;j<n;j++)
					if(b&&!clues.contains((t[0]-obelisks[j][0])+" "+(t[1]-obelisks[j][1])))
						b=false;
			}
		System.out.println(t[0]+" "+t[1]);
	}
}