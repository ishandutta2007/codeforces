import java.util.*;
public class PsychosInALine {
	public static void main(String[]args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Stack<Integer>st1=new Stack<Integer>();
		Stack<Integer>st2=new Stack<Integer>();
		Stack<Integer>st3=new Stack<Integer>();
		int maxRound=0;
		for(int i=0;i<n;i++)
			st1.push(sc.nextInt());
		while(!st1.isEmpty()){
			int round=0;
			while(!st2.isEmpty()&&st1.peek()>st2.peek()){
				st2.pop();
				round=Math.max(round+1,st3.pop());
			}
			st2.push(st1.pop());
			st3.push(round);
			if(round>maxRound)
				maxRound=round;
		}
		sc.close();
		System.out.println(maxRound);
	}
}