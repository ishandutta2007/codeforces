import java.util.*;
public class SerejaArrangement {
    public static void main(String[]args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),m=sc.nextInt();
        int l=(int)((1.0+Math.sqrt(8*n-7))/2.0);
        if(l%2==0&&l>(int)Math.sqrt(2*n))
            l--;
        TreeMap<Integer,Integer>costs=new TreeMap<Integer,Integer>();
        for(int i=0;i<Math.min(l,m);i++){
            sc.nextInt();
            int c=sc.nextInt();
            costs.put(c,costs.containsKey(c)?costs.get(c)+1:1);
        }
        for(int i=l;i<m;i++){
            sc.nextInt();
            int c=sc.nextInt(),f=costs.firstKey();
            if(c>f){
                if(costs.get(f)==1)
                    costs.remove(f);
                else
                    costs.put(f,costs.get(f)-1);
                costs.put(c,costs.containsKey(c)?costs.get(c)+1:1);
            }
        }
        long cost=0;
        for(int i:costs.keySet())
            cost+=i*costs.get(i);
        System.out.println(cost);
    }
}