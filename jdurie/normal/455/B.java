import java.util.*;
public class ALotOfGames {
	private static HashMap<String,HashSet<String>>tree=new HashMap<String,HashSet<String>>();
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt(),k=sc.nextInt();
		sc.nextLine();
		tree.put("",new HashSet<String>());
		for(int i=0;i<n;i++){
			String s=sc.nextLine(),last="";
			for(int c=0;c<s.length();c++){
				String next=last+s.charAt(c);
				if(!tree.containsKey(next))
					tree.put(next,new HashSet<String>());
				tree.get(last).add(next);
				last=next;
			}
		}
		sc.close();
		System.out.println(can("",false)&&(can("",true)||k%2==1)?"First":"Second");
	}
	public static boolean can(String s,boolean odd){
		if(tree.get(s).isEmpty())
			return odd;
		boolean can=false;
		for(String st:tree.get(s))
			if(!can(st,odd))
				can=true;
		return can;
	}
}