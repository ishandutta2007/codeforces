import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		char[]chars=new char[n];
		sc.nextLine();
		chars=sc.nextLine().toCharArray();
		sc.close();
		TreeMap<Character,Integer>counts=new TreeMap<Character,Integer>();
		for(char c:chars)
			if(!counts.containsKey(c))
				counts.put(c,1);
			else
				counts.put(c,counts.get(c)+1);
		for(char c:counts.keySet())
			print(c,counts.get(c));
	}
	public static void print(char c,int n){
		String str=c+""+c+""+c+""+c+""+c+""+c+""+c+""+c+""+c+""+c+""+c+""+c+""+c+""+c+""+c+""+c;
		for(int i=0;i<n/16;i++)
			System.out.print(str);
		for(int i=0;i<n%16;i++)
			System.out.print(c);
	}
}