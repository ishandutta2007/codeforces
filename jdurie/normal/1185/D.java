//package cf568d2;
import java.util.*;
public class D {
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        Integer[]a=new Integer[n];
        HashMap<Integer,Integer>rlkup=new HashMap<Integer,Integer>();
        for(int i=0;i<n;i++) {
            a[i] = sc.nextInt();
            rlkup.put(a[i],i+1);
        }
        Arrays.sort(a);
        HashMap<Integer,Integer>dels=new HashMap<Integer,Integer>();
        for(int i=1;i<n;i++){
            int d=a[i]-a[i-1];
            dels.put(d,dels.containsKey(d)?dels.get(d)+1:1);
        }
        int delta=-1;
        int ct=0;
        for(int d:dels.keySet())
            if(dels.get(d)>ct||(dels.get(d)==ct&&d>delta)){
                delta=d;
                ct=dels.get(d);
            }
        if(ct==n-1)
            System.out.println(rlkup.get(a[0]));
        else if(ct==n-2){
            if(a[1]-a[0]!=delta)
                System.out.println(rlkup.get(a[0]));
            else if(a[n-1]-a[n-2]!=delta)
                System.out.println(rlkup.get(a[n-1]));
            else if(delta!=0&&dels.containsKey(0)){
                int i=1;
                while(a[i]!=a[i-1])
                    i++;
                System.out.println(rlkup.get(a[i]));
            }else
                System.out.println(-1);
        }else if(ct==n-3&&(delta==0||!dels.containsKey(0))){
            int i=1;
            while(a[i]-a[i-1]==delta)
                i++;
            if(a[i+1]-a[i-1]==delta)
                System.out.println(rlkup.get(a[i]));
            else
                System.out.println(-1);
        }else
            System.out.println(-1);
    }
}