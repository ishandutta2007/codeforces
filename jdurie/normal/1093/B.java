import java.util.*;
public class B {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		sc.nextLine();
		for(int i=0;i<t;i++){
			HashMap<Character,Integer>map=new HashMap<Character,Integer>();
			String s=sc.nextLine();
			for(int c=0;c<s.length();c++){
				char ch=s.charAt(c);
				if(!map.containsKey(ch))
					map.put(ch,1);
				else
					map.put(ch,map.get(ch)+1);
			}
			if(map.keySet().size()<2)
				System.out.print(-1);
			else
				for(char c:map.keySet()){
					int js=map.get(c);
					for(int j=0;j<js;j++)
						System.out.print(c);
				}
			System.out.println();
		}
		sc.close();
	}
}