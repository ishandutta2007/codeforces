//package cf568d2;
import java.util.*;
public class B {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int q=sc.nextInt();
        sc.nextLine();
        for(int w=0;w<q;w++){
            char[]s1=sc.nextLine().toCharArray();
            char[]s2=sc.nextLine().toCharArray();
            LinkedList<Character>c1=new LinkedList<Character>(),c2=new LinkedList<Character>();
            LinkedList<Integer>l1=new LinkedList<Integer>(),l2=new LinkedList<Integer>();
            fill(s1,c1,l1);
            fill(s2,c2,l2);
            boolean ok=true;
            //System.out.println(c1+" "+l1);
            //System.out.println(c2+" "+l2);
            while(ok&&!c1.isEmpty())
                if(c2.isEmpty()||c1.pollFirst()!=c2.pollFirst()||l1.pollFirst()>l2.pollFirst())
                    ok=false;
            System.out.println(ok&&c2.isEmpty()?"YES":"NO");
        }
    }
    private static void fill(char[]s,LinkedList<Character>c,LinkedList<Integer>l){
        char last='}';
        for(char ch:s)
            if(ch==last)
                l.addLast(l.removeLast()+1);
            else{
                c.addLast(ch);
                l.addLast(1);
                last=ch;
            }
    }
}