import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		int k=sc.nextInt();
		sc.close();
		LinkedList<Integer>snow=new LinkedList<Integer>();
		LinkedList<Integer>canes=new LinkedList<Integer>();
		String real="";
		for(int i=0;i<s.length();i++)
			if(s.charAt(i)=='?')
				canes.addLast(i-snow.size()-canes.size()-1);
			else if(s.charAt(i)=='*')
				snow.addLast(i-snow.size()-canes.size()-1);
			else
				real+=s.charAt(i);
		boolean possible=true;
		while(k<real.length()&&possible)
			if(!canes.isEmpty()&&!snow.isEmpty()){
				real=remove(real,canes.getLast()>snow.getLast()?canes.removeLast():snow.removeLast());
			}else if(!canes.isEmpty())
				real=remove(real,canes.removeLast());
			else if(!snow.isEmpty())
				real=remove(real,snow.removeLast());
			else
				possible=false;
		if(k>real.length())
			if(!snow.isEmpty())
				real=fill(real,snow.removeFirst(),k-real.length());
			else
				possible=false;
		System.out.println(possible?real:"Impossible");
	}
	private static String remove(String s,int i){
		return s.substring(0,i)+s.substring(i+1,s.length());
	}
	private static String fill(String s,int i,int k){
		String st=s.substring(0,i+1);
		for(int j=0;j<k;j++)
			st+=s.charAt(i);
		return st+s.substring(i+1,s.length());
	}
}