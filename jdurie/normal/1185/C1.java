//package cf568d2;
import java.util.*;
public class C {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt();
        LinkedList<Integer>prev=new LinkedList<Integer>();
        for(int i=0;i<n;i++){
            int x=sc.nextInt(),sum=x,ct=0;
            LinkedList<Integer>temp=new LinkedList<Integer>();
            while(sum<=m&&!prev.isEmpty()){
                temp.add(prev.getFirst());
                sum+=prev.removeFirst();
                ct++;
            }
            for(int y:temp)
                prev.add(y);
            prev.add(x);
            Collections.sort(prev);
            if(sum>m)
                ct--;
            System.out.print((i-ct)+" ");
        }
        System.out.println();
    }
}