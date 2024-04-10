import java.util.*;
public class B {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt(),k=sc.nextInt();
		sc.nextLine();
		char[]s=sc.nextLine().toCharArray();
		int[]runsFor=new int[26];
		char last='-';
		int len=0;
		for(int i=0;i<s.length;i++){
			if(s[i]==last)
				len++;
			else
				len=1;
			if(len==k){
				runsFor[s[i]-97]++;
				len=0;
				last='-';
			}else
				last=s[i];
		}
		int max=0;
		for(int i:runsFor)
			max=Math.max(max, i);
		System.out.println(max);
		sc.close();
	}
}