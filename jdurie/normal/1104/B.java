import java.util.*;
public class B {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		String s=sc.nextLine();
		sc.close();
		LinkedList<Character> l=new LinkedList<Character>();
		for(int i=0;i<s.length();i++)
			l.addLast(s.charAt(i));
		ListIterator<Character>it=l.listIterator();
		int matches=0;
		while(it.hasNext()){
			char a=it.next();
			if(it.hasNext()){
				char b=it.next();
				if(a==b){
					it.remove();
					it.previous();
					it.remove();
					matches++;
				}
				if(it.hasPrevious())
					it.previous();
			}
		}
		System.out.println(matches%2==0?"No":"Yes");
	}
}