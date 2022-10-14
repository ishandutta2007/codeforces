import java.util.*;
public class C {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.nextLine();
		HashMap<Integer,Integer>forwards=new HashMap<Integer,Integer>();
		HashMap<Integer,Integer>backwards=new HashMap<Integer,Integer>();
		for(int i=0;i<n;i++){
			String s=sc.nextLine();
			int sum=0;
			boolean f=true;
			for(int c=0;c<s.length();c++){
				sum+=s.charAt(c)=='('?1:-1;
				if(sum<0)
					f=false;
			}
			if(f)
				forwards.put(sum,forwards.containsKey(sum)?forwards.get(sum)+1:1);
			sum=0;
			boolean b=true;
			for(int c=s.length()-1;c>=0;c--){
				sum+=s.charAt(c)==')'?1:-1;
				if(sum<0)
					b=false;
			}
			if(b)
				backwards.put(sum,backwards.containsKey(sum)?backwards.get(sum)+1:1);
		}
		int sets=0;
		for(int i:forwards.keySet()){
			if(i==0)
				sets+=forwards.get(i)/2;
			else if(backwards.containsKey(i)){
				sets+=Math.min(forwards.get(i),backwards.get(i));
			}
		}
		System.out.println(sets);
		sc.close();
	}
}